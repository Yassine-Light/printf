*This project has been created as part of the 42 curriculum by ylaghrib.*
 
# ft_printf
 
## Description
 
**ft_printf** is a re-implementation of the C standard library function `printf()`.
The goal of the project is to learn how **variadic functions** work in C
(`va_start`, `va_arg`, `va_end`) and to write clean, extensible code
that parses a format string and prints formatted output.
 
The project produces a static library, `libftprintf.a`, exposing:
 
```c
int ft_printf(const char *fmt, ...);
```
 
It returns the number of characters printed, like the original `printf()`, and -1 on error.
 
### Supported conversions
 
| Conversion | Description                                         |
|------------|-----------------------------------------------------|
| `%c`       | Prints a single character                           |
| `%s`       | Prints a string                                     |
| `%p`       | Prints a `void *` pointer in hexadecimal            |
| `%d`       | Prints a signed decimal (base 10) number            |
| `%i`       | Prints a signed integer in base 10                  |
| `%u`       | Prints an unsigned decimal (base 10) number         |
| `%x`       | Prints a number in lowercase hexadecimal (base 16)  |
| `%X`       | Prints a number in uppercase hexadecimal (base 16)  |
| `%%`       | Prints a percent sign                               |

 
## Instructions
 
### Compilation
 
The library is built with `cc` and the flags `-Wall -Wextra -Werror`.
`libftprintf.a` using `ar`.
 
```bash
make        # builds libftprintf.a
make clean  # removes object files
make fclean # removes object files and libftprintf.a
make re     # rebuilds everything
```
 
### Usage
 
Include the header and link against the library:
 
```c
#include "ft_printf.h"
 
int main(void)
{
    ft_printf("Hello %s! %d + %d = %i\n", "world", 1, 2, 3);
    return (0);
}
```
 
```bash
cc -Wall -Wextra -Werror main.c libftprintf.a -o test
./test
```
 
## Algorithm and data structures
  
**Algorithm.** `ft_printf` walks through the format string one character at a
time:
 
1. If the current character is not `%`, it is written as-is with `write()`.
2. If it is `%`, the next character is read and passed to a dispatcher that
   selects the matching conversion handler (`c`, `s`, `p`, `d`, `i`, `u`, `x`,
   `X`, `%`).
3. The handler fetches its argument from the `va_list` with `va_arg()` using
   the correct type, prints it, and returns the number of characters written.
4. All returned counts are accumulated and the total is returned at the end,
   after `va_end()` has been called.

**Justification:**
 
- A single pass over the format string is simple and runs in linear time.
- The `format()` keeps each conversion isolated in its own small function, 
 which keeps the code extensible and Norm-compliant.
- Numbers are converted to their base representation ,
 which avoids any dynamic allocation and therefore any risk of memory leaks.
- Printing directly with `write()` follows the subject, which forbids
  reproducing the original buffer management.
- Special cases are handled explicitly: `NULL` strings print `(null)`, `%p`
  with a null pointer prints `(nil)`.

**Data structures.**

- No custom data structure is needed: the only state is the
 `va_list` holding the variadic arguments and an integer counter of printed
 characters.
 
## Resources
 
### References
 
- `man 3 printf` – behavior of the original function
- `man 3 stdarg` – `va_start`, `va_arg`, `va_copy`, `va_end`
- `man 3 write`
- *System V Application Binary Interface* AMD64 Architecture Processor Supplement Draft Version 0.99.6
### Use of AI

- AI was used to help draft the structure and wording of this README.
- Explaining how variadics work and why designed in their way (like how they need a known param).