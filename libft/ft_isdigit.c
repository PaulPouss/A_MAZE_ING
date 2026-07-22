/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aunoguei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 11:37:33 by aunoguei          #+#    #+#             */
/*   Updated: 2026/01/21 12:38:24 by aunoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
/*
#include <stdio.h>
int	main(void)
{
	printf("isdigit? retorno para '8' : %d", ft_isdigit('8'));
	printf("retorno 'a' para : %d", ft_isdigit('a'));
	printf("retorno '/' para: %d\n", ft_isdigit('/'));
	return (0);
}*/
