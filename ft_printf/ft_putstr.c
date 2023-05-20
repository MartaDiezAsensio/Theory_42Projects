/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiez-as <mdiez-as@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 20:13:06 by mdiez-as          #+#    #+#             */
/*   Updated: 2023/05/19 20:22:00 by mdiez-as         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_putstr(char *s)
{
	int	len;

	len = ft_strlen(s);
	write(1, s, len);
	return ((int)ft_strlen(s));
}
