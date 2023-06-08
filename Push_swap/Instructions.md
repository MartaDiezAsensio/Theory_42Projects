
COMMON INSTRUCTIONS

Push swap is a project that wwants you to sort a set of data. 
You have at your isposal a set of integeer valuess, 2 stacks, and a set of instructions to manipulate both stacks.
The goal is to write a program called push_swap.c which calculates and displays on the standard output the smallest 
program, made of Push swap languaje instructions, that sorts the integers received as an argument. 

STACK

	Remember that a stack is a data type that is characterized to be a LIFO data structure. (Last-In First-out).

	Formal definition: A stack is an ambstract data type that serves as a collection of elements, with two main 
	operations:
		1. Push: Adds an element to the collection
		2. Pop: Removes the most recently added element that was not yet removed.

	Applications
		1. Expression evaluation and syntax parsing
		2. Backtracking
		3. Compile-time memory management
	

ANALYSIS OF ALGORITHMS (TIME COMPLEXITY)

In computer science, the analysis of algorithms is the process of finding the compuational coplexity of algorithms.
	Cost Models
	(+INFO)


RULES

	1. At the beginning the stack A contains a random ammount of negative and/or positive numbers which cannot be 
	duplicated.
	2. Stack B is empty

The goal is to sort in ascending order numbers intp stack A. To do so you have the following operations:

	1. sa (swap a): Swap the first 2 elements at the top of slack a. (do nothing if there is only one or no elements).
	2. sb (swap b): Swap the first 2 elements at the top of slack b. (do nothing if there is only one or no elements).
	3. ss: sa and sb at the same time.
	4. pa (push a): Take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
	5. pb (push b): Take the first element at the top of a and put it at the top of b. Do nothing if a is empty.
	6. 
