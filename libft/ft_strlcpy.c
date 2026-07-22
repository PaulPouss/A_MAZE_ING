/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aunoguei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 13:38:22 by aunoguei          #+#    #+#             */
/*   Updated: 2026/01/15 10:13:14 by aunoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	length;
	size_t	i;

	length = ft_strlen(src);
	if (size == 0)
		return (length);
	i = 0;
	while (src[i] && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (length);
}
/*
#include <unistd.h>
#include <stdio.h>
int     main(void)
{
        char    array[100];
        char    *dest = array;
        char    *src = "je suis un test464";
        unsigned int    size;
        int     i;
        size = 19;
        ft_strlcpy(dest, src, size);
        i = 0;
        while (dest[i] != '\0')
        {
                write(1, &dest[i],1);
                i++;
        }
	printf("\n%ld", ft_strlcpy(dest, src, size));
        return (0);
}
*/
