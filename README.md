# Libft

My first library in C, built at **1337 Khouribga**, part of the 42 Network.

I reimplemented a set of common C library functions and added utilities for strings, file descriptors, and singly linked lists. The result is `libft.a`: a static library I can link into my next projects.

**Status:** Libft validated · **Language:** C · **Contents:** 34 mandatory functions + 9 linked-list functions

## What's inside

| Area | Functions |
| --- | --- |
| Character checks | `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint` |
| Case conversion | `ft_toupper`, `ft_tolower` |
| Memory | `ft_memset`, `ft_bzero`, `ft_memcpy`, `ft_memmove`, `ft_memchr`, `ft_memcmp`, `ft_calloc` |
| Strings | `ft_strlen`, `ft_strlcpy`, `ft_strlcat`, `ft_strchr`, `ft_strrchr`, `ft_strncmp`, `ft_strnstr`, `ft_strdup` |
| String utilities | `ft_substr`, `ft_strjoin`, `ft_strtrim`, `ft_split`, `ft_strmapi`, `ft_striteri` |
| Number conversion | `ft_atoi`, `ft_itoa` |
| File-descriptor output | `ft_putchar_fd`, `ft_putstr_fd`, `ft_putendl_fd`, `ft_putnbr_fd` |
| Linked lists | `ft_lstnew`, `ft_lstadd_front`, `ft_lstadd_back`, `ft_lstsize`, `ft_lstlast`, `ft_lstdelone`, `ft_lstclear`, `ft_lstiter`, `ft_lstmap` |

## Build

You need a C compiler, `make`, and `ar`. I developed this project on Linux.

```sh
git clone https://github.com/bossyassine78-ship-it/libft.git
cd libft
make
```

This creates `libft.a` in the project root. This repository builds **all 43 functions**, including the linked-list part, by default.

| Command | What it does |
| --- | --- |
| `make` | Build the complete library |
| `make bonus` | Build the same complete library; linked lists are already included |
| `make example` | Build the linked-list example |
| `make clean` | Remove object files |
| `make fclean` | Remove object files, the archive, and the example executable |
| `make re` | Rebuild the library from scratch |

Compilation uses `-Wall -Wextra -Werror`. Changes to a source file, `libft.h`, or the Makefile trigger the relevant rebuild. Running `make` again without changes keeps the existing build.

## Use it in another program

Include `libft.h`, then link your program with the archive:

```c
#include "libft.h"

int main(void)
{
    char *message;

    message = ft_strjoin("hello, ", "1337");
    if (!message)
        return (1);
    ft_putendl_fd(message, 1);
    free(message);
    return (0);
}
```

Save this as `main.c` in the project root, then run:

```sh
cc -Wall -Wextra -Werror -I. main.c -L. -lft -o demo
./demo
```

Expected output: `hello, 1337`.

## Linked-list example

```sh
make example
./examples/list_map
```

```text
original: hello world
mapped:   HELLO WORLD
```

The example uses `ft_lstmap` to create a second list with uppercase copies of the original strings. It keeps the original list unchanged and frees both lists before exiting.

### Memory ownership

- Free strings returned by `ft_strdup`, `ft_substr`, `ft_strjoin`, `ft_strtrim`, `ft_itoa`, and `ft_strmapi` when finished.
- For `ft_split`, free each string and then the pointer array.
- `ft_lstnew` stores the content pointer you give it. It does not copy the content.
- `ft_lstclear` and `ft_lstdelone` use your `del` callback to dispose of content before freeing nodes. Choose that callback according to who owns the content.
- `ft_lstmap` creates new nodes using the values returned by your `f` callback. To make independent content, the callback must create independent values. If node allocation fails, the function uses `del` to clean up the mapped content and nodes built so far.

## What I learned

This project pushed me to understand what happens behind small functions I used to take for granted:

- Moving through raw bytes with pointers, and handling overlapping memory.
- Working with null-terminated strings and boundary cases.
- Managing allocation failures and freeing partially built structures.
- Using callbacks and double pointers to build and transform linked lists.
- Compiling `.c` files into `.o` files, building an archive with `ar`, and linking it into a program.

I also used `nm`, `readelf`, and `objdump` while studying how the source becomes object files, symbols, and an executable.

## Repository notes

The implementation comes from my completed Libft project. For this repository, I moved the standalone test out of `ft_lstmap.c`, added a self-contained example with cleanup, made compilation and header dependencies explicit in the Makefile, and changed the bitwise `|` guard in `ft_lstdelone` to logical `||`.

The function bodies otherwise retain my original approach. This is an educational library, and the examples are not a complete correctness test suite.

---

**Yassine El Hilal** · `yael-hil` at 1337 · [GitHub](https://github.com/bossyassine78-ship-it)
