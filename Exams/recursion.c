/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiez-as <mdiez-as@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 22:24:20 by mdiez-as          #+#    #+#             */
/*   Updated: 2023/06/18 23:26:12 by mdiez-as         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

//Print first 50 natural numbers
void	print_50(int num)
{
	if (num <= 50)
	{
		printf("%d ", num++);
		print_50(num);
	}
}

//Sum of numbers from 1 to n
int	cumultive_sum(int n)
{
	int	i;

	if (n == 1)
		return (1);
	else
		i = n + cumultive_sum(n - 1);

	return i;
}

//Find factorial ofa number

int	main()
{
	printf("%d", cumultive_sum(5));
}