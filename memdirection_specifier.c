#include <stdio.h>

int	main()
{
	int		a = 8;
	char	b = 'a';
	int		c = 1278698243324;
	int		d = 1111111;

	printf("Value:  %d - Adress: %p\n", a, &a);
	printf("Value:  %c - Adress: %p\n", b, &b);
	printf("Value:  %d - Adress: %p\n", c, &c);
	printf("Value:  %d - Adress: %p\n", d, &d);
}

/* To print the adress you need to write &(var). 
If you don't you will just get the variable's value
in hexadecimal form*/