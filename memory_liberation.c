/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_liberation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aunoguei <aunoguei@student.42urduliz.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 13:28:59 by aunoguei          #+#    #+#             */
/*   Updated: 2026/02/18 14:28:23 by ppousser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	clear_all(t_numbers_list **stacks, t_command *commands)
{
	clear_lst_numbers(stacks);
	free(stacks);
	free(commands->strategy);
}

void	clear_lst_numbers(t_numbers_list **lst)
{
	t_numbers_list	*temp;

	if (!lst)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		free(*lst);
		*lst = temp;
	}
}

void	free_input(char **input, int size, t_command commands)
{
	int	i;

	i = 0;
	if (commands.bench == 1)
		size++;
	if (commands.strategy != NULL)
		size++;
	while (i < (size + 1))
	{
		free(input[i]);
		i++;
	}
	free(input);
}
