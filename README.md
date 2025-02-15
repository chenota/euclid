# Euclid
Provides the Euclidian and Extended Euclidian algorithms for finding the greatest common divisor (GCD) of two numbers.

## Program Arguments

| Argument        | Description                                                                  |
|-----------------|------------------------------------------------------------------------------|
| `-e`            | Run the extended Euclidian algorithm.                                        |
| `-v`            | Use verbose program output.                                                  |
| `-l`            | If using verbose output, print the execution table with $\LaTeX$ formatting. |
| `A`             | (Positional) Input number A.                                                 |
| `B`             | (Positional) Input number B.                                                 |

**Note:** Options must come before positional arguments.

## Build Information

To build the program, you can use the provided makefile by running the `make` command.

## Example Output

```
$ ./eucl.out -ve 1759 550  

i       r       q       x       y
-1      1759            1       0
0       550             0       1
1       109     3       1       -3
2       5       5       -5      16
3       4       21      106     -339
4       1       1       -111    355
5       0       4

GCD(1759, 550) = 1

Multiplicative Inverse of 550 (mod 1759) = 355
```