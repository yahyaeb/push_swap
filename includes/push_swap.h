/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bouk <yel-bouk@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 22:12:29 by yel-bouk          #+#    #+#             */
/*   Updated: 2024/12/19 18:11:41 by yel-bouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include "../ft_printf/includes/ft_printf.h"

#define STACK_SIZE 100
extern int total_operations;

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
void free_stack(t_list **stack);
void print_stack(t_list *stack, const char *name); // remove it later
t_list *create_node(int value);
t_list *create_list(int * array, int size);
int	ft_atoi(const char *str);
void	*ft_calloc(size_t count, size_t size);
int	ft_isdigit(int c);
int	ft_wordcount(const char *str, char delimiter);
int	ft_wordsize(char const *str, char c);
char	**free_table(char **table);
char	**ft_split(char const *s, char c);
char	*ft_strncpy(char *dest, const char *src, size_t n);
void	ft_bzero(void *ptr, size_t num);
int *string_to_int(char *str);
t_list* input_taker(char *str);
#endif