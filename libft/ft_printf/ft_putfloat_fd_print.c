/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putfloat_fd_print.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aunoguei <aunoguei@student.42urduliz.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 14:12:33 by aunoguei          #+#    #+#             */
/*   Updated: 2026/02/18 15:24:41 by aunoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_decimal(double number, int fd)
{
	double	a;
	char	c_a;
	double	b;
	char	c_b;

	a = (number * 10);
	c_a = (int)a % 10 + '0';
	b = (number * 100);
	c_b = (int)b % 10 + '0';
	write(fd, &c_a, 1);
	write(fd, &c_b, 1);
	return (2);
}

int	ft_printfloat_fd_print(double number, int fd)
{
	int	count;
	int	num;

	count = 0;
	num = (int)number;
	count += ft_putnbr_fd_print(num, fd);
	count += write(fd, ".", 1);
	count += print_decimal(number, fd);
	return (count);
}
