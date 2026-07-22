/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bucket_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppousser <ppousser@student.42urduliz.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 11:08:00 by ppousser          #+#    #+#             */
/*   Updated: 2026/02/19 11:08:04 by ppousser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	square_root(long unsigned nb)
{
	long unsigned	i;

	i = 1;
	while ((i * i) <= nb)
		i++;
	return (i - 1);
}

void	create_next_bucket(t_stacks *stacks, int bucket_size, int i,
		t_bench *bench)
{
	int	max_bucket;
	int	min_bucket;
	int	count;

	min_bucket = bucket_size * i;
	max_bucket = bucket_size * (i + 1);
	count = is_bucket_needed(stacks->a, min_bucket, max_bucket);
	while (count > 0)
	{
		if (stacks->a->index >= min_bucket && stacks->a->index < max_bucket)
		{
			pb(stacks, bench);
			count--;
		}
		else
			ra(stacks, bench);
	}
}

void	sort_buckets(t_stacks *stacks, t_bench *bench)
{
	int	count_ra;

	count_ra = 0;
	pa(stacks, bench);
	while (stacks->b)
	{
		if (stacks->a->index > stacks->b->index)
			pa(stacks, bench);
		else
		{
			while (stacks->a->index < stacks->b->index)
			{
				ra(stacks, bench);
				count_ra++;
			}
			pa(stacks, bench);
			while (count_ra > 0)
			{
				rra(stacks, bench);
				count_ra--;
			}
		}
	}
}

static void	create_buckets(t_stacks *stacks, int bucket_size, int size,
		t_bench *bench)
{
	int	i;

	i = 0;
	while (i < bucket_size - 1)
	{
		create_next_bucket(stacks, bucket_size, i, bench);
		i++;
	}
	while (stacks->a)
	{
		if (stacks->a->index == size - 1)
		{
			if (stacks->a->next != NULL)
			{
				ra(stacks, bench);
			}
			else
				return ;
		}
		pb(stacks, bench);
	}
}

void	bucket_sort(t_stacks *stacks, int size, t_bench *bench)
{
	int	bucket_size;

	bucket_size = square_root(size);
	create_buckets(stacks, bucket_size, size, bench);
	sort_buckets(stacks, bench);
}
