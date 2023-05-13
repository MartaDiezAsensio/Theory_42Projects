#include <stdio.h>
#include <string.h>
#include <stdlib.h>

union test
{
	int		i;
	float	f;
	char	c;
};

int	main()
{
	union test	*test_1;

	test_1 = (union test *)malloc(sizeof(union test));
	(*test_1).f = 2.6f;
	printf("Memory size occupied: %d\n", sizeof(test_1));
	printf("Float val = %.01f\n", (*test_1).f);
}

/*The 'f' after 2.6 is there to indicate that the number is 
a float type literal. In C, if a numeric literal contains a 
decimal point but no suffix is treated as a doubble (I've
tested that and as a double it shoud accupy 8 bytes but even
without f as a suffix, if stated as float is still 4 bytes).
*/

/*It seems like the size of this union is 8 when the max length 
of the variables if 4 bytes both for int and float.
This might be because the exct size of a union might also depend 
on the alignment requirements of the system. Some systems require 
additional padding between members to ensure that they are 
properly aligned.*/
