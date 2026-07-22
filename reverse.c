/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aunoguei <aunoguei@student.42urduliz.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 10:13:36 by aunoguei          #+#    #+#             */
/*   Updated: 2026/02/18 14:19:33 by aunoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stacks *stacks, t_bench *bench)
{
	reverse(&stacks->a);
	write(1, "rra\n", 4);
	bench->rra += 1;
	bench->total += 1;
}

void	rrb(t_stacks *stacks, t_bench *bench)
{
	reverse(&stacks->b);
	write(1, "rrb\n", 4);
	bench->rrb += 1;
	bench->total += 1;
}

void	rrr(t_stacks *stacks, t_bench *bench)
{
	reverse(&stacks->a);
	reverse(&stacks->b);
	write(1, "rrr\n", 4);
	bench->rrr += 1;
	bench->total += 1;
}
