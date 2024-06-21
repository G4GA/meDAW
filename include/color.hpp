#pragma once

#include <string>

namespace tColor {
    const std::string RED = "\033[31m";
    const std::string GREEN = "\033[32m";
    const std::string YELLOW = "\033[33m";
    const std::string BLUE = "\033[34m";
    const std::string ENDC = "\033[0m";
    const std::string BOLD = "\033[1m";

    std::string color_o(const std::string& t_str, const std::string &color) 
    {
        return color + t_str + ENDC; 
    }

   std::string printResult(bool assertion, const std::string &message)
   {
        std::string n_message = "=> Test [" + color_o(message, BOLD) + "] ";

        return assertion ? n_message + color_o("OK", GREEN) + "\n":
                       n_message + color_o("Failed", RED) + "\n";
   }
}
