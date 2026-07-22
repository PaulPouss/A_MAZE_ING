/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aunoguei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 11:59:20 by aunoguei          #+#    #+#             */
/*   Updated: 2026/01/22 16:47:34 by aunoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*destcpy;
	size_t				i;

	if (dest == src || n == 0)
		return (dest);
	destcpy = (unsigned char *)dest;
	if (dest < src)
	{
		i = 0;
		while (i < n)
		{
			destcpy[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	else
	{
		while (n > 0)
		{
			n--;
			destcpy[n] = ((unsigned char *)src)[n];
		}
	}
	return (dest);
}
/*
#include "libft.h"
#include <stdio.h>

int     main(void)
{
        char    src[12] = "abcdefgh";
        char    dest[12] = "hola-mundo";
        char    orisrc[12] = "abcdefgh";
        char    oridest[12] = "hola-mundo";

        printf("before FT: %s\n", src);
        ft_memmove(src+2, dest+3, 9);
        printf("after FT: %s", src);
        printf("\nbefore ORIGINAL: %s\n", orisrc);
        memmove(orisrc+2, oridest+3, 9);
        printf("after ORIGINAL: %s", orisrc);
        return (0);
}
*/
