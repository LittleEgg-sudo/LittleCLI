//
// Created by littleegg on 3/28/2025.
//

#include "inputhandler.hpp"

std::string input::read_input() {
    console::current_input.clear();
    char ch;

    while (true) {
        ch = _getch();

        if (ch == '\r') {
            std::cout << std::endl;
            return console::current_input;
        } else if (ch == '\b') {
            if (!console::current_input.empty()) {
                console::current_input.pop_back();
                std::cout << "\b \b";
            }
        } else if (ch == -32) {
            ch = _getch();

            if (ch == 72) {
                if (command::history_index < (int)command::command_history.size() - 1) {
                    command::history_index++;
                    console::current_input = command::command_history[command::command_history.size() - 1 - command::history_index];
                    console::clear_input_line();
                    std::cout << ">> " << console::current_input;
                }
            } else if (ch == 80) {
                if (command::history_index > 0) {
                    command::history_index--;
                    console::current_input = command::command_history[command::command_history.size() - 1 - command::history_index];
                } else {
                    command::history_index = -1;
                    console::current_input.clear();
                }
                console::clear_input_line();
                std::cout << ">> " << console::current_input;
            }
        } else if (isprint(ch)) {  // Printable characters
            console::current_input += ch;
            std::cout << ch;
        }
    }
}