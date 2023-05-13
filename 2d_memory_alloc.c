#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_COL 4
#define MAX_ROW 3

int	main()
{
	int	*p[MAX_COL];

	*p = (int (*) [MAX_COL])malloc(sizeof(*p) * MAX_ROW);
}

/**/
