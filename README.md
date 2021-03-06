# Monte Carlo Tree Search

## Implemented by

- Andrea Mascaretti (andrea1.mascaretti@mail.polimi.it)
- Michele Pellegrino (michele2.pellegrino@mail.polimi.it)

*(Source code available on [GitHub](https://github.com/mascaretti/mcts.git))*

## Requirements

- C++11 compiler (tested with g++ and clang)
- MPI (for parallelization)

Optional:
- R (for data analysis and plots)
  * the [*tidyverse*](https://www.tidyverse.org/) package
  * the [*forecats*](https://forcats.tidyverse.org/) package

## Compiling

- Run `$ make [options]` in the main directory.
  * Selecting `DEBUG=yes` (`DEBUG=no`) enables (disable) debugging (with GDB, for instance)

## Running

- Parallel:
  * run `$ mpiexec -np [number of cores] [executable]` to run the parallel scripts.

- Speedup test:
  * run `test_gen.sh` to run all the tests in the folder **speedup_test**.

- Serial:
  * run `$ ./[executable]` to execute the serial scripts.

## Description

- **src**:        contains the source code and the template classes that implement both the games and
            the search tree
- **examples**:   contains examples of matches, namely ai vs. random player, ai vs. ai and
            ai vs. human player
- **test**:       contains various tests concerning data structures (struct_test), games (nim_test
            and oxo_test), parallel speedup (speedup_test) and data analysis (analysis)


Developed and tested on Debian, CentOs and MacOS X
