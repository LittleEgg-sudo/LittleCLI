#include "inputhandler.hpp"

void testprint(std::vector<std::string> params) {
    if(params.size() != 1) {
        console::add_log("not correct command usage!");
        return;
    }

    console::add_log("working! param1: " + params[0]);
}

int main() {
    std::string input;
    console::clear_log_area();

    command::register_command("testprint", testprint);
    command::register_command("exit", [](std::vector<std::string> params){ exit(1); });

    while (true) {
        console::print_log();
        std::cout << ">> ";
        input = input::read_input();

        command::handle_input(input);

        console::clear_input_line();

        if (!input.empty() && (command::command_history.empty() || command::command_history.back() != input))
            command::command_history.push_back(input);

        command::history_index = -1;

        console::current_input.clear();
    }

    return 0;
}
