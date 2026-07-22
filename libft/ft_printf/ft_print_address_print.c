/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_address_print.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aunoguei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 13:07:31 by aunoguei          #+#    #+#             */
/*   Updated: 2026/02/11 10:28:12 by aunoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	putnbr_hex_long(unsigned long n, char *base)
{
	unsigned long	numbers[32];
	int				i;
	int				count;

	if (n == 0)
		return (write(1, "0", 1));
	i = 0;
	count = 0;
	while (n > 0)
	{
		numbers[i] = (n % 16);
		n /= 16;
		count++;
		i++;
	}
	i--;
	while (i > 0)
	{
		write(1, &base[numbers[i]], 1);
		i--;
	}
	write(1, &base[numbers[i]], 1);
	return (count);
}

int	ft_print_address_print(void *ptr, int fd)
{
	int					count;
	unsigned long		address;

	if (!ptr)
	{
		write(fd, "(nil)", 5);
		return (5);
	}
	address = (unsigned long)ptr;
	write(fd, "0x", 2);
	count = 2;
	count += putnbr_hex_long(address, "0123456789abcdef");
	return (count);
}
