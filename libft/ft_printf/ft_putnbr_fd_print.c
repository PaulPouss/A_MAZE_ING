/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd_print.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aunoguei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 13:50:17 by aunoguei          #+#    #+#             */
/*   Updated: 2026/02/11 10:31:47 by aunoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_printnbr(long n, int fd)
{
	long		i;
	char		digits[32];
	int			count;

	i = 0;
	count = 0;
	while (n > 0)
	{
		digits[i] = (n % 10) + '0';
		n /= 10;
		i++;
	}
	i--;
	while (i >= 0)
	{
		write(fd, &(digits[i]), 1);
		count++;
		i--;
	}
	return (count);
}

int	ft_putnbr_fd_print(int n, int fd)
{
	long	number;
	int		count;

	if (n == 0)
	{
		write(fd, "0", 1);
		return (1);
	}
	number = n;
	count = 0;
	if (number < 0)
	{
		write(fd, "-", 1);
		number *= -1;
		count++;
	}
	count += ft_printnbr(number, fd);
	return (count);
}
