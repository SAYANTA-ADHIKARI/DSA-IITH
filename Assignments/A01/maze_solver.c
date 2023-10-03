#include <stdio.h>
#include <stdlib.h>
#include "deque.c"

int file_lines(FILE *f)
{
    int count = 0;
    char ch;
    while ((ch = fgetc(f)) != EOF)
    {
        if (ch == '\n')
        {
            count++;
        }
    }
    // The last line may not end with a newline character
    if (count > 0)
    {
        count++;
    }
    return count;
}
int file_char_line(FILE *f)
{
    char line[100];
    int count = 0;
    if (fgets(line, sizeof(line), f) != NULL)
    {
        for (int i = 0; line[i] != '\n'; i++)
        {
            count++;
        }
    }
    return count;
}

char **read_maze(FILE *f, int rows, int cols)
{
    char **maze = (char **)calloc(rows * 2, sizeof(char *));
    for (int i = 0; i < rows; i++)
    {
        maze[i] = (char *)calloc(cols * 2, sizeof(char));
        if (maze[i] == NULL)
        {
            printf("Memory allocation failed.\n");
        }
    }
    fseek(f, 0, SEEK_SET);
    char ch = getc(f);
    int c_cnt = 0, r_cnt = 0;
    while (ch != EOF)
    {
        if (ch == '\n')
        {
            r_cnt++;
            c_cnt = 0;
        }
        else
        {
            if (ch == '#' || ch == 'S' || ch == 'E' || ch == ' ')
            {
                maze[r_cnt][c_cnt] = ch;
                c_cnt++;
            }
            else
            {
                printf("Wrong Input!!!\n");
                exit(0);
            }
        }
        ch = getc(f);
    }
    fseek(f, 0, SEEK_SET);
    return maze;
}
void print_maze(char **maze, int rows, int cols)
{
    printf("Printing Maze: --------->\n");
    for (int i = 0; i < rows; i++)
    {
        printf("\n");
        for (int j = 0; j < cols; j++)
        {
            printf("%c", maze[i][j]);
        }
    }
    printf("\n");
}

point find_start(char **maze, int rows, int cols)
{
    point p;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (maze[i][j] == 'S')
            {
                p.x = i;
                p.y = j;
                break;
            }
        }
    }
    return p;
}
point find_end(char **maze, int rows, int cols)
{
    point p;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (maze[i][j] == 'E')
            {
                p.x = i;
                p.y = j;
                break;
            }
        }
    }
    return p;
}

int manhattan_distance(point p1, point p2)
{
    return abs(p1.x - p2.x) + abs(p1.y - p2.y);
}
bool valid_point(point p, int rows, int cols)
{
    if (p.x < rows && p.x >= 0)
    {
        if (p.y < cols && p.y >= 0)
        {
            return true;
        }
        else
            return false;
    }
    else
        return false;
}

char **solve_maze(char **maze, int rows, int cols, point start, point end)
{
    Deque *not_visited = make_deque(rows * cols, rows);
    bool solved = false;
    add_first(start, not_visited);
    while (is_empty(not_visited) == false)
    {
        point curr = not_visited->arr[not_visited->head];
        remove_first(not_visited, false);
        if (maze[curr.x][curr.y] == 'E')
        {
            solved = true;
            break;
        }
        else if (maze[curr.x][curr.y] == '.' || maze[curr.x][curr.y] == '#')
            continue;
        else
        {
            // Marking Point as Visited
            if (maze[curr.x][curr.y] == ' ')
                maze[curr.x][curr.y] = '.';

            // Adding its neighbours
            point temp;
            int d0, d;
            d0 = manhattan_distance(curr, end);
            // Neighbour 1
            temp.x = curr.x + 1;
            temp.y = curr.y;
            if (valid_point(temp, rows, cols) == true)
            {
                d = manhattan_distance(temp, end);
                if (d <= d0)
                    add_first(temp, not_visited);
                else
                    add_last(temp, not_visited);
            }

            // Neighbour 2
            temp.x = curr.x - 1;
            temp.y = curr.y;
            if (valid_point(temp, rows, cols) == true)
            {
                d = manhattan_distance(temp, end);
                if (d <= d0)
                    add_first(temp, not_visited);
                else
                    add_last(temp, not_visited);
            }

            // Neighbour 3
            temp.x = curr.x;
            temp.y = curr.y - 1;
            if (valid_point(temp, rows, cols) == true)
            {
                d = manhattan_distance(temp, end);
                if (d <= d0)
                    add_first(temp, not_visited);
                else
                    add_last(temp, not_visited);
            }

            // Neighbour 4
            temp.x = curr.x;
            temp.y = curr.y + 1;
            if (valid_point(temp, rows, cols) == true)
            {
                d = manhattan_distance(temp, end);
                if (d <= d0)
                    add_first(temp, not_visited);
                else
                    add_last(temp, not_visited);
            }
        }
    }
    if (solved == true)
        printf("Maze Solved!!!\n");
    else
        printf("Maze Not Solved!!!\n");
    return maze;
}
bool write_maze(FILE *f, char **maze, int rows, int cols)
{
    char ch;
    bool complete = true;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            ch = fputc(maze[i][j], f);
            if (ch == EOF)
            {
                complete = false;
                break;
            }
        }
        ch = fputc('\n', f);
        if (ch == EOF)
        {
            complete = false;
            break;
        }
    }
    return complete;
}

int main()
{
    char filename[100], out_filename[100];
    // Geting Maze file name
    printf("Enter the file name: ");
    scanf("%s", filename);
    FILE *f = fopen(filename, "r");

    // Getting the number of rows and columns in the maze
    int cols = file_char_line(f);
    fseek(f, 0, SEEK_SET);
    int rows = file_lines(f);

    // Reading the maze
    char **maze = read_maze(f, rows, cols);
    print_maze(maze, rows, cols);
    printf("\n Searching for path....\n");

    // Finding start and end points in the maze
    point start = find_start(maze, rows, cols);
    point end = find_end(maze, rows, cols);

    // Solving the maze
    maze = solve_maze(maze, rows, cols, start, end);
    print_maze(maze, rows, cols);

    // Getting the output filename
    printf("Enter the file name where u want to write: ");
    scanf("%s", out_filename);
    FILE *f2 = fopen(out_filename, "w");

    // Writing the solved maze in output file
    bool c = write_maze(f2, maze, rows, cols);
    if (c == true)
        printf(" Output Maze is saved in %s", out_filename);
    else
        printf("Error in writing the file in %s", out_filename);
    fclose(f);
    fclose(f2);
}