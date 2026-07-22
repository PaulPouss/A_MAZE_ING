/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aunoguei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 13:57:47 by aunoguei          #+#    #+#             */
/*   Updated: 2026/01/22 09:28:22 by aunoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	k;
	size_t	i;

	dest_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (size <= dest_len)
		return (size + src_len);
	i = dest_len;
	k = 0;
	while (i < size - 1 && src[k] != '\0')
	{
		dst[i] = src[k];
		i++;
		k++;
	}
	dst[i] = '\0';
	return (src_len + dest_len);
}
/*
#include <stdio.h>
int     main(void)
{
        char    string[] = "hello";
        char    string2[] = " world";

        printf("%ld\n", ft_strlcat(string, string2, (unsigned int)3));
        printf("%s", string);
        return (0);
}*/
