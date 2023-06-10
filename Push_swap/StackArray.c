
// IMPLEMENTATION OF STACK USING AN ARRAY

#include <stdio.h>

//Stack structure

typedef struct Stack
{
	int	items[100];
	int	top;
	int	index;
}Stack;

int	isEmpty(Stack *stack);
int	isFull(Stack *stack);

void	initialize(Stack *stack)
{
	stack->top = -1;
	stack->index = 0;
}

//Push (insert)
void	push(Stack *stack, int	top)
{
	stack->top = top;
	stack->items[stack->index] = stack->top;
	stack->index++;
}

//Pop (extract)
int	pop(Stack *stack)
{
	if (isEmpty(stack))
		return (-1);
	return (stack->items[stack->top--]);
}

//IsEmpty
int	isEmpty(Stack *stack)
{
	if (stack->top == -1)
		return (1);
	return (0);
}

//IsFull
int	isFull(Stack *stack)
{
	if (stack->index == 99)
		return (1);
	return (0);
}

//Peek (get top element without removing it)
int	peek(Stack *stack)
{
	return (stack->top);
}

int	main()
{
	Stack	stack;

	initialize(&stack);

	push(&stack, 3);
	push(&stack, 7);
	push(&stack, 2);

	printf("Top element: %d\n", peek(&stack));

	printf("Elements: ");
	while (!isEmpty(&stack)) {
		printf("%d ", pop(&stack));
	}
	printf("\n");

}