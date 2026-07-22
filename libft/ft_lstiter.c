/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aunoguei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 09:49:02 by aunoguei          #+#    #+#             */
/*   Updated: 2026/01/22 16:28:25 by aunoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*ptr;

	if (!lst || !f)
		return ;
	ptr = lst;
	while (ptr)
	{
		f(ptr->content);
		ptr = ptr->next;
	}
}
/*
#include "libft.h"
#include <stdio.h>

void    delete(void *content)
{
        free(content);
}

void    transform(void *content)
{
        size_t  i;
        unsigned char *str;
        str = (unsigned char *)content;
        i = 0;
        while (str[i])
        {
                if (str[i] >= 'a' || str[i] <= 'z')
                        str[i] -= 32;
                i++;
        }
}

int     main(void)
{
        t_list  *list;

        list = NULL;
        ft_lstadd_back(&list, ft_lstnew(ft_strdup("node1")));
        ft_lstadd_back(&list, ft_lstnew(ft_strdup("node2")));
        ft_lstadd_back(&list, ft_lstnew(ft_strdup("node3")));
        printf("before transform list : %s\n", (char *)list->content);
        ft_lstiter(list, transform);
        printf("after transform list : %s\n", (char *)list->content);
        ft_lstclear(&list, delete);
        return (0);
}
*/
