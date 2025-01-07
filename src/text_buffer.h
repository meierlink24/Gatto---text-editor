#ifndef TEXT_BUFFER_H
#define TEXT_BUFFER_H

#include <string>

class TextBuffer {
public:
    TextBuffer();
    void append(char c);
    std::string getText() const;

private:
    std::string buffer;
};

#endif // TEXT_BUFFER_H