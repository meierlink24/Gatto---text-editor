#include "editor.h"
#include <iostream>
#include <unistd.h>
#include <termios.h>

Editor::Editor() : insertMode(false) {}

void Editor::run() {
    std::cout << "Welcome to Gatto! Press 'I' to enter insert mode." << std::endl;

    while (true) {
        char input = getch(); // Use the member function
        handleInput(input);
    }
}

void Editor::handleInput(char input) {
    if (input == 'I') {
        insertMode = true;
        std::cout << "\nInsert mode. Type your text (Press 'Esc' to exit):" << std::endl;
        insertText();
    } else if (input == 'q') {
        std::cout << "Exiting Gatto." << std::endl;
        exit(0);
    }
}

void Editor::insertText() {
    while (insertMode) {
        char charInput = getch(); // Use the member function
        if (charInput == 27) { // Escape key
            insertMode = false;
            std::cout << "\nExited insert mode." << std::endl;
        } else {
            textBuffer.append(charInput);
            std::cout << charInput; // Echo the character
        }
    }
}

// Member function to read a single character from the terminal
char Editor::getch() {
    struct termios oldt, newt;
    char ch;
    tcgetattr(STDIN_FILENO, &oldt); // Get current terminal settings
    newt = oldt; // Copy settings
    newt.c_lflag &= ~(ICANON | ECHO); // Disable canonical mode and echo
    tcsetattr(STDIN_FILENO, TCSANOW, &newt); // Set new settings
    ch = getchar(); // Read a character
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt); // Restore old settings
    return ch; // Return the character
}