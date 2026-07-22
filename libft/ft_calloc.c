/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aunoguei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 16:05:23 by aunoguei          #+#    #+#             */
/*   Updated: 2026/01/15 08:19:13 by aunoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void			*ptr;
	unsigned char	*str;
	size_t			i;

	if (nmemb == 0 || size == 0)
	{
		return (malloc(0));
	}
	if (nmemb > SIZE_MAX / size)
		return (0);
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (0);
	str = ptr;
	i = 0;
	while (i < nmemb * size)
		str[i++] = '\0';
	return ((void *)ptr);
}
/*
#include <stdio.h>

int	main(void)
{
	int	*ptr;
	size_t	i;

	ptr = ft_calloc(3, sizeof(int));
	if (!ptr)
		return (0);
	i = 0;
	while (i < 3)
	{
		printf("%d", ptr[i]);
		i++;
	}
	free(ptr);
	return (0);
}*/
