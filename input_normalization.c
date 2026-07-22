/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_normalization.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aunoguei <aunoguei@student.42urduliz.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 15:13:09 by aunoguei          #+#    #+#             */
/*   Updated: 2026/02/15 13:46:12 by aunoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	num_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	bubblesort(int *numbers, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (numbers[j] > numbers[j + 1])
				num_swap(&numbers[j], &numbers[j + 1]);
			j++;
		}
		i++;
	}
}

static int	partition(int *numbers, int low, int high)
{
	int	pivot;
	int	i;
	int	j;

	pivot = numbers[low];
	i = high;
	j = high;
	while (i > low)
	{
		if (numbers[i] > pivot)
		{
			num_swap(&numbers[i], &numbers[j]);
			j--;
		}
		i--;
	}
	num_swap(&numbers[low], &numbers[j]);
	return (j);
}

void	quicksort(int *numbers, int low, int high)
{
	int	pivot_index;

	if (low < high)
	{
		pivot_index = partition(numbers, low, high);
		quicksort(numbers, low, pivot_index - 1);
		quicksort(numbers, pivot_index + 1, high);
	}
}
/*
#include <stdio.h>
int	main(void)
{
	int	i;
	int	numbers[] = {5, 4 , 3, 1, 2, 0};

	i = 0;
	quicksort(numbers, 0, 5);
	while(i < 6)
	{
		printf("%d", numbers[i]);
		i++;
	}
}*/
