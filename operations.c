/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aunoguei <aunoguei@student.42urduliz.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 10:00:24 by aunoguei          #+#    #+#             */
/*   Updated: 2026/02/18 14:17:33 by aunoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stacks *stacks, t_bench *bench)
{
	swap(&stacks->a);
	write(1, "sa\n", 3);
	bench->sa += 1;
	bench->total += 1;
}

void	sb(t_stacks *stacks, t_bench *bench)
{
	swap(&stacks->b);
	write(1, "sb\n", 3);
	bench->sb += 1;
	bench->total += 1;
}

void	ss(t_stacks *stacks, t_bench *bench)
{
	swap(&stacks->a);
	swap(&stacks->b);
	write(1, "ss\n", 3);
	bench->ss += 1;
	bench->total += 1;
}

void	pa(t_stacks *stacks, t_bench *bench)
{
	push(&stacks->b, &stacks->a);
	write(1, "pa\n", 3);
	bench->pa += 1;
	bench->total += 1;
}

void	pb(t_stacks *stacks, t_bench *bench)
{
	push(&stacks->a, &stacks->b);
	write(1, "pb\n", 3);
	bench->pb += 1;
	bench->total += 1;
}
