/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppousser <ppousser@student.42urduliz.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 11:11:26 by ppousser          #+#    #+#             */
/*   Updated: 2026/02/19 11:11:28 by ppousser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	extract_commands(char *input, t_command *commands)
{
	if (ft_strncmp(input, "--bench", 7) == 0)
	{
		commands->bench = commands->bench + 1;
		if (commands->bench != 1)
			return (0);
	}
	else
	{
		if (commands->strategy != NULL)
			return (0);
		commands->strategy = ft_strdup(input);
	}
	return (1);
}

int	calcul_size_numb(char **input)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (input[i])
	{
		if (ft_is_str_int(input[i]) != 1)
			count++;
		i++;
	}
	return (count);
}

char	**extract_numbers(int *size, char **input, t_command commands)
{
	int		i;
	int		j;
	char	**res;

	i = 0;
	j = 0;
	*size = *size - calcul_size_numb(input);
	if (*size == 0)
		write (2, "Error\n", 6);
	res = malloc ((*size + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	while (input[i])
	{
		if (ft_is_str_int(input[i]) == 1)
		{
			res[j] = ft_strdup(input[i]);
			j++;
		}
		i++;
	}
	free_input(input, *size, commands);
	return (res);
}

char	**manage_input(int argc, char **argv, int *size, t_command *commands)
{
	char	**res_final;
	int		i;

	i = 0;
	res_final = NULL;
	res_final = (convert_input(argc, argv, size));
	if (!res_final)
		return (NULL);
	if (ft_is_input_valid(res_final, commands) == 0)
	{
		while (i < *size)
		{
			free(res_final[i]);
			i++;
		}
		free(res_final);
		write (2, "Error\n", 6);
		res_final = NULL;
	}
	return (res_final);
}

int	is_bucket_needed(t_numbers_list *stacksa, int min_bucket, int max_bucket)
{
	t_numbers_list	*temp;
	int				count;

	count = 0;
	if (stacksa == NULL)
		return (0);
	temp = stacksa;
	while (temp != NULL)
	{
		if (temp->index >= min_bucket && temp->index < max_bucket)
			count++;
		temp = temp->next;
	}
	return (count);
}
