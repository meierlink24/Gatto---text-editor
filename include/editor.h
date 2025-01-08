// editor.h
#ifndef EDITOR_H
#define EDITOR_H

#include <string>
#include <vector>
#include <iostream>
#include <regex>

/**
 * TextEditor class provides basic text editing capabilities,
 * including cursor navigation, syntax highlighting, and undo functionality.
 */
class TextEditor {
public:
    TextEditor();  // Constructor
    void run();    // Main execution loop

private:
    void display();                            // Render the text editor interface
    void handleInput(char input);              // Handle user input
    void saveToFile(const std::string& filename); // Save content to a file
    void undoLastAction();                     // Undo the last action
    void search(const std::string& query);     // Search for a string
    void highlightSyntax(const std::string& line); // Highlight syntax for a line

    void showCursor();                         // Show cursor on terminal
    void hideCursor();                         // Hide cursor on terminal

    std::vector<std::string> lines;           // Stores the lines of text
    size_t cursorX, cursorY;                  // Cursor coordinates
    bool isInsertMode;                        // Tracks if editor is in insert mode
    std::vector<std::pair<char, std::string>> actionHistory; // History for undo functionality
};

#endif // EDITOR_H
