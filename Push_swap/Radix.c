/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiez-as <mdiez-as@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 17:21:16 by mdiez-as          #+#    #+#             */
/*   Updated: 2023/06/10 17:36:47 by mdiez-as         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

//Function to get max value of the arra
int	getMax(int arr[], int len)
{
	int	max;
	int	i;

	max = arr[0];
	i = 0;
	while (i < len)
	{
		if (arr[i] > max)
			max = arr[i];
		i++;
	}
	return (max);
}

//Use counting sort to sort the elements based on the digit exp
void	countingSort(int arr[], int len, int exp)
{
	int	res[len];
	int	count[10] = {0};
}

//Radix sort implementation
void	radixSort(int arr[], int len)
{
	int	max;
	int	exp;

	max = getMax(arr, len);
	exp = 1;
	while (max / exp > 0)
	{
		countingSort(arr, len, exp);
		exp *= 10;
	}
}

//Print Array

void	printArr(int arr[], int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		printf("%d", arr[i]);
		i++;
	}
}

//Test radix implementation

int	main()
{
	int	arr[] = {170, 45, 74, 76, 8, 123, 65};
	int	len = sizeof(arr) / sizeof(arr[0]);

	printArr(arr, len);
	printf("\n");

	radixSort(arr, len);
	printArr(arr, len);
}