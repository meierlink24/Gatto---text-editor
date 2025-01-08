# Gatto Text Editor

![Gatto Logo](/assets/pics/Gatto.png)

Gatto is a lightweight and simple text editor written in C++ designed for basic editing tasks with a focus on usability and simplicity. This editor is ideal for learning and quick text manipulation in a terminal environment.

## Features
- **Insert and Escape Modes**: Seamlessly toggle between editing and navigation modes.
- **Undo**: Undo your last action with the `u` key.
- **Search**: Search for a specific string using the `/` key.
- **Save to File**: Save the current document with `Ctrl + S`.
- **Syntax Highlighting**: Basic syntax highlighting for C++ keywords.
- **Line Numbers**: Display line numbers for easy navigation.

## Installation
### Prerequisites
- A C++17-compatible compiler (e.g., `g++`)
- GNU Make

### Steps
1. Clone the repository:
   ```bash
   git clone <repository-url>
   cd gatto
   ```
2. Compile the project:
   ```bash
   make
   ```
3. Run the editor:
   ```bash
   ./text_editor
   ```

## Usage
- Navigate between lines and characters using `w`, `s`, `a`, `d`.
- Enter **Insert Mode** with the `i` key to type text.
- Exit **Insert Mode** with the `ESC` key.
- Delete a character with the `x` key.
- Save your work with `Ctrl + S`.
- Undo your last action with the `u` key.
- Search for a term using `/` and enter the query.
- Exit the editor with the `q` key.

## Project Structure
```
project/
├── include/        # Header files
│   ├── editor.h
├── src/            # Source files
│   ├── main.cpp
│   ├── editor.cpp
├── Makefile        # Build system
├── README.md       # Project documentation
```

## Screenshot
![Gatto Screenshot](/assets/pics/gatto.png)

## Contributions
Contributions are welcome! Feel free to fork the repository and submit a pull request with your improvements.

## License
This project is licensed under the MIT License. See the `LICENSE` file for details.

## Acknowledgments
Special thanks to everyone who contributed to the development and testing of Gatto.

