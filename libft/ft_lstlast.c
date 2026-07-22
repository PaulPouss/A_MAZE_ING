/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aunoguei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 16:56:36 by aunoguei          #+#    #+#             */
/*   Updated: 2026/01/21 15:38:36 by aunoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
/*
int     main(void)
{
        t_list  *list;
        t_list  *last;

        list = NULL;
        ft_lstadd_back(&list, ft_lstnew("node 1"));
        ft_lstadd_back(&list, ft_lstnew("node 2"));
        ft_lstadd_back(&list, ft_lstnew("node 3"));
        last = ft_lstlast(list);
        if (last)
                printf("%s \n", (char *)last->content);
        return (0);
}
*/
