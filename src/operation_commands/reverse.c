/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bouk <yel-bouk@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 14:20:06 by yel-bouk          #+#    #+#             */
/*   Updated: 2025/01/03 11:53:35 by yel-bouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void reverse_rotate(t_list **stack) {
    if (!*stack || !(*stack)->next)
        return;

    t_list *last = *stack;
    t_list *second_last = NULL;

    // Traverse to the last node and keep track of the second last node
    while (last->next) {
        second_last = last;
        last = last->next;
    }
    // Detach the last node from the list
    if (second_last)
        second_last->next = NULL;

    if (last) 
        last->prev = NULL;

    // Move the detached last node to the front
    last->next = *stack;
    if (*stack)
        (*stack)->prev = last;
    *stack = last;
}

void rra(t_list **stack_a)
{
    reverse_rotate(stack_a);
    ft_printf("rra\n");
    total_operations++;
}
void rrb(t_list **stack_b)
{
    reverse_rotate(stack_b);
    ft_printf("rrb\n");
    total_operations++;
}
void rrr(t_list **stack_a, t_list **stack_b)
{
    reverse_rotate(stack_a);
    reverse_rotate(stack_b);
    ft_printf("rrr\n");
    total_operations++;
}