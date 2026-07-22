/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aunoguei <aunoguei@student.42urduliz.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 15:01:24 by aunoguei          #+#    #+#             */
/*   Updated: 2026/02/18 13:46:39 by ppousser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include "./libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>

typedef struct s_command
{
	int		bench;
	char	*strategy;
}			t_command;

typedef struct s_numbers_list
{
	int						content;
	int						index;
	struct s_numbers_list	*next;
}			t_numbers_list;

typedef struct s_bench
{
	int		bench;
	int		total;
	int		sa;
	int		sb;
	int		ss;
	int		pa;
	int		pb;
	int		ra;
	int		rb;
	int		rr;
	int		rra;
	int		rrb;
	int		rrr;
}			t_bench;

typedef struct s_stack
{
	struct s_numbers_list	*a;
	struct s_numbers_list	*b;
}			t_stacks;

int				is_bucket_needed(t_numbers_list *stacksa,
					int min_bucket, int max_bucket);
float			compute_disorder(int size, t_numbers_list *stack);
void			push_swap(int size, char **argv);
t_stacks		*init_stacks(int size, char **argv);
void			select_algorithm(t_stacks *stacks, int size, t_command cmds);
/* ************************************************************************** */
/*                             WRAPPERS FUNCTIONS                             */
/* ************************************************************************** */

void			sa(t_stacks *stacks, t_bench *bench);
void			sb(t_stacks *stacks, t_bench *bench);
void			ss(t_stacks *stacks, t_bench *bench);
void			pa(t_stacks *stacks, t_bench *bench);
void			pb(t_stacks *stacks, t_bench *bench);
void			ra(t_stacks *stacks, t_bench *bench);
void			rb(t_stacks *stacks, t_bench *bench);
void			rr(t_stacks *stacks, t_bench *bench);
void			rra(t_stacks *stacks, t_bench *bench);
void			rrb(t_stacks *stacks, t_bench *bench);
void			rrr(t_stacks *stacks, t_bench *bench);

/* ************************************************************************** */
/*                             OPERATIONS FUNCTIONS                           */
/* ************************************************************************** */

void			bucket_sort(t_stacks *stacks, int size, t_bench *bench);
void			insertion_sort(t_stacks *stack, t_bench *bench);
void			radix_sort(t_stacks *stacks, int size, t_bench *bench);
void			adaptive_sort(t_stacks *stacks, int size, float disorder,
					t_bench *bench);
void			bubblesort(int *numbers, int size);
void			quicksort(int *numbers, int low, int high);

/* ************************************************************************** */
/*                             STRINGS FUNCTIONS                              */
/* ************************************************************************** */

int				ft_is_input_valid(char **str, t_command *commands);
int				ft_is_str_int(char *src);

/* ************************************************************************** */
/*                              MEMORY FUNCTIONS                              */
/* ************************************************************************** */

char			**convert_input(int size, char **argv, int *size_final);
char			**manage_input(int argc, char **argv, int *size,
					t_command *commands);
char			**extract_numbers(int *size, char **input, t_command commands);
int				extract_commands(char *input, t_command *commands);
void			free_input(char **input, int size, t_command commands);
void			clear_all(t_numbers_list **stacks, t_command *command);

/* ************************************************************************** */
/*                             LIST FUNCTIONS                                 */
/* ************************************************************************** */
void			swap(t_numbers_list **stack);
void			push(t_numbers_list **src, t_numbers_list **dest);
void			rotate(t_numbers_list **stack);
void			reverse(t_numbers_list **stack);
void			clear_lst_numbers(t_numbers_list **lst);
void			numbers_lstadd_front(t_numbers_list **lst, t_numbers_list *new);
void			numbers_lstadd_back(t_numbers_list **lst, t_numbers_list *new);
t_numbers_list	*numbers_lstnew(int content);
t_numbers_list	*numbers_lstlast(t_numbers_list *lst);
#endif
