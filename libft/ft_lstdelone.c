/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aunoguei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 09:25:13 by aunoguei          #+#    #+#             */
/*   Updated: 2026/01/22 15:46:21 by aunoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}
/*
#include "libft.h"
#include <stdio.h>

void    delete(void *content)
{
        free(content);
}

int     main(void)
{
        t_list  *list;
        t_list  *first;
        t_list  *second;
        t_list  *third;

        list = NULL;

        first = ft_lstnew(ft_strdup("node 1"));
        second = ft_lstnew(ft_strdup("node 2"));
        third = ft_lstnew(ft_strdup("node 3"));

        ft_lstadd_back(&list, first);
        ft_lstadd_back(&list, second);
        ft_lstadd_back(&list, third);
        ft_lstdelone(second, delete);

        printf("first : %s\n", (char *)first->content);
        if (second == NULL)
                printf("second : %s\n", (char *)second->content);
        else
                printf("nothing there\n");
        printf("third : %s\n", (char *)first->content);
        ft_lstdelone(first, delete);
        ft_lstdelone(third, delete);
        return (0);
}
*/
