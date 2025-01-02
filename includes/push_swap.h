/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bouk <yel-bouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 22:12:29 by yel-bouk          #+#    #+#             */
/*   Updated: 2025/01/02 16:12:46 by yel-bouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <limits.h>
#include "../ft_printf/includes/ft_printf.h"

// Global Variable
extern int total_operations;

// Struct Definitions
typedef struct s_list
{
    int value;               // The value of the node
    int cost_a;              // Cost to move its target node to the top of stack_a
    int cost_b;              // Cost to move this node to the top of stack_b
    struct s_list *target;   // Pointer to the target node in stack_a
    struct s_list *next;     // Pointer to the next node
    struct s_list *prev;     // Pointer to the previous node
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
void swap(t_list **stack);
void push(t_list **dest, t_list **src);
void    reverse_rotate(t_list **stack);
void    rotate(t_list **stack);


// Stack Utilities
int is_sorted(t_list *stack);
int stack_size(t_list *stack);
t_list *create_node(int value);
t_list *create_list(int *array, int size);
void free_stack(t_list **stack);
void print_stack(t_list *stack, const char *name); // Debug only

// Helper Functions
t_list* find_min(t_list *stack);
t_list* find_max(t_list *stack);

// Sorting Algorithms
void sort_three(t_list **stack_a);

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
