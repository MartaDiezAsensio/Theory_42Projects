#include <stdio.h>
#include <stdarg.h> //Library needed to implement variatic functions

/*Function that sums a set number of numbers*/

int	ft_sum(int a, int b, int c)
{
	int	res;

	res = a + b + c;
	return (res);
}

/*Same function but implemented with variatic functions*/

int	ft_va_sum(int count, ...)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	va_list	args;
	/*Initialization of args, va_list data type, it's going 
	to store the list of our arguments*/

	va_start(args, count);
	/*Sets the pointer to the list args to the first parameter.
	The second param of this function points to the start of list*/

	while (i < count)
	{
		res = res + va_arg(args, int);
		i++;
	}
	va_end(args);
	/*Finishes the iteration on the list. (Closes the list)*/
	return (res);
}

int	main()
{
	int	a = 3;
	int	b = 4;
	int	c = 1;

	printf("Regular sum : %i\n", ft_sum(a, b, c));
	printf("Variatic sum : %i\n", ft_va_sum(3, 3, 4, 1));
}