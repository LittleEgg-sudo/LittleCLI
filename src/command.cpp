//
// Created by littleegg on 3/28/2025.
//

#include "command.hpp"

void command::handle_input(std::string input) {
    std::istringstream stream(input);
    std::vector<std::string> tokens;
    std::string token;

    while (getline(stream, token, ' ')) {
        tokens.push_back(token);
    }

    if (!tokens.size())
        return;

    if (commands.find(tokens[0]) != commands.end()) {
        std::vector<std::string> params(tokens.begin() + 1, tokens.end());
        commands[tokens[0]](params);
    }
    else
        console::add_log("invalid command");
}

void command::register_command(std::string command, void(*function)(std::vector<std::string>)) {
    commands[command] = function;
}