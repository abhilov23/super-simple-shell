# Super Simple Shell

## Overview
Super Simple Shell is a custom Unix-like shell implemented in C. It provides a basic command-line interface to interact with the underlying operating system by executing commands, supporting standard features like argument handling, built-in commands, and error reporting.

## Features
- **Command Execution:** Executes system commands using the `execvp` system call.
- **Built-in Commands:** Supports internal commands like `cd` (change directory) and `exit` to terminate the shell.
- **Custom Prompt:** Displays a prompt indicating the current working directory for better context.
- **Error Handling:** Provides user-friendly error messages for invalid commands and system call failures.
- **Basic Input Parsing:** Handles input commands and arguments efficiently.

## Installation

To clone and build the project:

1. Clone the repository:
   ```bash
   git clone https://github.com/abhilov23/super-simple-shell.git
   cd super-simple-shell
   ```

2. Compile the shell:
   ```bash
   gcc -o super_simple_shell.exe cell.c utils.c -I .
   ```

3. Run the shell:
   ```bash
   ./super_simple_shell.exe
   ```

## Usage

1. Start the shell by running:
   ```bash
   ./super_simple_shell.exe
   ```

2. Execute commands as you would in a typical Unix shell. Examples:
   ```bash
   ls -l
   cd /path/to/directory
   echo "Hello, World!"
   ```

3. Use the `exit` command to terminate the shell:
   ```bash
   exit
   ```

### Built-in Commands

- **`cd`**: Changes the current working directory.
  ```bash
  cd [directory]
  ```

- **`exit`**: Exits the shell program.
  ```bash
  exit
  ```

## Code Structure

- **cell.c**: Contains the main function, handles user input, and manages the shell loop.
- **utils.c**: Implements helper functions for command parsing, execution, and built-in commands like `cd` and `exit`.
- **cell.h**: Declares shared functions and constants used across the project.

## Error Handling

The shell provides detailed error messages for situations such as:
- Invalid or unknown commands.
- System call failures.
- Incorrect usage of built-in commands.

## Limitations

- Advanced features like piping (`|`), I/O redirection (`<`, `>`), and background execution (`&`) are not currently supported.
- Input parsing is basic and may not handle all edge cases.

## Future Enhancements

- Add support for pipelines (`|`) and background tasks (`&`).
- Improve input parsing to handle more complex command structures.
- Enhance I/O redirection functionality.
- Implement command history and tab-completion features.

## License

This project is open-source and available under the MIT License. Feel free to use, modify, and distribute it.

## Contribution

Contributions are welcome! To contribute:
1. Fork the repository.
2. Create a new branch for your feature or bug fix.
3. Commit your changes with clear and concise messages.
4. Submit a pull request detailing your changes.

---

### Author

- **Abhilov**

For more information, suggestions, or feedback, feel free to reach out via GitHub. Happy coding!

