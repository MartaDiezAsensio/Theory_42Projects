#include <stdio.h>
#include <unistd.h>

int	count_args(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
			count++;
		i++;
	}
	return (count);
}

int	main()
{
	char	str[] = "Number to print: %d , String : %s";

	printf("%i", count_args(str));
}