/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bouk <yel-bouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 17:25:16 by yel-bouk          #+#    #+#             */
/*   Updated: 2025/01/07 19:21:04 by yel-bouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include "../ft_printf/includes/ft_printf.h"

/* **************************** Struct Definitions ************************* */

typedef struct s_list
{
	long				value;
	struct s_list	*next;
}					t_list;

/* *********************** Stack Manipulation Operations ******************* */

void				sa(t_list **stack_a);
void				sb(t_list **stack_b);
void				ss(t_list **stack_a, t_list **stack_b);
void				pa(t_list **stack_a, t_list **stack_b);
void				pb(t_list **stack_b, t_list **stack_a);
void				ra(t_list **stack_a);
void				rb(t_list **stack_b);
void				rra(t_list **stack_a);
void				rrb(t_list **stack_b);
void				rr(t_list **stack_a, t_list **stack_b);
void				rrr(t_list **stack_a, t_list **stack_b);

/* ************************** Stack Utilities ****************************** */

int					is_sorted(t_list *stack);
int					stack_size(t_list *stack);
t_list				*create_node(int value);
t_list				*create_list(int *array, int size);
void				free_stack(t_list **stack);

/* ************************** Helper Functions ***************************** */

int					find_min(t_list *stack);
int					find_max(t_list *stack);
int					find_pos(t_list *stack, int value);
int					find_min_value(t_list *stack);
int					has_elements_in_range(t_list *stack, int min, int max);
int					find_closest_in_range(t_list *stack, int min, int max);
int					*stack_to_array(t_list *stack, int size);
t_list				*find_max_node(t_list *stack);

/* ************************* Sorting Algorithms **************************** */

void				sort_three(t_list **stack_a);
void				sort_five(t_list **stack_a, t_list **stack_b);
void				sort_large(t_list **stack_a, t_list **stack_b);
void				push_to_stack_b(t_list **stack_a,
						t_list **stack_b, int index);
void				bring_to_top_a(t_list **stack_a, int index_a);
void				bring_to_top_b(t_list **stack_b, int index_a);

/* ******************* Input Handling *********** */

int					*string_to_int(char *str);
t_list				*input_taker(char *str);

/* ************************ Utility Functions ****************************** */

long	ft_atoi(const char *str);
void				*ft_calloc(size_t count, size_t size);
int					ft_isdigit(int c);
int					ft_wordcount(const char *str, char delimiter);
int					ft_wordsize(char const *str, char c);
char				**free_table(char **table);
char				**ft_split(char const *s, char c);
char				*ft_strncpy(char *dest, const char *src, size_t n);
void				ft_bzero(void *ptr, size_t num);
char				*ft_strdup(char *str);
char				*ft_strjoin(char *s1, char *s2);
size_t				ft_strlcpy(char *dest, char *src, size_t size);
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);

/* ************************ Other Operations ******************************* */

void				rotate(t_list **stack);
void				push(t_list **dst, t_list **src);
void				rev_rotate(t_list **stack);
void				swap(t_list **stack);
char				*convert_args_to_string(int argc, char **argv);
int	check_int_array_values(int *array, int size);
int	check_atoi_values(long n);
int	ft_word_count(const char *str);

#endif
