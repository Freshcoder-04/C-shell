# Instructions

In your shell run the following command to compile all the source files:

```bash
$ make
```

Then run the following command to execute the program:

```bash
$ ./shell
```

If you wish to change the name of the final executable from ```shell``` to ```executable``` look for ``` line 5 ``` in the ``` Makefile ``` and replace ``` shell ``` with ```executable``` of your choice.


# Shell manual

## Overview
This custom shell program allows users to interact with the file system and perform basic tasks such as changing directories, printing the current working directory, displaying history, and echoing text. It also includes a command history mechanism that stores the user's last 20 commands and persists across sessions.

## Commands

### 1. `cd` (Change Directory)
- **Usage**: `cd <directory>`
- **Description**: This command changes the current working directory to the target directory specified.
- **Examples**:
  - `cd dir1`: Changes to the specified absolute path.
  - `cd dir1/dir11`: Changes to the specified absolute path.
  - `cd ~`: Moves to the user's home directory.
  - `cd ..`: Navigates to the parent directory.
  - `cd -`: Switches back to the previous working directory.

### 2. `pwd` (Print Working Directory)
- **Usage**: `pwd`
- **Description**: Prints the current working directory path.
- **Examples**:
  - Simply running `pwd` will output the full path of the directory you are currently in.

### 3. `echo`
- **Usage**: `echo <string>`
- **Description**: This command outputs the string provided as an argument.
- **Special handling**: If a string is enclosed in double quotes, the quotes will be printed as well.
- **Examples**:
  - `echo Hello`: Outputs `Hello` to the terminal.
  - `echo "This is quoted."`: Outputs `"This is quoted."`.

### 4. `history`
- **Usage**: `history`
- **Description**: Displays the last 10 commands entered by the user, out of a total of 20 commands stored in history.
- **Examples**:
  - Running `history` will print the last 10 commands from the user's session or previous sessions if the history was saved.

### 5. `exit`
- **Usage**: `exit`
- **Description**: Exits the custom shell.
- **Examples**:
  - Typing `exit` will close the shell.