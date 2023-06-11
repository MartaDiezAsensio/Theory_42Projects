/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CountingSort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiez-as <mdiez-as@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 21:25:25 by mdiez-as          #+#    #+#             */
/*   Updated: 2023/06/11 23:06:41 by mdiez-as         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	*ft_countingSort(int arr[], int k)
{
	//Find maximum valu in the array
	int	max;
	int	i;

	max = arr[0];
	for (i = 0; i < k; i++)
	{
		if (arr[i] > max)
			max = arr[i];
	}

	//create a count array with size equal to (max + 1)
	int	*count;

	count = (int *)calloc((max + 1), sizeof(int));
	if (!count)
		return (0);
	

	//Count occurences of each value
	for (i = 0; i < k; i++)
		count[arr[i]]++;
	
	//Compute cumulative sum in count array
	for (i = 1; i < (max + 1); i++)
	{
		count[i] = count[i] + count[i - 1];
	}

	//Build the sorted array (careful with k -1 to get to index 0)
	int	*sorted;

	sorted = (int *)malloc(sizeof(int) * k);
	if (!sorted)
	{
		free(count);
		return (0);
	}
	
	for (i = k - 1; i >= 0; i--)
	{
		sorted[count[arr[i]] - 1] = arr[i];
		count[arr[i]]--;
	}

	//Copy the sorted array back to the original array
	for (i = 0; i < k; i++)
		arr[i] = sorted[i];
	
	free(count);
	free(sorted);

	return (arr);
}

int	main()
{
	int arr[] = {1, 4, 18, 3, 2, 9};
	int	k = sizeof(arr) / sizeof(arr[0]);

	int	*sorted;
	sorted = ft_countingSort(arr, k);
	
	for (int i = 0; i < k; i++)
	{
		printf("%d  ", sorted[i]);
	}
}

