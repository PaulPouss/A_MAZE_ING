/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aunoguei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 12:13:04 by aunoguei          #+#    #+#             */
/*   Updated: 2026/01/15 08:15:14 by aunoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*buffer;

	i = 0;
	buffer = s;
	while (i < n)
		buffer[i++] = '\0';
}
/*
#include <stdio.h>

int     main(void)
{
        char	dest[10] = "hello";
        ft_bzero(dest, 1);
        printf("%s", &dest[0]);
        return (0);
}*/
