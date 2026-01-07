_This project has been created as part of the 42 curriculum by **danborys**_

# PUSH_SWAP

## DESCRIPTION

PUSH_SWAP is a program that calculates and displays an optimized sequence of Push_swap instructions needed to sort the given integers. The program uses 2 stacks named a and b.

At the beginning:
* The stack a contains a random number of unique negative and/or positive integers.
* The stack b is empty.

The goal is to sort the numbers in stack a in ascending order.

### The following operations can be used:

> **sa** (swap a): Swap the first 2 elements at the top of stack a.

> **sb** (swap b): Swap the first 2 elements at the top of stack b.

> **ss** : sa and sb at the same time.
> **pa** (push a): Take the first element at the top of b and put it at the top of a.

> **pb** (push b): Take the first element at the top of a and put it at the top of b.

> **ra** (rotate a): Shift up all elements of stack a by 1.
The first element becomes the last one.

> **rb** (rotate b): Shift up all elements of stack b by 1.
The first element becomes the last one.

> **rr** : ra and rb at the same time.

> **rra** (reverse rotate a): Shift down all elements of stack a by 1.The last element becomes the first one.

> **rrb** (reverse rotate b): Shift down all elements of stack b by 1.The last element becomes the first one.

> **rrr** : rra and rrb at the same time.

## INSTRUCTIONS

Go to project's directory and run **make** or **make all** or **make push_swap** in a console. The push_swap executable will be created. Now you can run something like ```./push_swap 2 1 3 6 5 8``` or ```ARG="4 67 3 87 23"; ./push_swap $ARG``` . The program will print sequence of operations that can be used for sorting list of integers received as input:

```
$>./push_swap 2 1 3 6 5

sa
pb
pb
pb
sa
pa
pa
pa
```
In case of error, the program display "Error" followed by an ’\n’ on the standard error.
Errors include, for example: empty input, some arguments not being integers, some arguments exceeding the integer limits, and/or the presence of duplicates.

## BONUS

The bonus part includes a program called **checker**.
It verifies whether a given sequence of push_swap instructions correctly sorts the stack.

### Description

The **checker** program takes the same arguments as `push_swap` and reads instructions from the standard input.
After executing all instructions:

- If stack **a** is sorted in ascending order **and** stack **b** is empty, it prints **"OK"**
- Otherwise, it prints **"KO"**

If an error occurs, it prints **"Error"** followed by a newline to the standard error.

Errors include, for example:
- empty input
- non-integer arguments
- integers exceeding limits
- duplicate values
- invalid or incorrectly formatted instructions

### How to run

First, compile the bonus part: ```make bonus```
Then run *checker* with a list of integers and provide instructions via standard input:
```
$> ./checker 2 1 3
sa
<Ctrl+D>
OK
```

Or test it together with `push_swap`:
```
$> ./push_swap 2 1 3 | ./checker 2 1 3
OK
```

## RESOURCES

1. This guide helped to understand possible edge cases, sorting algorithms and their complexity: <https://42-cursus.gitbook.io/guide/2-rank-02/push_swap/algorithms>
2. Random number generator <https://www.calculatorsoup.com/calculators/statistics/random-number-generator.php>
3. ChatGPT was used for debugging and better understanding of sorting logic <https://chatgpt.com/>

