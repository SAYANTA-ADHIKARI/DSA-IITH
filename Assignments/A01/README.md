# Maze Solver Program Documentation

This documentation explains the functions and their functionality in the provided C program that solves a maze.

## Table of Contents

1. [File Input Functions](#file-input-functions)
   - `file_lines`: Counts the number of lines in a file.
   - `file_char_line`: Counts the number of characters in the first line of a file.
2. [Maze Manipulation Functions](#maze-manipulation-functions)
   - `read_maze`: Reads the maze from a file and stores it in a 2D array.
   - `print_maze`: Prints the maze to the console.
   - `find_start`: Locates the start ('S') position in the maze.
   - `find_end`: Locates the end ('E') position in the maze.
   - `manhattan_distance`: Computes the Manhattan distance between two points.
   - `valid_point`: Checks if a point is within the bounds of the maze.
3. [Maze Solving Function](#maze-solving-function)
   - `solve_maze`: Uses BFS to solve the maze and mark the path with dots ('.').
4. [File Output Function](#file-output-function)
   - `write_maze`: Writes the solved maze to another file.
5. [Deque Data Structure](#deque-data-structure)
   - `print_point`: Prints a point (x, y) to the console.
   - `make_deque`: Creates a deque data structure with a specified capacity and head index.
   - `add_first`: Adds a point to the front of the deque.
   - `add_last`: Adds a point to the end of the deque.
   - `remove_first`: Removes the point from the front of the deque.
   - `remove_last`: Removes the point from the end of the deque.
   - `is_empty`: Checks if the deque is empty.
6. [Maze Solver Program Execution Guide](#maze-solver-program-execution-guide)

## File Input Functions

### `file_lines(FILE *f)`

- **Description**: Counts the number of lines in a file.
- **Parameters**:
  - `f`: A pointer to the input file.
- **Returns**: The number of lines in the file.

### `file_char_line(FILE *f)`

- **Description**: Counts the number of characters in the first line of a file.
- **Parameters**:
  - `f`: A pointer to the input file.
- **Returns**: The number of characters in the first line of the file.

## Maze Manipulation Functions

### `read_maze(FILE *f, int rows, int cols)`

- **Description**: Reads the maze from a file and stores it in a 2D array.
- **Parameters**:
  - `f`: A pointer to the input file.
  - `rows`: The number of rows in the maze.
  - `cols`: The number of columns in the maze.
- **Returns**: A 2D array (maze) containing the maze layout.

### `print_maze(char **maze, int rows, int cols)`

- **Description**: Prints the maze to the console.
- **Parameters**:
  - `maze`: A 2D array representing the maze.
  - `rows`: The number of rows in the maze.
  - `cols`: The number of columns in the maze.

### `find_start(char **maze, int rows, int cols)`

- **Description**: Locates the start ('S') position in the maze.
- **Parameters**:
  - `maze`: A 2D array representing the maze.
  - `rows`: The number of rows in the maze.
  - `cols`: The number of columns in the maze.
- **Returns**: A `point` structure representing the start position.

### `find_end(char **maze, int rows, int cols)`

- **Description**: Locates the end ('E') position in the maze.
- **Parameters**:
  - `maze`: A 2D array representing the maze.
  - `rows`: The number of rows in the maze.
  - `cols`: The number of columns in the maze.
- **Returns**: A `point` structure representing the end position.

### `manhattan_distance(point p1, point p2)`

- **Description**: Computes the Manhattan Distance between two points.
- **Parameters**:
  - `p1`: The first point.
  - `p2`: The second point.
- **Returns**: The Manhattan distance between the two points.

### `valid_point(point p, int rows, int cols)`

- **Description**: Checks if a point is within the bounds of the maze.
- **Parameters**:
  - `p`: The point to be checked.
  - `rows`: The number of rows in the maze.
  - `cols`: The number of columns in the maze.
- **Returns**: `true` if the point is valid (within bounds), otherwise `false`.

## Maze Solving Function

### `solve_maze(char **maze, int rows, int cols, point start, point end)`

- **Description**: Uses BFS to solve the maze and mark the path with dots ('.').
- **Parameters**:
  - `maze`: A 2D array representing the maze.
  - `rows`: The number of rows in the maze.
  - `cols`: The number of columns in the maze.
  - `start`: The start position.
  - `end`: The end position.
- **Returns**: The solved maze as a 2D array.

## File Output Function

### `write_maze(FILE *f, char **maze, int rows, int cols)`

- **Description**: Writes the solved maze to another file.
- **Parameters**:
  - `f`: A pointer to the output file.
  - `maze`: A 2D array representing the solved maze.
  - `rows`: The number of rows in the maze.
  - `cols`: The number of columns in the maze.

## Deque Data Structure

This section describes the functions related to the deque data structure used in the program.

### `print_point(point p)`

- **Description**: Prints a point (x, y) to the console.
- **Parameters**:
  - `p`: The point to be printed.

### `make_deque(int capacity, int head_idx)`

- **Description**: Creates a deque data structure with a specified capacity and head index.
- **Parameters**:
  - `capacity`: The maximum capacity of the deque.
  - `head_idx`: The initial head index.
- **Returns**: A pointer to the created deque.

### `add_first(point p, Deque *d)`

- **Description**: Adds a point to the front of the deque.
- **Parameters**:
  - `p`: The point to be added.
  - `d`: A pointer to the deque.

### `add_last(point p, Deque *d)`

- **Description**: Adds a point to the end of the deque.
- **Parameters**:
  - `p`: The point to be added.
  - `d`: A pointer to the deque.

### `remove_first(Deque *d, bool verbose)`

- **Description**: Removes the point from the front of the deque.
- **Parameters**:
 `d`: A pointer to the deque.
  - `verbose`: If `true`, provides verbose output.
  
### `remove_last(Deque *d, bool verbose)`

- **Description**: Removes the point from the end of the deque.
- **Parameters**:
  - `d`: A pointer to the deque.
  - `verbose`: If `true`, provides verbose output.

### `is_empty(Deque *d)`

- **Description**: Checks if the deque is empty.
- **Parameters**:
  - `d`: A pointer to the deque.
- **Returns**: `true` if the deque is empty, otherwise `false`.

This documentation provides a detailed explanation of the functions and data structures used in the maze solver program. It should help users understand the program's structure and functionality.

## Maze Solver Program Execution Guide

### Prerequisites

Before running the code, ensure you have the following prerequisites installed:

- A C compiler (e.g., GCC)
- A terminal or command prompt

### Instructions

1. **Compile the Code**

   Open your terminal or command prompt and navigate to the directory where you have saved the C code file (e.g., `maze_solver.c`). To compile the code, use the `gcc` command:

   ```bash
   gcc maze_solver.c -o maze_solver.out
   ```

   This command will compile the code and generate an executable file named `maze_solver.out`.

2. **Run the Program**

   After successful compilation, you can run the program using the following command:

   ```bash
   ./maze_solver
   ```

   This will execute the maze solver program. It will prompt you for the input file name, which should contain the maze you want to solve. Enter the file name and press Enter.

3. **View the Output**

   The program will process the maze, solve it, and display the result in the terminal. If the maze is solvable, it will print **"Maze Solved!!!"** along with the solved maze. If it's unsolvable, it will print **"Maze Not Solved!!!"**.

4. **Write the Solved Maze to a File (Optional)**

   After solving the maze, the program will ask you to enter the name of the file where you want to save the solved maze. Enter the desired output file name and press Enter. The solved maze will be saved in the specified file.

5. **Exit the Program**

   Once you have viewed the results and saved the solved maze (if desired), you can exit the program by closing the terminal or pressing `Ctrl+C`.

### Example Usage

Here's an example of how you can execute the code:

1. Compile the code:

   ```bash
   gcc maze_solver.c -o maze_solver
   ```

2. Run the program:

   ```bash
   ./maze_solver
   ```

3. Follow the prompts to provide the input file name and output file name (if you want to save the solved maze). Below provided the full terminal output that you will see.

    ```bash
    Enter the file name: maze1.txt
    Printing Maze: --------->

    ##########
    #  S     #
    # ### ## #
    # #    # #
    # #  # # #
    # ## #####
    # #      #
    # # #  # #
    ##### ####
    #   #    #
    # #    #E#
    ##########

    Searching for path....
    Maze Solved!!!
    Printing Maze: --------->

    ##########
    # .S.....#
    # ###.##.#
    # # ...#.#
    # # .#.#.#
    # ##.#####
    # # .....#
    # # #..#.#
    #####.####
    #   #....#
    # #    #E#
    ##########
    Enter the file name where u want to write: maze1out.txt
     Output Maze is saved in maze1out.txt
    ```
4. View the results in the terminal. The Output solved maze is also present in the output file `maze1out.txt`.

5. Exit the program when you're done.

That's it! You've successfully executed the maze solver program from the command line.

