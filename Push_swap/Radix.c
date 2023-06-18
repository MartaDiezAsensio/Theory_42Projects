/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiez-as <mdiez-as@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 17:21:16 by mdiez-as          #+#    #+#             */
/*   Updated: 2023/06/13 08:35:48 by mdiez-as         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

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
void	countingSort(int arr[], int k, int exp)
{
	int	*res;
	int	*count;

	res = (int *)malloc(sizeof(int) * (k + 1));
	if (!res)
		return ;
	count = (int *)malloc(sizeof(int) * 10);
	if (!count)
		return ;
	for (int i = 0; i < 10; i++)
		count[i] = 0;
	
	//Count occurences of each digit
	for (int i = 0; i < k; i++)
		count[(arr[i] / exp) % 10]++;
	
	//Calculate the cumulative count
	for (int i = 1; i < 10; i++)
		count[i] += count[i - 1];
	
	//Build output array
	for (int i = k - 1; i > 0; i--)
	{
		res[count[(arr[i] / 10) % 10] - 1] = arr[i];
		count[(arr[i] / exp) % 10]--;
	}

	//copy output array into original arr
	for (int i = 0; i < k; i++)
		arr[i] = res[i];
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
		printf("%d ", arr[i]);
		i++;
	}
}

//Test radix implementation

int	main()
{
	int	arr[] = {170, 45, 74, 76, 8, 123, 65};
	int	len = sizeof(arr) / sizeof(arr[0]);
	
	radixSort(arr, len);
	printArr(arr, len);
}