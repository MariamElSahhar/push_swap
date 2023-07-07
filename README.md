# push_swap
This 42 project involves sorting a stack of numbers using two stacks and a set of predefined operations. The goal is to develop an algorithm that sorts the stack with the fewest number of operations. It provides an opportunity to explore different sorting algorithms and optimize their performance for specific scenarios.  

## Prerequisites
- [GCC](https://gcc.gnu.org/) or C complier

## Installation
1. Clone the repository  
  `git clone https://github.com/MariamElSahhar/push_swap.git`  
2. Navigate to the directory  
  `cd push_swap`  
3. Compile the program
   `make`

## Usage
Run the program using the following command  
`./push_swap [numbers]`    
**[numbers]** is the list of integers you want to sort, separated by spaces. For example:  
`./push_swap 4 2 -100 59 0`  
The program outputs a series of permitted operations to sort the numbers.
### Permitted Operations
- **sa** - Swap the first two elements of stack A
- **sb** - Swap the first two elements of stack B
- **ss** - Swap the first two elements of both stack A and stack B
- **pa** - Push the top element from stack B to stack A
- **pb** - Push the top element from stack A to stack B
- **ra** - Rotate stack A upward (shift all elements up by one, the first element becomes the last)
- **rb** - Rotate stack B upward (shift all elements up by one, the first element becomes the last)
- **rr** - Rotate both stack A and stack B upward
- **rra** - Rotate stack A downward (shift all elements down by one, the last element becomes the first)
- **rrb** - Rotate stack B downward (shift all elements down by one, the last element becomes the first)
- **rrr** - Rotate both stack A and stack B downward

### Performance
You can measure performance by counting the number of operations the program used like so:  
`./push_swap [numbers] | wc -l`  
