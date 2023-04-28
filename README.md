# get_next_line
The get_next_line project challenges us to create a function that reads from a file descriptor and returns the next line, storing the remaining content in a buffer.
The goal is to be able to read a file, a stdin input or any other file descriptor while learning how to create programs that can modify their behaviour with compilation flags.

## Getting Started
To use the get_next_line function, simply clone the repository to your local machine.
The library comes with a Makefile that includes the following rules:

- `all`: compiles the library
- `re`: recompiles the library
- `fclean`: removes all object files and the library
- `clean`: removes all object files

To compile the library, run:

```bash
make all
```
This will generate a `.a` file that you can link to your C projects.

## Using the Function
To use the `get_next_line` function, include the `get_next_line.h` header file in your C source files.

```C
#include "get_next_line.h"

int main(void)
{
    char *line;
    int fd = open("file.txt", O_RDONLY);

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s\n", line);
        free(line);
    }
    close(fd);
    return (0);
}
```

**Note**: Use the libft project from now on to use this function.

## Conclusions
- The get_next_line function is a useful tool for reading files in a program, and it is often used in later projects at 42.
- This project has been added to the libft, which can be found [here](https://github.com/Jkutkut/42Madrid-Libft).
