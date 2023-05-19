#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_COL 4
#define MAX_ROW 3

/*When running this code we get an arrer in p (expresion
must be a modifiable lvalue, an expresion that yields an 
object reference, a dereferenced pointer or a funtion call
that returns a refrence).
In the code 'p' is declared as an array of pointers to *int 
with 4 elements. This means that the emory allocation will 
not match the type of 'p'. There is not sufficient allocation.*/
void	allocation_1(int *p[MAX_COL])
{
	p = (int (*) [MAX_COL])malloc(sizeof(*p) * MAX_ROW);
}

/*This other function takes the idea of the previous one
and allocates using an iterative loop one string for
each place of the array of pointers*/
void	allocation_2(int *p[MAX_COL])
{
	int	i;

	i = 0;
	while (i < MAX_COL)
	{
		p[i] = (int *)malloc(sizeof(int) * MAX_ROW);
		i++;
	}
}

/*Here the parameter p needs to be a triple pointer because 
is pointing to a double pointer. */
void	allocation_3(int ***p)
{
	int	i;

	i = 0;
	*p = (int **)malloc(sizeof(int *) * MAX_ROW);
	while (i < MAX_ROW)
	{
		(*p)[i]= (int *)malloc(sizeof(int) * MAX_COL);
		i++;
	}
}

/*This function does the same as the precious one but takes 
as paramenters the ammount of rows and cols. This way we don't
need tripple pointers as we don't need to point into a double
pointer and instead we allocate the memory for the table with
rows and cols pertinent.*/
char	**allocation_4(int rows, int cols)
{
	char	**arr;
	int	i;

	i = 0;
	arr = (char **)malloc(sizeof(char *) * rows);
	if (!(arr))
		return (NULL);
	while (i < rows)
	{
		arr[i] = (char *)malloc(sizeof(char) * cols);
		if (!(arr[i]))
			return (NULL);
		i++;
	}
	return (arr);
}

int main()
{
	char	**arr;
	char	rows = 3;
	char	cols = 4;
	int	i;

	i = 0;
	arr = NULL;
	arr = allocation_4(rows, cols);

	while (i < rows)
	{
		strcpy(arr[i], "hol");
		i++;
	}

	while (i < rows)
	{
		printf("%s", arr[i]);
		i++;
	}

	while (i < rows)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

/*Sde note: malloc allocates memory from the heap and not
from the stack.*/