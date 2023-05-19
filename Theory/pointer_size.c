#include <stdio.h>

int	main()
{
	int		*ptr1;
	char	*ptr2;
	long	*ptr3;

	printf("%d\n", sizeof(ptr1));
	printf("%d\n", sizeof(ptr2));
	printf("%d\n", sizeof(ptr3));
}

/* This functions is printing the size reserved for the memory. 
In this case we get 8 because in a 64-bit machine, the size of 
a pointer is 8 bytes*/