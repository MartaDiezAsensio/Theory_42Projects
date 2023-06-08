/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiez-as <mdiez-as@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 17:04:01 by mdiez-as          #+#    #+#             */
/*   Updated: 2023/06/08 17:32:31 by mdiez-as         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*This program implements a basic calculator that evaluates arithmetic
expressions using a stack to hadle the operator procedence.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Structure to represent a stack

typedef struct	Stack
{
	int	top;
	int	capacity;
	int	*array;
}Stack;

//Function to create a stack
Stack	*create_stack(int capacity)
{
	Stack	*stack = (Stack *)malloc(sizeof(Stack));
	
	stack->top = -1;
	stack->capacity = capacity;
	stack->array = (int *)malloc(sizeof(int) * stack->capacity);
	
	return (stack);
}

//Function to check if the stack is empty
int	isEmpty(Stack *stack)
{
	return (stack->top == -1);
}

//Function to check if the stack is full
int	isFull(Stack *stack)
{
	return (stack->top == stack->capacity -1);
}

//Function to push an element to the stack
void	push_elem(Stack *stack, int elem)
{
	if (isFull(stack))
	{
		printf("Stack overflow\n");
		return ;
	}
	stack->array[++stack->top] = elem;
}

//Function to pop an element from the stack
int	pop_elem(Stack *stack)
{
	if (isEmpty(stack))
	{
		printf("Stack underflow\n");
		return (-1);
	}
	return (stack->array[stack->top--]);
}

//Functino to evaluate an arithmetic expression
int	evaluateExpression(const char* expression) {
	Stack* stack = createStack(strlen(expression));
	int i;

	for (i = 0; i < strlen(expression); i++) {
		if (isdigit(expression[i])) {
			push(stack, expression[i] - '0');
		} else {
			int operand1 = pop(stack);
			int operand2 = pop(stack);

			switch (expression[i]) {
				case '+':
					push(stack, operand2 + operand1);
					break;
				case '-':
					push(stack, operand2 - operand1);
					break;
				case '*':
					push(stack, operand2 * operand1);
					break;
				case '/':
					push(stack, operand2 / operand1);
					break;
			}
		}
	}
	return pop(stack);
}

int	main() {
	const char* expression = "62+5*84/-";
	int result = evaluateExpression(expression);

	printf("Result: %d\n", result);

	return (0);
}