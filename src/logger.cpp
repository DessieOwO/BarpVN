#include "logger.hpp"

std::string Logger::timestamp() {
    std::time_t now = std::time(nullptr);
    std::string ts = std::asctime(std::localtime(&now));
    ts.erase(ts.length() - 1);
    return "[" + ts + "]";
}

void Logger::output(const std::string& message, const std::string& color) {
    std::clog << color << timestamp() << message << Color::RESET << std::endl;
    LogFile << timestamp() << message << std::endl;
}

void Logger::urgentOutput(const std::string& message, const std::string& color) {
    std::cerr << color << timestamp() << message << Color::RESET << std::endl;
    LogFile << timestamp() << message << std::endl;
}

Logger::Logger() {
    LogFile.open("BarpVN_session.log");
    if (!LogFile.is_open()) {
        fatal("Failed to open log file!");
        std::exit(EXIT_FAILURE);
    }
}

void Logger::info(const std::string& message) {
    output(" - INFO: " + message);
}

void Logger::warn(const std::string& message) {
    output(" - WARN: " + message, Color::YELLOW);
}

void Logger::error(const std::string& message) {
    urgentOutput(" - ERROR: " + message, Color::RED);
}

void Logger::debug(const std::string& message) {
    output(" - DEBUG: " + message, Color::GREY);
}

void Logger::fatal(const std::string& message) {
    urgentOutput(" - FATAL: " + message, Color::BOLD_RED);
}