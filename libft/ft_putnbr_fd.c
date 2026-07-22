/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aunoguei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 13:50:17 by aunoguei          #+#    #+#             */
/*   Updated: 2026/01/20 09:03:14 by aunoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_printnbr(long n, int fd)
{
	long	i;
	char	digits[20];

	i = 0;
	while (n > 0)
	{
		digits[i] = (n % 10) + '0';
		n /= 10;
		i++;
	}
	while (i-- > 0)
		write(fd, &(digits[i]), 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	long	number;

	if (n == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	number = n;
	if (number < 0)
	{
		write(fd, "-", 1);
		number *= -1;
	}
	ft_printnbr(number, fd);
}
