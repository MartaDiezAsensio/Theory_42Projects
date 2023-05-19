/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiez-as <mdiez-as@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 19:51:41 by mdiez-as          #+#    #+#             */
/*   Updated: 2023/05/19 21:57:42 by mdiez-as         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static char	*ft_string(unsigned long num, int *strlen)
{
	int				i;
	unsigned long	temp;
	char			*str;

	i = 0;
	temp = num;
	while (temp != 0)
	{
		temp = temp / 16;
		i++;
	}
	str = calloc(i + 1, sizeof(char));
	*strlen = i - 1;
	return (str);
}

int	ft_print_pointer(unsigned long num)
{
	unsigned long	temp;
	char			*print;
	int				i;
	int				*iptr;

	iptr = &i;
	temp = num;
	print = ft_string(num, iptr);
	if (!print)
		return (0);
	while (temp != 0 && i-- >= 0)
	{
		if ((temp % 16) < 10)
			print[i + 1] = (temp % 16) + '0';
		else
			print[i + 1] = (temp % 16) + '7';
		temp = temp / 16;
	}
	i = ft_strlen(print) + ft_putstr("0x");
	ft_putstr(print);
	free(print);
	if (num == 0)
		i += ft_putchar('0');
	return (i);
}
