// main.cpp
#include "editor.h"

/**
 * Entry point of the application.
 * Initializes the TextEditor and starts its main loop.
 */
int main() {
    TextEditor editor;
    try {
        editor.run();
    } catch (const std::exception& e) {
        std::cerr << "An error occurred: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}