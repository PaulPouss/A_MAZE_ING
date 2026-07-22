/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aunoguei <aunoguei@student.42urduliz.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 16:38:04 by aunoguei          #+#    #+#             */
/*   Updated: 2026/02/11 13:08:18 by aunoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_numbers_list **stack)
{
	t_numbers_list	*temp_a;
	t_numbers_list	*temp_b;

	if (!stack || !(*stack) || !((*stack)->next))
		return ;
	temp_a = *stack;
	temp_b = (*stack)->next;
	(*stack)->next = temp_b->next;
	temp_b->next = temp_a;
	(*stack) = temp_b;
}

void	push(t_numbers_list **src, t_numbers_list **dest)
{
	t_numbers_list	*temp;

	if (!*src)
		return ;
	temp = (*src)->next;
	numbers_lstadd_front(dest, *src);
	*src = temp;
}

void	rotate(t_numbers_list **stack)
{
	t_numbers_list	*last;
	t_numbers_list	*new_first;

	if (!stack || !(*stack) || !((*stack)->next))
		return ;
	last = numbers_lstlast(*stack);
	new_first = (*stack)->next;
	(*stack)->next = NULL;
	last->next = *stack;
	*stack = new_first;
}

void	reverse(t_numbers_list **stack)
{
	t_numbers_list	*last;
	t_numbers_list	*before_last;
	t_numbers_list	*current;

	if (!stack || !(*stack) || !((*stack)->next))
		return ;
	current = *stack;
	while (current->next->next)
		current = current->next;
	before_last = current;
	last = current->next;
	before_last->next = NULL;
	numbers_lstadd_front(stack, last);
}
/*MAIN PARA PUSH
#include <stdio.h>
int     main(void)
{
        t_list  *stack_a;
	t_list	*stack_b;
        t_list  *nodea;
        t_list  *nodemiddle;
        t_list  *nodeb;
	t_list	*node1;
	t_list  *node2;
	t_list  *node3;

        stack_a = NULL;
	stack_b = NULL;
        nodea = ft_lstnew(50);
        ft_lstadd_front(&stack_a, nodea);
        nodemiddle = ft_lstnew(45);
        ft_lstadd_front(&stack_a, nodemiddle);
        nodeb = ft_lstnew(40);
        ft_lstadd_front(&stack_a, nodeb);
	node1 = ft_lstnew(184651);
        ft_lstadd_front(&stack_b, node1);
        node2 = ft_lstnew(294643);
        ft_lstadd_front(&stack_b, node2);
        node3 = ft_lstnew(354915);
        ft_lstadd_front(&stack_b, node3);
	push(&stack_a, &stack_b);
	printf("stack a\n");
        while (stack_a)
        {
                printf("Before %d ", stack_a->content);
                stack_a = stack_a->next;
        }
        printf("\n");
	printf("stack b\n");
        while (stack_b)
        {
                printf("after %d ", stack_b->content);
                stack_b = stack_b->next;
        }
        return (0);
}
*/
/*MAIN PARA ROTATE O REVERSE
#include <stdio.h>
int     main(void)
{
        t_list  *list;
	t_list *ref;
        t_list  *nodea;
        t_list  *nodemiddle;
        t_list  *nodeb;

	
        list = NULL;
        nodea = ft_lstnew(30);
        ft_lstadd_front(&list, nodea);
        nodemiddle = ft_lstnew(20);
        ft_lstadd_front(&list, nodemiddle);
        nodeb = ft_lstnew(10);
        ft_lstadd_front(&list, nodeb);
	ref = list;
	while (list)
	{
		printf("Before %d ", list->content);
		list = list->next;
	}
	printf("\n");
	reverse(&ref);
	while (ref)
        {
                printf("after %d ", ref->content);
                ref = ref->next;
        }
        return (0);
}
*/
