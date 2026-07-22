/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aunoguei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 11:43:03 by aunoguei          #+#    #+#             */
/*   Updated: 2026/01/21 12:26:55 by aunoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (1);
	return (0);
}

/*
#include <stdio.h>
int     main(void)
{
        printf("que retorna space : %d", ft_isalnum(' '));
        printf("que retorna a : %d", ft_isalnum('a'));
        printf("que retorna B : %d", ft_isalnum('B'));
        return (0);
}
*/
