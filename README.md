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

## Documentation

Check the project documentation [here](./docs/index.md).
