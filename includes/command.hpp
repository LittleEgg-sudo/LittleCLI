//
// Created by littleegg on 3/28/2025.
//

#ifndef LITTLECLI_COMMAND_HPP
#define LITTLECLI_COMMAND_HPP

#include "console.hpp"
#include <unordered_map>
#include <sstream>

namespace command {
    inline std::unordered_map<std::string, void(*)(std::vector<std::string>)> commands;
    inline std::deque<std::string> command_history;
    inline int history_index = -1;

    void handle_input(std::string input);
    void register_command(std::string command, void(*function)(std::vector<std::string>));
};


#endif //LITTLECLI_COMMAND_HPP
