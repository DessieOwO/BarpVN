#include <iostream>
#include <ctime>
#include <string>
#include <fstream>
#include <cstdlib>

namespace Color {
    constexpr const char* RESET = "\033[0m";
    constexpr const char* GREY    = "\033[90m";
    constexpr const char* YELLOW  = "\033[33m";
    constexpr const char* RED     = "\033[31m";
    constexpr const char* BOLD_RED = "\033[1;31m";
}

class Logger {
    private:
        std::ofstream LogFile;

        std::string timestamp() {
            std::time_t now = std::time(nullptr);
            std::string ts = std::asctime(std::localtime(&now));
            ts.erase(ts.length() - 1);
            return "[" + ts + "]";
        }

        void output(const std::string& message, const std::string& color = Color::RESET) {
            //TODO: In release versions, add a config to surpress debug messages
            std::clog << color << timestamp() << message << Color::RESET << std::endl;
            LogFile << timestamp() << message << std::endl;
        }
        void urgentOutput(const std::string& message, const std::string& color = Color::RESET) {
            std::cerr << color << timestamp() << message << Color::RESET << std::endl;
            LogFile << timestamp() << message << std::endl;
        }

    public:
        Logger() {
            LogFile.open("BarpVN_session.log");
            if (!LogFile.is_open()) {
                fatal("Failed to open log file!");
                std::exit(EXIT_FAILURE);
            }
        }
        void info(const std::string& message) {
            output(" - INFO: " + message);
        }
        void warn(const std::string& message) {
            output(" - WARN: " + message, Color::YELLOW);
        }
        void error(const std::string& message) {
            urgentOutput(" - ERROR: " + message, Color::RED);
        }
        void debug(const std::string& message) {
            output(" - DEBUG: " + message, Color::GREY);
        }
        void fatal(const std::string& message) {
            urgentOutput(" - FATAL: " + message, Color::BOLD_RED);
        }
};