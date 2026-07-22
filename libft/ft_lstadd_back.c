/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aunoguei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 09:21:17 by aunoguei          #+#    #+#             */
/*   Updated: 2026/01/22 08:42:31 by aunoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!lst || !new)
		return ;
	new->next = NULL;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = new;
}
/*
int     main(void)
{
        t_list  *list;
        t_list  *last;


        list = NULL;
        ft_lstadd_back(&list, ft_lstnew("node 1\0"));
        ft_lstadd_back(&list, ft_lstnew("node 2\0"));
        ft_lstadd_back(&list, ft_lstnew("node 3\0"));
        last = ft_lstlast(list);
        if (last && list)
                printf("last : %s\n", (char *)last->content);
        return (0);
}
*/
