/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aunoguei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 18:07:11 by aunoguei          #+#    #+#             */
/*   Updated: 2026/01/22 10:11:06 by aunoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	if (c == '\0')
		return ((char *) &s[i]);
	while (i >= 0)
	{
		if (s[i] == (const char)c)
			return ((char *) &s[i]);
		i--;
	}
	return (NULL);
}
/*
#include <stdio.h>

int     main(void)
{
        char *str = ft_strrchr("hello", 'e');
                printf("%c", *str);
        return (0);
}*/
