/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_selection.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppousser <ppousser@student.42urduliz.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 11:07:16 by ppousser          #+#    #+#             */
/*   Updated: 2026/02/19 11:07:22 by ppousser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_bench	init_bench(t_command cmds)
{
	t_bench	bench;

	bench.bench = cmds.bench;
	bench.total = 0;
	bench.sa = 0;
	bench.sb = 0;
	bench.ss = 0;
	bench.pa = 0;
	bench.pb = 0;
	bench.ra = 0;
	bench.rb = 0;
	bench.rr = 0;
	bench.rra = 0;
	bench.rrb = 0;
	bench.rrr = 0;
	return (bench);
}

void	print_strategy(t_command *cmds, float disorder)
{
	if (cmds->strategy == NULL || ft_strlen(cmds->strategy) == 10)
	{
		if (disorder < 0.2)
		{
			ft_printf(2, "[bench] strategy: Adaptive / O(n^2)\n");
			return ;
		}
		else if (disorder < 0.5)
		{
			ft_printf(2, "[bench] strategy: Adaptive / O(n√n)\n");
			return ;
		}
		else
			ft_printf(2, "[bench] strategy: Adaptive / O(n log n)\n");
	}
	else if (ft_strlen(cmds->strategy) == 9)
		ft_printf(2, "[bench] strategy: Complex / O(n log n)\n");
	else
	{
		if (ft_strncmp(cmds->strategy, "--simple", 8) == 0)
			ft_printf(2, "[bench] strategy: Simple / O(n^2)\n");
		else
			ft_printf(2, "[bench] strategy: Medium / O(n√n)\n");
	}
}

void	print_bench(t_command cmds, t_bench bench, float disorder)
{
	float	percent;

	percent = disorder * 100;
	ft_printf(2, "[bench] disorder: %f%\n", (double)percent);
	print_strategy(&cmds, disorder);
	ft_printf(2, "[bench] total_ops: %d\n", bench.total);
	ft_printf(2, "[bench] sa: %d sb: %d ss: %d pa: %d pb: %d\n",
		bench.sa, bench.sb, bench.ss, bench.pa, bench.pb);
	ft_printf(2, "[bench] ra: %d rb: %d rr: %d rra: %d rrb: %d rrr: %d\n",
		bench.ra, bench.rb, bench.rr, bench.rra, bench.rrb, bench.rrr);
}

void	select_algorithm(t_stacks *stacks, int size, t_command cmds)
{
	float	disorder;
	t_bench	bench;

	disorder = compute_disorder(size, stacks->a);
	bench = init_bench(cmds);
	if (disorder != 0)
	{
		if (cmds.strategy == NULL || ft_strlen(cmds.strategy) == 10)
			adaptive_sort(stacks, size, disorder, &bench);
		else
		{
			if (ft_strlen(cmds.strategy) == 9)
				radix_sort(stacks, size, &bench);
			else if (ft_strlen(cmds.strategy) == 8)
			{
				if (ft_strncmp(cmds.strategy, "--simple", 8) == 0)
					insertion_sort(stacks, &bench);
				else
					bucket_sort(stacks, size, &bench);
			}
		}
	}
	if (bench.bench == 1)
		print_bench(cmds, bench, disorder);
}
