/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aunoguei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 09:32:57 by aunoguei          #+#    #+#             */
/*   Updated: 2026/01/22 15:53:01 by aunoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = temp;
	}
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

        list = NULL;
        ft_lstadd_back(&list, ft_lstnew(ft_strdup("node 1")));
        ft_lstadd_back(&list, ft_lstnew(ft_strdup("node 2")));
        ft_lstadd_back(&list, ft_lstnew(ft_strdup("node 3")));
        printf("first node list before cleaning : %s\n", (char *)list->content);
        ft_lstclear(&list, delete);
        if (list == NULL)
                printf("after cleaning : SUCCESS, list is null");
        else
                printf("not NULL");
        return (0);
}
*/
