#pragma once

#include <string>

namespace tColor {
    const std::string RED = "\033[31m";
    const std::string GREEN = "\033[32m";
    const std::string YELLOW = "\033[33m";
    const std::string BLUE = "\033[34m";
    const std::string ENDC = "\033[0m";

    std::string print_c(const std::string& t_str, const std::string &color) 
    {
        return color + t_str + ENDC; 
    }
}
