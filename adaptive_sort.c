/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aunoguei <aunoguei@student.42urduliz.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 15:35:38 by aunoguei          #+#    #+#             */
/*   Updated: 2026/02/18 12:22:50 by aunoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_three(t_stacks *stacks, t_bench *bench)
{
	int	a;
	int	b;
	int	c;

	a = stacks->a->index;
	b = stacks->a->next->index;
	c = stacks->a->next->next->index;
	if (a < b && b > c && c < a)
		rra(stacks, bench);
	else if (a < b && b > c && c > a)
	{
		sa(stacks, bench);
		ra(stacks, bench);
	}
	else if (a > b && b < c && c < a)
		ra(stacks, bench);
	else if (a > b && b < c && c > a)
		sa(stacks, bench);
	else if (a > b && b > c && c < a)
	{
		sa(stacks, bench);
		rra(stacks, bench);
	}
}

static void	sort_five(t_stacks *stacks, int size, t_bench *bench)
{
	while (stacks->a)
	{
		if (stacks->a->index == 0)
		{
			pb(stacks, bench);
			break ;
		}
		ra(stacks, bench);
	}
	if (size != 4)
	{
		while (stacks->a)
		{
			if (stacks->a->index == 1)
			{
				pb(stacks, bench);
				break ;
			}
			ra(stacks, bench);
		}
	}
	sort_three(stacks, bench);
	while (stacks->b)
		pa(stacks, bench);
}

void	adaptive_sort(t_stacks *stacks, int size, float disorder,
	t_bench *bench)
{
	if (size < 2)
		return ;
	else if (size == 2)
	{
		if (stacks->a->index > stacks->a->next->index)
			sa(stacks, bench);
		return ;
	}
	else if (size == 3)
		sort_three(stacks, bench);
	else if (size == 4 || size == 5)
		sort_five(stacks, size, bench);
	else if (disorder < 0.2)
		insertion_sort(stacks, bench);
	else if (disorder < 0.5)
		bucket_sort(stacks, size, bench);
	else
		radix_sort(stacks, size, bench);
}
