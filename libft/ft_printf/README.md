*This project has been created as part of the 42 curriculum by aunoguei.*

#Description

ft_printf is a project that consists of reimplementing the standard C function `printf()`
in order to gain a deeper understanding of the C language, variadic functions, and static
library creation.

`ft_printf` writes output to the standard output stream, under the control of a format
string that specifies how subsequent arguments (accessed via the variable-length argument
facilities of `stdarg`) are converted for output.

#Implementation

All functions are written in C and compiled into a static library : libftprintf.a

It supports the following format specifiers:
- `%c`
- `%s`
- `%p`
- `%d`
- `%i`
- `%u`
- `%x`
- `%X`
- `%%`

#Instructions

To compile the library, run :
make

Other available rules:
- make clean: removes object files
- make fclean: removes object files and the library
- make re: recompiles the library

#Resources
https://man7.org/linux/man-pages/man3/printf.3.html
