/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiez-as <mdiez-as@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 20:13:55 by mdiez-as          #+#    #+#             */
/*   Updated: 2023/05/19 21:34:24 by mdiez-as         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int main()
{
	void	*ptr;
	//unsigned long num;

	//num = &ptr;
	ft_print_pointer((unsigned long)ptr);
	printf("     %p", ptr);
}
