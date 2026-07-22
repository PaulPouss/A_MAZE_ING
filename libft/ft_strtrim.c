/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aunoguei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 10:53:06 by aunoguei          #+#    #+#             */
/*   Updated: 2026/01/15 07:54:15 by aunoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	i;
	size_t	end;

	if (!s1 || !set)
		return (NULL);
	end = ft_strlen(s1);
	i = 0;
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	while (i < end && ft_strchr(set, s1[end - 1]))
		end--;
	str = ft_substr(s1, i, end - i);
	return (str);
}
/*
#include <stdio.h>
int	main(void)
{
	char *str = ft_strtrim("hello", "eo");
	printf("%s", str);
	free(str);
	return (0);
}*/
