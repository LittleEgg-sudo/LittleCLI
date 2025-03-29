//
// Created by littleegg on 3/28/2025.
//

#ifndef LITTLECLI_CONSOLE_HPP
#define LITTLECLI_CONSOLE_HPP

#include <iostream>
#include <string>
#include <deque>
#include <windows.h>

namespace console {
    inline HANDLE console_handle = GetStdHandle(STD_OUTPUT_HANDLE);
    inline int console_height = 20;
    inline std::deque<std::string> log_buffer;
    inline std::string current_input = "";

    void get_console_size();
    void clear_log_area();
    void print_log();
    void add_log(const std::string& message);
    void clear_input_line();
}


#endif //LITTLECLI_CONSOLE_HPP
