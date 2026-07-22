/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_convertion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppousser <ppousser@student.42urduliz.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 11:08:39 by ppousser          #+#    #+#             */
/*   Updated: 2026/02/19 11:08:43 by ppousser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_word(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] != ' ' && ((i == 0) || (str[i - 1] == ' ')))
			count++;
		i++;
	}
	return (count);
}

static int	count_size_total(int size, char **argv)
{
	int	i;
	int	count;

	i = 0;
	count = 1;
	while (i < size)
	{
		count = count + count_word(argv[i]);
		i++;
	}
	return (count);
}

static int	assign_str_split(char **res, char *str)
{
	int		i;
	char	**temp;

	i = 0;
	temp = ft_split(str, ' ');
	if (!temp)
		return (0);
	while (temp[i] != NULL)
	{
		res[i] = ft_strdup(temp[i]);
		i++;
	}
	i = 0;
	while (temp[i] != NULL)
	{
		free(temp[i]);
		i++;
	}
	free(temp);
	return (i);
}

char	**convert_input(int size, char **argv, int *size_final)
{
	int		i;
	int		j;
	char	**res;

	j = count_size_total(size, argv);
	i = 0;
	res = malloc((j + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	j = 0;
	while (i < size)
	{
		if (count_word(argv[i]) == 1)
		{
			res[j] = ft_strdup(argv[i]);
			j++;
		}
		else
			j = j + assign_str_split(&res[j], argv[i]);
		i++;
	}
	res[j] = NULL;
	*size_final = j;
	return (res);
}
