/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd_print.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aunoguei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 14:17:20 by aunoguei          #+#    #+#             */
/*   Updated: 2026/02/18 13:30:46 by aunoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_fd_print(char *s, int fd)
{
	size_t	i;
	int		count;

	if (!s)
	{
		write(fd, "(null)", 6);
		return (6);
	}
	i = 0;
	count = 0;
	while (s[i])
	{
		write (fd, &s[i], 1);
		count++;
		i++;
	}
	return (count);
}
