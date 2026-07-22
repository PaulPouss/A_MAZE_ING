/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aunoguei <aunoguei@student.42urduliz.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 10:09:36 by aunoguei          #+#    #+#             */
/*   Updated: 2026/02/18 14:18:32 by aunoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stacks *stacks, t_bench *bench)
{
	rotate(&stacks->a);
	write(1, "ra\n", 3);
	bench->ra += 1;
	bench->total += 1;
}

void	rb(t_stacks *stacks, t_bench *bench)
{
	rotate(&stacks->b);
	write(1, "rb\n", 3);
	bench->rb += 1;
	bench->total += 1;
}

void	rr(t_stacks *stacks, t_bench *bench)
{
	rotate(&stacks->a);
	rotate(&stacks->b);
	write(1, "rr\n", 3);
	bench->rrr += 1;
	bench->total += 1;
}
