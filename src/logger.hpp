#pragma once
#include <iostream>
#include <ctime>
#include <string>
#include <fstream>
#include <cstdlib>

namespace Color {
    constexpr const char* RESET    = "\033[0m";
    constexpr const char* GREY     = "\033[90m";
    constexpr const char* YELLOW   = "\033[33m";
    constexpr const char* RED      = "\033[31m";
    constexpr const char* BOLD_RED = "\033[1;31m";
}

class Logger {
private:
    std::ofstream LogFile;
    std::string timestamp();
    void output(const std::string& message, const std::string& color = Color::RESET);
    void urgentOutput(const std::string& message, const std::string& color = Color::RESET);
public:
    Logger();
    void info(const std::string& message);
    void warn(const std::string& message);
    void error(const std::string& message);
    void debug(const std::string& message);
    void fatal(const std::string& message);
};