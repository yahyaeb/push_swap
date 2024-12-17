/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bouk <yel-bouk@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 22:12:29 by yel-bouk          #+#    #+#             */
/*   Updated: 2024/12/17 23:36:21 by yel-bouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100

typedef struct s_list
{
	int value;
	struct s_list *next;
} t_list;
void sa(t_list **stack);
void sb(t_list **stack);
void pa(t_list **stack_a, t_list **stack_b);
void pb(t_list **stack_b, t_list **stack_a);
void ra(t_list **stack_a);
void    rb(t_list **stack_b);
void rra(t_list **stack_a);
void rrb(t_list **stack_b);
void rrr(t_list **array_a, t_list **array_b);
void rr(t_list **array_a,t_list **array_b);
int	is_sorted(t_list *stack);
int	find_min(t_list *stack);
int	find_max(t_list *stack);
int	find_pos(t_list *stack, int value);
int	stack_size(t_list *stack);
void push_min_to_b(t_list **stack_a, t_list **stack_b);
void sort_three(t_list **stack_a);
void sort_large(t_list **stack_a, t_list **stack_b);
void print_stack(t_list *stack, const char *name);
#endif