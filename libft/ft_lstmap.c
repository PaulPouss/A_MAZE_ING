/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aunoguei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 10:22:48 by aunoguei          #+#    #+#             */
/*   Updated: 2026/01/22 16:14:05 by aunoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlist;
	t_list	*newnode;
	void	*content;

	if (!lst || !f || !del)
		return (NULL);
	newlist = NULL;
	while (lst)
	{
		content = f(lst->content);
		newnode = ft_lstnew(content);
		if (!newnode)
		{
			del(content);
			ft_lstclear(&newlist, del);
			return (NULL);
		}
		ft_lstadd_back(&newlist, newnode);
		lst = lst->next;
	}
	return (newlist);
}
/*
#include "libft.h"
#include <stdio.h>

void    delete(void *content)
{
        free(content);
}

void    *transform(void *content)
{
        size_t  i;
        unsigned char   *str;
        unsigned char   *new;

        str = (unsigned char *)content;
        str = ft_strdup(str);
        if (!str)
                return (NULL);
        i = 0;
        while (str[i])
        {
                if (str[i] >= 'a' || str[i] <= 'z')
                        str[i] -= 32;
                i++;
        }
        return ((void *)str);
}

int     main(void)
{
        t_list  *list;
        t_list  *new;

        list = NULL;
        ft_lstadd_back(&list, ft_lstnew(ft_strdup("node1")));
        ft_lstadd_back(&list, ft_lstnew(ft_strdup("node2")));
        ft_lstadd_back(&list, ft_lstnew(ft_strdup("node3")));
        new = ft_lstmap(list, transform, delete);
        printf("first node list : %s\n", (char *)list->content);
        printf("first node NEW list : %s\n", (char *)new->content);
        ft_lstclear(&list, delete);
        ft_lstclear(&new, delete);
        return (0);
}*/
