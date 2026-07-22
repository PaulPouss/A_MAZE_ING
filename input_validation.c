/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppousser <ppousser@student.42urduliz.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 11:09:42 by ppousser          #+#    #+#             */
/*   Updated: 2026/02/19 11:09:45 by ppousser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_is_command(char *str)
{
	if (ft_strncmp(str, "--simple", 8) == 0 && ft_strlen(str) == 8)
		return (1);
	else if (ft_strncmp(str, "--medium", 8) == 0 && ft_strlen(str) == 8)
		return (1);
	else if (ft_strncmp(str, "--complex", 9) == 0 && ft_strlen(str) == 9)
		return (1);
	else if (ft_strncmp(str, "--adaptive", 10) == 0 && ft_strlen(str) == 10)
		return (1);
	else if (ft_strncmp(str, "--bench", 7) == 0 && ft_strlen(str) == 7)
		return (1);
	else
		return (0);
}

int	ft_is_str_int(char *src)
{
	int	i;

	i = 0;
	if (src[i] == '-')
		i++;
	while (src[i] != '\0')
	{
		if (ft_isdigit(src[i]) != 1)
			return (0);
		i++;
	}
	if ((ft_atoi(src) > INT_MAX) || (ft_atoi(src) < INT_MIN))
		return (0);
	return (1);
}

static int	ft_is_repetition(char **str)
{
	int	i;
	int	j;

	i = 1;
	j = 1;
	while (str[i])
	{
		if (ft_is_command(str[i]) == 0)
		{
			j = i + 1;
			while (str[j])
			{
				if (ft_is_command(str[j]) == 0)
				{
					if (ft_atoi(str[i]) == ft_atoi(str[j]))
						return (0);
				}
				j++;
			}
		}
		i++;
	}
	return (1);
}

int	ft_is_input_valid(char **str, t_command *commands)
{
	int	i;

	i = 1;
	while (str[i])
	{
		if (ft_is_str_int(str[i]) == 1)
			i++;
		else if (ft_is_command(str[i]) == 1)
		{
			if (extract_commands(str[i], commands) == 0)
				return (0);
			i++;
		}
		else
			return (0);
	}
	if (ft_is_repetition(str) != 1)
		return (0);
	return (1);
}
