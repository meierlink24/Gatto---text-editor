// editor.cpp
#include "editor.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <termios.h>
#include <unistd.h>
#include <algorithm>

// Utility function to get a single character from the keyboard
char getch() {
    struct termios oldt, newt;
    char ch;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO); // Disable canonical mode and echo
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
}

/**
 * Constructor initializes the editor with default settings.
 */
TextEditor::TextEditor() : cursorX(0), cursorY(0), isInsertMode(false) {
    lines.push_back(""); // Start with an empty line
}

/**
 * Show cursor on terminal.
 */
void TextEditor::showCursor() {
    std::cout << "\e[?25h"; // Show the cursor
}

/**
 * Hide cursor on terminal.
 */
void TextEditor::hideCursor() {
    std::cout << "\e[?25l"; // Hide the cursor
}

/**
 * Main loop for the text editor.
 * Handles rendering and user input.
 */
void TextEditor::run() {
    char input;
    hideCursor(); // Hide the cursor at the start
    while (true) {
        display();
        if (isInsertMode) {
            input = getch();
            if (input == 27) { // ESC key
                isInsertMode = false;
                showCursor(); // Show the cursor when exiting insert mode
            } else if (input == 19) { // Ctrl + S
                std::string filename;
                std::cout << "Enter filename to save: ";
                std::cin >> filename;
                saveToFile(filename);
            } else {
                if (cursorY < lines.size() && cursorX <= lines[cursorY].size()) {
                    lines[cursorY].insert(cursorX, 1, input);
                    actionHistory.push_back({'i', std::string(1, input)}); // Record action for undo
                    cursorX++;
                }
            }
        } else {
            input = getch();
            handleInput(input);
            hideCursor(); // Hide the cursor when in escape mode
        }
    }
}

/**
 * Display the text editor interface.
 */
void TextEditor::display() {
    system("clear"); // Clear the terminal
    for (size_t i = 0; i < lines.size(); ++i) {
        highlightSyntax(lines[i]); // Highlight syntax for each line
        std::cout << (i + 1) << ": " << lines[i] << std::endl; // Display line numbers
    }
    std::cout << "\e[" << (cursorY + 1) << ";" << (cursorX + 1) << "H"; // Move cursor to position
    std::cout << "Cursor Position: (" << cursorX << ", " << cursorY << ")" << std::endl;
    std::cout << (isInsertMode ? "[INSERT MODE]" : "[ESC MODE]") << std::endl;
}

/**
 * Handle user input in escape mode.
 */
void TextEditor::handleInput(char input) {
    switch (input) {
        case 'i':
            isInsertMode = true;
            break;
        case 'w':
            if (cursorY > 0) cursorY--;
            break;
        case 's':
            if (cursorY < lines.size() - 1) cursorY++;
            break;
        case 'a':
            if (cursorX > 0) cursorX--;
            break;
        case 'd':
            if (cursorX < lines[cursorY].size()) cursorX++;
            break;
        case 'x':
            if (!lines[cursorY].empty() && cursorX > 0) {
                actionHistory.push_back({'d', lines[cursorY].substr(cursorX - 1, 1)}); // Record deletion for undo
                lines[cursorY].erase(cursorX - 1, 1);
                cursorX--;
            }
            break;
        case 'q':
            exit(0); // Exit the editor
        case 'u': // Undo last action
            undoLastAction();
            break;
        case '/': { // Search functionality
            std::string query;
            std::cout << "Enter search query: ";
            std::cin >> query;
            search(query);
            break;
        }
        default:
            break;
    }
}

/**
 * Save the current content to a file.
 */
void TextEditor::saveToFile(const std::string& filename) {
    if (filename.empty()) {
        std::cerr << "Error: Filename cannot be empty." << std::endl;
        return;
    }
    std::ofstream outFile(filename);
    for (const auto& line : lines) {
        outFile << line << std::endl;
    }
    outFile.close();
    std::cout << "File saved to " << filename << std::endl;
}

/**
 * Undo the last action.
 */
void TextEditor::undoLastAction() {
    if (!actionHistory.empty()) {
        auto lastAction = actionHistory.back();
        actionHistory.pop_back();
        if (lastAction.first == 'i') { // Undo insert
            if (!lines[cursorY].empty() && cursorX > 0) {
                lines[cursorY].erase(cursorX - 1, 1);
                cursorX--;
            }
        } else if (lastAction.first == 'd') { // Undo delete
            if (cursorY < lines.size()) {
                lines[cursorY].insert(cursorX, lastAction.second);
                cursorX++;
            }
        }
    } else {
        std::cout << "No actions to undo." << std::endl;
    }
}

/**
 * Search for a query string and display results.
 */
void TextEditor::search(const std::string& query) {
    std::cout << "Searching for: " << query << std::endl;
    for (size_t i = 0; i < lines.size(); ++i) {
        if (lines[i].find(query) != std::string::npos) {
            std::cout << "Found in line " << (i + 1) << ": " << lines[i] << std::endl;
        }
    }
    std::cout << "Press any key to continue...";
    getch(); // Wait for user input to continue
}

/**
 * Highlight syntax for a given line.
 */
void TextEditor::highlightSyntax(const std::string& line) {
    // Simple syntax highlighting for C++ keywords
    const std::vector<std::string> keywords = {"int", "return", "if", "else", "for", "while", "class", "public", "private", "protected", "void", "include"};
    std::string highlightedLine = line;

    for (const auto& keyword : keywords) {
        size_t pos = 0;
        while ((pos = highlightedLine.find(keyword, pos)) != std::string::npos) {
            std::cout << "\033[1;32m" << keyword << "\033[0m";
            pos += keyword.length();
        }
    }
    std::cout << highlightedLine << std::endl;
}
