#ifndef PRINTF_H
# define PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
#include <stdarg.h>

int	ft_putchar(char c);
int	ft_putstr(char *s);
size_t	ft_strlen(const char *s);
int	ft_putnbr(int n);

int	ft_print_pointer(unsigned long num);

#endif