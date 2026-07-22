/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aunoguei <aunoguei@student.42urduliz.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 17:54:50 by aunoguei          #+#    #+#             */
/*   Updated: 2026/02/11 15:31:38 by aunoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	numbers_lstadd_front(t_numbers_list **lst, t_numbers_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

void	numbers_lstadd_back(t_numbers_list **lst, t_numbers_list *new)
{
	t_numbers_list	*last;

	if (!lst || !new)
		return ;
	new->next = NULL;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last = numbers_lstlast(*lst);
	last->next = new;
}

t_numbers_list	*numbers_lstnew(int content)
{
	t_numbers_list	*ptr;

	ptr = malloc(sizeof(t_numbers_list));
	if (!ptr)
		return (NULL);
	ptr->content = content;
	ptr->next = NULL;
	return (ptr);
}

t_numbers_list	*numbers_lstlast(t_numbers_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
