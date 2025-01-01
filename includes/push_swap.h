/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bouk <yel-bouk@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 22:12:29 by yel-bouk          #+#    #+#             */
/*   Updated: 2025/01/01 20:04:23 by yel-bouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include "../ft_printf/includes/ft_printf.h"

// Global Variable
extern int total_operations;

// Struct Definitions
typedef struct s_list
{
    int value;
    struct s_list *next;
} t_list;

// Stack Manipulation Operations
void sa(t_list **stack);
void sb(t_list **stack);
void pa(t_list **stack_a, t_list **stack_b);
void pb(t_list **stack_b, t_list **stack_a);
void ra(t_list **stack_a);
void rb(t_list **stack_b);
void rra(t_list **stack_a);
void rrb(t_list **stack_b);
void rr(t_list **stack_a, t_list **stack_b);
void rrr(t_list **stack_a, t_list **stack_b);

// Stack Utilities
int is_sorted(t_list *stack);
int stack_size(t_list *stack);
t_list *create_node(int value);
t_list *create_list(int *array, int size);
void free_stack(t_list **stack);
void print_stack(t_list *stack, const char *name); // Debug only

// Helper Functions
int find_min(t_list *stack);
int find_max(t_list *stack);
int find_pos(t_list *stack, int value);
int find_min_value(t_list *stack);
int get_value_at(t_list *stack, int index);
int has_elements_in_range(t_list *stack, int min, int max);
int find_closest_in_range(t_list *stack, int min, int max);
int *stack_to_array(t_list *stack, int size);

// Sorting Algorithms
void sort_three(t_list **stack_a);
void sort_five(t_list **stack_a, t_list **stack_b);
void sort_large(t_list **stack_a, t_list **stack_b);
void push_to_stack_b(t_list **stack_a, t_list **stack_b, int index);
void bring_to_top(t_list **stack_a, int index_a);

// Input Handling
int *string_to_int(char *str);
t_list *input_taker(char *str);

// Utility Functions
int ft_atoi(const char *str);
void *ft_calloc(size_t count, size_t size);
int ft_isdigit(int c);
int ft_wordcount(const char *str, char delimiter);
int ft_wordsize(char const *str, char c);
char **free_table(char **table);
char **ft_split(char const *s, char c);
char *ft_strncpy(char *dest, const char *src, size_t n);
void ft_bzero(void *ptr, size_t num);

#endif
