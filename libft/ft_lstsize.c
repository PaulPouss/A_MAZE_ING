/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aunoguei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 16:35:29 by aunoguei          #+#    #+#             */
/*   Updated: 2026/01/21 15:34:26 by aunoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	size_t	i;

	if (!lst)
		return (0);
	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
/*
int	main(void)
{
        t_list  *list;
        t_list  *node1;
        t_list  *node2;
        t_list  *node3;

        list = NULL;
        node1 = ft_lstnew("node 1\0");
        node2 = ft_lstnew("node 2\0");
        node3 = ft_lstnew("node 3\0");
        ft_lstadd_front(&list, node1);
        ft_lstadd_front(&list, node2);
        ft_lstadd_front(&list, node3);
        printf("list size : %d\n", ft_lstsize(list));
        return (0);
}*/
