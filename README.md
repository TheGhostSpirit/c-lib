# C-Lib

## Description

This is a high-level C Library built for GNU/Linux systems and focusing on bringing meaningful objects and utils for faster development.

## Installation

- Install Docker.

- Navigate to project folder.

- Build the docker image and compile the sources.

```bash
docker build -t compiler .
docker run --rm -v $PWD:/dev/temp compiler
```

- Link the compiled object file at /out against your project.

- Link the math library against your project as well (-lm).

- Include the header file at /out in your project.

#### Example

- A simple program using the lib:

```C
#include "c-lib.h"

int main(int argc, char **argv)
{
    String *str = wrapString("foo");
    str->proto->concat(str, "bar");
    puts(str->string);
    return 0;
}
```

- Can be compiled with gcc in the following way:

```bash
gcc -c main.c
gcc main.o c-lib.o -lm -o a.out
```

## Notes

- stdio, stdlib, stdarg, stdbool, string and math system headers are already included through the library, don't reinclude them!

## Documentation

Check the project documentation [here](./docs/index.md).
