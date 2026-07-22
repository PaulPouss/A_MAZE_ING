/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aunoguei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 09:21:27 by aunoguei          #+#    #+#             */
/*   Updated: 2026/01/22 11:15:31 by aunoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	k;

	i = 0;
	k = 0;
	if (!*little)
		return ((char *)big);
	while (big[i] && i < len)
	{
		while (big[i] == little[k] && i < len)
		{
			i++;
			k++;
		}
		if (little[k] == '\0')
			return ((char *)&big[i - k]);
		i = (i - k);
		k = 0;
		i++;
	}
	return (NULL);
}
/*
#include <stdio.h>

int     main(void)
{
        char    *str = "helloworld";
        char    *str1 = "world";
        printf("%s", ft_strnstr(str, str1, 10));
        return (0);
}*/
