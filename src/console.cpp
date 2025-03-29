//
// Created by littleegg on 3/28/2025.
//

#include "console.hpp"

void console::get_console_size() {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if (GetConsoleScreenBufferInfo(console_handle, &csbi)) {
        console_height = csbi.srWindow.Bottom - csbi.srWindow.Top - 2;
    }
}

void console::clear_log_area() {
    COORD cursorPos = {0, 0};
    DWORD written;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(console_handle, &csbi);
    int logAreaSize = csbi.dwSize.X * console_height;

    FillConsoleOutputCharacterA(console_handle, ' ', logAreaSize, cursorPos, &written);
    FillConsoleOutputAttribute(console_handle, csbi.wAttributes, logAreaSize, cursorPos, &written);
}

void console::print_log() {
    get_console_size();
    clear_log_area();

    COORD cursorPos = {0, 0};
    SetConsoleCursorPosition(console_handle, cursorPos);

    for (const auto& log : log_buffer) {
        std::cout << log << std::endl;
    }

    cursorPos.Y = console_height;
    cursorPos.X = 2;
    SetConsoleCursorPosition(console_handle, cursorPos);
    std::cout << current_input;
}

void console::add_log(const std::string& message) {
    if (log_buffer.size() >= console_height - 1)
        log_buffer.pop_front();
    log_buffer.push_back(message);
}

void console::clear_input_line() {
    COORD cursorPos;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(console_handle, &csbi);
    cursorPos.X = 0;
    cursorPos.Y = console_height;

    SetConsoleCursorPosition(console_handle, cursorPos);
    std::cout << std::string(csbi.dwSize.X, ' ');  // Overwrite input line

    cursorPos.X = 2;
    SetConsoleCursorPosition(console_handle, cursorPos);
}