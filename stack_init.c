/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aunoguei <aunoguei@student.42urduliz.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 15:09:03 by aunoguei          #+#    #+#             */
/*   Updated: 2026/02/17 11:50:58 by aunoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*copy_to_array(char **numbers, int size)
{
	int	*copy;
	int	i;

	copy = malloc(size * sizeof(int));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < size)
	{
		copy[i] = (int)ft_atoi(numbers[i]);
		i++;
	}
	return (copy);
}

static void	add_index(t_numbers_list *stack_a, int *ordered, int size)
{
	int				i;
	t_numbers_list	*node;

	node = stack_a;
	while (node)
	{
		i = 0;
		while (i < size)
		{
			if (ordered[i] == node->content)
			{
				node->index = i;
			}
			i++;
		}
		node = node->next;
	}
}

static int	assign_index(t_numbers_list *stack_a, char **numbers, int size)
{
	int	*ordered;

	ordered = copy_to_array(numbers, size);
	if (!ordered)
		return (0);
	if (size < 100)
		bubblesort(ordered, size);
	else
		quicksort(ordered, 0, size - 1);
	add_index(stack_a, ordered, size);
	free(ordered);
	return (1);
}

static t_numbers_list	*init_stack_a(int size, char **numbers)
{
	int				i;
	int				num;
	t_numbers_list	*node;
	t_numbers_list	*stack_a;

	i = 0;
	stack_a = NULL;
	node = NULL;
	while (i < size)
	{
		num = (int)ft_atoi(numbers[i]);
		node = numbers_lstnew(num);
		if (!node)
		{
			clear_lst_numbers(&stack_a);
			return (NULL);
		}
		numbers_lstadd_back(&stack_a, node);
		i++;
	}
	return (stack_a);
}

t_stacks	*init_stacks(int size, char **argv)
{
	t_stacks	*stacks;

	stacks = malloc(1 * sizeof(t_stacks));
	if (!stacks)
		return (NULL);
	stacks->a = init_stack_a(size, argv);
	if (!stacks->a)
	{
		free(stacks);
		return (NULL);
	}
	assign_index(stacks->a, argv, size);
	if (!assign_index(stacks->a, argv, size))
	{
		free(stacks);
		return (NULL);
	}
	stacks->b = NULL;
	return (stacks);
}
