/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aunoguei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 13:33:32 by aunoguei          #+#    #+#             */
/*   Updated: 2026/01/22 12:19:50 by aunoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *str, char c)
{
	size_t	i;
	size_t	words;

	i = 0;
	words = 0;
	while (str[i])
	{
		if (str[i] != c && (i == 0 || str[i - 1] == c))
			words++;
		i++;
	}
	return (words);
}

char	**split_words(char **ptr, char const *s, char c, size_t words)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
		{
			j = i;
			while (s[j] != c && s[j] != '\0')
				j++;
			ptr[words] = (char *)ft_substr((char *)s, i, j - i);
			if (!ptr[words])
			{
				i = 0;
				while (ptr[i])
					free(ptr[i++]);
				free(ptr);
				return (NULL);
			}
			words++;
		}
		i++;
	}
	return (ptr);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	size_t	words;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	ptr = ft_calloc(words + 1, sizeof(char *));
	if (!ptr)
		return (NULL);
	words = 0;
	return (split_words(ptr, s, c, words));
}
/*
#include <stddef.h>
#include "libft.h"
#include <stdio.h>

int     main(void)
int     main(void)
{
        char **str = ft_split("hello world hola mundo", ' ');
        size_t i = 0;

        while (str[i])
        {
                printf("%s", str[i]);
                free(str[i]);
                i++;
        }
        free(str);
        return (0);
}

*/
