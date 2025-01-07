#include "text_buffer.h"

TextBuffer::TextBuffer() : buffer("") {}

void TextBuffer::append(char c) {
    buffer += c;
}

std::string TextBuffer::getText() const {
    return buffer;
}