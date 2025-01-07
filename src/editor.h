
#ifndef EDITOR_H
#define EDITOR_H

#include <string>
#include "text_buffer.h"

class Editor {
public:
    Editor();
    void run();

private:
    TextBuffer textBuffer;
    bool insertMode;

    void handleInput(char input);
    void insertText();
    char getch(); // Declare getch as a member function
};

#endif // EDITOR_H