/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiez-as <mdiez-as@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 21:37:01 by mdiez-as          #+#    #+#             */
/*   Updated: 2023/05/19 21:55:20 by mdiez-as         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"


static int	ft_formats(va_list args, char *str)
{
	int	i;

	i = 0;
	if (*(str + 1) == 'c')
		i += ft_putchar(va_arg(args, char));
	else if (*(str + 1) == 's')
		i += ft_putstr(va_arg(args, char *));
	else if (*(str + 1) == 'p')
		i += ft_print_pointer(va_arg(args, unsigned long));
	else if (*(str + 1) == 'd')
		i += ft_putnbr(va_arg(args, int));
	else if (*(str + 1) == 'i')
		i += ft_putnbr(va_arg(args, int));
	else if (*(str + 1) == 'u')
		i += ft_putnbr_u(va_arg(args, unsigned int));
	else if (*(str + 1) == 'x')
		i += int_to_hex(va_arg(args, unsigned int));
	else if (*(str + 1) == 'X')
		i += int_to_hex2(va_arg(args, unsigned int));
	else if (*(str + 1) == '%')
	{
		write(1, "%", 1);
		va_arg(args, char);
		i++;
	}
	else
		return (-1);
	return (i);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	va_start(args, str);
	int	i;

	i = 0;
	while (*str != '\0')
	{
		if (*str == '%')
			i += ft_formats(args, str);
		else
			i += ft_putchar(*str);
		str++;
	}
}
