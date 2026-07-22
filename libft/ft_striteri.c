/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aunoguei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 10:13:25 by aunoguei          #+#    #+#             */
/*   Updated: 2026/01/19 12:31:01 by aunoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
/*
int     main(void)
{
        void to_upper_even(unsigned int number, char *c)
        {
                if (number % 2 == 0 && *c >= 'a' && *c <= 'z')
                                *c -= 32;
        }
        char str[] = "hello2 world";
        void (*ptr)(unsigned int, char *) = &to_upper_even;
        ft_striteri(str, ptr);
        printf("%s", str);
        return (0);
}*/
