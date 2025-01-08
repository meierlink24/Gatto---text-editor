# Proposed Features for Gatto Text Editor

## Text Color Plugins

Introduce a plugin system that allows users to customize text colors for different text elements such as keywords, comments, and strings. This feature will enhance readability and make the editor more visually appealing.

### Details
- **User Customization**: Users can define custom color schemes via a configuration file (e.g., `colors.json` or `config.yaml`).
- **Predefined Themes**:
  - Default (No color changes)
  - Solarized
  - Monokai
- **Implementation**:
  - Parse configuration files to apply colors.
  - Use ANSI escape codes for terminal text coloring.


---

## Dark/Light Mode

Implement dark and light modes for the editor to reduce eye strain and suit different lighting environments.

### Details
- **Modes**:
  - Dark Mode: Dark background with light text.
  - Light Mode: Light background with dark text.
- **Toggle Mechanism**:
  - Use a hotkey (e.g., `Ctrl+D`) to toggle between modes.
  - Save the user's preference in a configuration file.
- **Default Setting**:
  - Default to system theme if detectable, or use light mode.


---

## Plugin System for Additional Features
### 
Design a plugin architecture that allows developers to extend the functionality of Gatto without modifying the core codebase.

### Details
- **Plugin Format**:
  - Plugins will be written in C++ and compiled as shared libraries (`.so` or `.dll`).
  - Dynamically loaded at runtime.
- **Core API**:
  - Expose hooks for features like syntax highlighting, text manipulation, and file handling.
- **Examples**:
  - Spell Checker Plugin
  - Auto-completion Plugin


---

##  Line Highlighting

Highlight the current line where the cursor is located for better focus during text editing.

### Details
- **Highlight Style**:
  - Use ANSI background colors to highlight the line.
- **Customization**:
  - Allow users to configure highlight color and enable/disable this feature.



---

##  Save and Load Sessions

Implement a session management feature to save the editor's state (e.g., open files, cursor position) and restore it on the next startup.

### Details
- **Save State**:
  - Automatically save session data in a JSON file.
  - Include details such as open files, cursor positions, and active plugins.
- **Restore State**:
  - Load the session data during startup.
- **User Control**:
  - Option to disable session management via configuration.



---

## Multi-Cursor Editing

Enable multiple cursors for simultaneous editing in different parts of the file.

### Details
- **Keyboard Shortcuts**:
  - Add new cursors using `Ctrl+Click` or `Alt+Arrow`.
- **Cursor Management**:
  - Support for navigating and editing with all active cursors.
- **Implementation**:
  - Extend the cursor data structure to handle multiple cursors.


---


