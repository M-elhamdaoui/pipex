# Pipex Project Readme

## Program Overview

**Program Name:** pipex

### 1. Makefile rules

- `NAME`: Target executable name
- `all`: Compiles the program
- `clean`: Removes object files
- `fclean`: Removes object files and the executable
- `re`: Rebuilds the project

### 2. Program Execution

```bash
./pipex file1 cmd1 cmd2 file2
```

- **Arguments:**
  - `file1` and `file2`: File names
  - `cmd1` and `cmd2`: Shell commands with parameters

- **Behavior:**
  - Mimics the shell command: `< file1 cmd1 | cmd2 > file2`

### 3. External Functions

- `open`, `close`, `read`, `write`
- `malloc`, `free`, `perror`
- `access`, `dup`, `dup2`
- `execve`, `exit`, `fork`, `pipe`
-  `wait`, `waitpid`,`ft_printf`

### 4. Libft

Libft is a project already coded by me in 42 curses.

### 5. Description

This project focuses on handling pipes. The program executes commands as described in the shell command:

```bash
$> < file1 cmd1 | cmd2 > file2
```

## Examples

1. ```bash
   $> ./pipex infile "ls -l" "wc -l" outfile
   ```
   Should behave like: `< infile ls -l | wc -l > outfile`

2. ```bash
   $> ./pipex infile "grep a1" "wc -w" outfile
   ```
   Should behave like: `< infile grep a1 | wc -w > outfile`

## Requirements

- **Makefile:** Must compile source files without relinking.
- **Error Handling:** Thoroughly handle errors; the program do not quit unexpectedly.
- **Memory Management:** No memory leaks.

# Bonus Part

### Handling Multiple Pipes

```bash
$> ./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2
```

Should behave like:

```bash
< file1 cmd1 | cmd2 | cmd3 ... | cmdn > file2
```

## 2. Supporting "<<" and ">>"

```bash
$> ./pipex here_doc LIMITER cmd cmd1 file
```

Should behave like:

```bash
cmd << LIMITER | cmd1 >> file
```
