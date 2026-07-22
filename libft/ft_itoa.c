/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aunoguei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 15:18:05 by aunoguei          #+#    #+#             */
/*   Updated: 2026/01/16 16:27:56 by aunoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	countdigits(long n)
{
	long	length;

	length = 0;
	if (n < 0)
	{
		n = -n;
		length++;
	}
	while (n >= 10)
	{
		length++;
		n /= 10;
	}
	return (length + 1);
}

static char	*fillstr(char *ptr, long num, int length)
{
	int	i;

	if (num < 0)
	{
		ptr[0] = '-';
		num *= -1;
		i = 1;
	}
	else
		i = 0;
	while (length > i)
	{
		ptr[length - 1] = num % 10 + '0';
		num /= 10;
		length--;
	}
	return (ptr);
}

char	*ft_itoa(int n)
{
	char	*ptr;
	int		length;
	long	num;

	if (n == 0)
		return (ft_strdup("0"));
	num = n;
	length = countdigits(n);
	ptr = ft_calloc(length + 1, sizeof(char));
	if (!ptr)
		return (NULL);
	fillstr(ptr, num, length);
	return (ptr);
}
/*
#include <limits.h>

int     main(void)
{
        char    *ptr;

        ptr = ft_itoa(INT_MIN);
        printf("%s", ptr);
        free(ptr);
        return (0);
}
*/
