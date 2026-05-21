*This project has been created as part of the 42 curriculum by ehorvat*.

# Push_swap
## Description

**Push_swap** is an algorithm project whose objective is to sort data on a stack, using a highly limited set of instructions and the lowest possible number of actions.

The program receives a list of integers, pushes them onto `Stack A`, and uses an auxiliary `Stack B` to move and sort them. To achieve maximum efficiency and meet the strict move limits of the evaluation (especially for 100 and 500 numbers), this project implements different strategies:

* **Small stacks (2 to 5 numbers)**: Custom algorithms are used with logical checks (hardcoded) and shortest path calculations (stack median) to solve them in the minimum number of moves.

* **Large stacks (100 to 500 numbers)**: The *Radix Sort* algorithm in base 2 (bitwise operations) is used. Previously, the numbers are pre-indexed (from 0 to N-1) to simplify the process, avoid issues with negative numbers, and reduce the number of bits to process.

## Instructions

### Compilation
The project includes a standard `Makefile`. To compile the executable, simply run:

```
Bash

make
```

This will generate the `push_swap` executable. (You can use `make clean`, `make fclean`, and `make re` for standard object file management).

### Execution
The program accepts the numbers to be sorted in two ways: passed as multiple arguments or as a single string enclosed in quotes.

```
Bash

# As multiple arguments
./push_swap 42 -15 8 99 0

# As a single string
./push_swap "42 -15 8 99 0"
```

### Expected Output
The program will print to the standard output (`stdout`) the list of operations (separated by newlines) needed to sort the numbers from lowest to highest in Stack A. The possible operations are: `sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`, `rrr`.

In case of an error (duplicate numbers, non-numeric arguments, or integer overflow), the program will print `Error` to the standard error output (`stderr`).

# Resources
Below is a list of classic references, debugging tools, and tutorials that have been fundamental in understanding the logic and development of the project:

* **Random Number Generator**: Ideal for creating quick lists of numbers to test the program without writing them by hand.
[Random Number Generator](https://www.calculatorsoup.com/calculators/statistics/random-number-generator.php)

* **Push_swap Visualizer**: An essential tool to graphically see how the stacks move in real-time and understand if the algorithm is doing what it should.
[ahkoh's Web Visualizer](https://codepen.io/ahkoh/full/bGWxmVz)

* *Radix Sort* and Algorithms Explanations: Video support material to assimilate pre-indexing and the inner workings of Radix using bit shifts.

* **YouTube**: [The fastest sorting algorithm Polylog](https://www.youtube.com/watch?v=Y95a-8oNqps)

* **YouTube**: [push_swap: un algoritmo de ordenamiento de alto rendimiento que utiliza 2 pilas ](https://www.youtube.com/watch?v=OaG81sDEpVk&t=2945s)

# AI Usage
During the development of this project, an AI assistant (LLM) was used in a "peer programmer" role for very specific tasks, always ensuring that the logical architecture was self-created. The exact tasks for which it was used were:

* **Memory debugging (Valgrind)**: Identification of "definitely lost leaks" during parsing, specifically locating the exact moment where `free()` should be applied to temporary numerical conversion arrays after node population.

* **Segmentation Fault resolution**: Guided help to find buffer overflows caused by trailing spaces in the `ft_split` function, as well as null pointer dereferences in stack operations (`pa`/`pb`).

* **Bitwise logic**: Theoretical validation of the `>>` (*shift right*) and `&` (*AND*) operator's functionality for the dynamic calculation of the maximum number of bits required by the Radix Sort algorithm.
