
THE STACK

A stack is a kind of list where items are always added to the fromt and removed from the front. Thus, a stack is
a LIFO structure. A stack can be thought of a structure that resambles a stack of trays. Each time a piece of 
data is added to the stack, it is placed on the top. Each time a piece of data is removed it also must be removed
from the top. Typically only the top item is visible.

STACK OPERATIONS

- Push: Add a new item to the stack
- Pop: Remove the top item from the stack
- Initialize: Creates an empty stack
- isEmpty: test for wether or not stack is empty
- isFull: test to see if stack is full and cannot grow
- Top: looks at value of the top item but not remove it.

STACK IMPLEMENTATIONS

THere are two general ways to implement a stack. As a stack is essentially a list with a restriction on the operations
of a list, we can use either an array or a linked list to implement it. The key to understanding how to do this efficiently
is to understand the nature of stack.

- Array Implementation
	With a list that is implemented as an array we typically start by creating an array that is bigger than what we need. To
	add a new value to the end of the array is a constant time operation as long as we track where the end is (witha  pointer).
	If we do that, the most recently added item will be at the back of the array. Removing that item simply involves decreasing
	the end of the array tracker by one.
		-> Array tracker

- Linked List Implementation
	To implement a stack using a linked list, we have to consider the type of linked list we would use and which end of the list
	we would want to insert to.

	The simplest linked list there is is a sngly list. If this linked list was implemented with just a poiner to the first node,
	insertion would be O(1) at front of the list, O(n) at back of list. Removal will have the same time complexity.

	If we were to insert always at front of list, then the most recently added item would be at the from os the list. Thus,
	removal must occur from the from as we always remove the most recently added item.

