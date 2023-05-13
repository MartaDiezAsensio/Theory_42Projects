#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int	count_rows(char *str, char c)
{
	int	i;
	int	rows;

	i = 0;
	rows = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			rows++;
		i++;
	}
	return (rows);
}

int	count_cols(char *str, char c)
{
	int	len;
	int	i;

	i = 0;
	len = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
		{
			return (len);
			len = 0;
		}
		len++;
		i++;
	}
	return (0);
}

char	**allocate_mem(int rows, int cols)
{

}

int	main()
{
	char	str[] = "Ho Ho Ho";
	char	c = 'o';
	int		i = 0;
	char	*str2;

	str2 = str;
	printf("%d\n", count_rows(str2, c));
	while (i < count_rows(str2, c) && (str))
	{
		printf("%d\n", count_cols(str2, c));
		str2 = str2 + count_cols(str2, c) + 1;
		i++;
	}
}