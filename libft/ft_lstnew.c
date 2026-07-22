/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aunoguei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 14:58:11 by aunoguei          #+#    #+#             */
/*   Updated: 2026/01/21 15:16:07 by aunoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*ptr;

	ptr = malloc(sizeof(t_list));
	if (!ptr)
		return (NULL);
	ptr->content = content;
	ptr->next = NULL;
	return (ptr);
}
/*
int main(void)
{
	t_list	*node1;
	t_list  *node2;
	t_list  *node3;

	node1 = ft_lstnew("node 1\0");
	node2 = ft_lstnew("node 2\0");
	node3 = ft_lstnew("node 3\0");

	printf("1) : %s", (char *)node1->content);
	printf("2) : %s", (char *)node2->content);
	printf("3) : %s", (char *)node3->content);
	return (0);
}*/
