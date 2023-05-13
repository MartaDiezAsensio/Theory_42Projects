#include<stdio.h>
#include<string.h>
#include <stdlib.h>

char	*function()
{
	char	buffer[20];
	strcpy(buffer, "hello");
	return (buffer);
}

char	*function2(char *buffer)
{
	strcpy(buffer, "hello");
	return (buffer);
}

char	*function3()
{
	char	*buffer;

	buffer = (char *)malloc(sizeof(char) * 20);
	strcpy(buffer, "hello");
	return (buffer);
}

int	main()
{
	char	*str;

	str = function3(str);
	printf("%s", str);
}

/*function1 would have an unpredictable output because buffer is
an "auto array" which means that only exists in the context of
the funtion aka it's a local variable.*/

/*Local variables are allocated on the stack. When the function
returns, the stack frame is destroyed and the memory allocated 
to buffer is freed.*/

/*To fix this issue, buffer should be alocated in the heap using
dynamic memory allocation functions like malloc() or calloc()
and then free the memory when it's no longer needed (Function3).
Alternatively you can pass a buffer to the function as a parameter
and copy the string to that buffer. (Function2)*/

