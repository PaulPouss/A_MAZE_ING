/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aunoguei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 10:51:00 by aunoguei          #+#    #+#             */
/*   Updated: 2026/01/21 12:38:01 by aunoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_islower(int c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	return (0);
}

static int	ft_isupper(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}

int	ft_isalpha(int c)
{
	if (ft_isupper(c) || ft_islower(c))
		return (1);
	return (0);
}
/*
#include <stdio.h>
int	main(void)
{
	printf("Isalpha? retorno para 8 : %d / ", ft_isalpha(8));
	printf("retorno para 'a' : %d / ", ft_isalpha('a'));
	printf("retorna para 'B' : %d / ", ft_isalpha('B'));
	printf("retorna space : %d \n", ft_isalpha(' '));
	return (0);
}*/
