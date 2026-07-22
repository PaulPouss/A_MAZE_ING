/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aunoguei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 16:35:57 by aunoguei          #+#    #+#             */
/*   Updated: 2026/01/19 10:07:01 by aunoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	size_t	length;
	char	*str;

	if (!s || !f)
		return (NULL);
	length = ft_strlen(s);
	str = ft_calloc((length + 1), sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (s[i])
	{
		str[i] = f(i, s[i]);
		i++;
	}
	return (str);
}
/*
int     main(void)
{
        char sumarASCII(unsigned int number, char c)
        {
                return (number + c);
        }
        char (*ptr)(unsigned int,  char) = &sumarASCII;
        char *str = ft_strmapi("hello world\0", ptr);
        printf("%s", str);
        free(str);
        return (0);
}*/
