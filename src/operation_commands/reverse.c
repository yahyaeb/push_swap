/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bouk <yel-bouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 14:20:06 by yel-bouk          #+#    #+#             */
/*   Updated: 2025/01/02 17:17:19 by yel-bouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void reverse_rotate(t_list **stack)
{
    if (!(*stack) || !(*stack)->next) // Check for empty or single-node list
        return;
    ft_printf("I am here1");
    t_list *tail = *stack;
    t_list *new_tail = NULL;
ft_printf("I am here2");
    // Traverse to the tail of the list
    while (tail->next)
        tail = tail->next;
ft_printf("I am here3");
    // Set the new tail to the previous node
    new_tail = tail->prev;
    ft_printf("I am here4");
    if (new_tail) 
        new_tail->next = NULL; // Disconnect the old tail
    ft_printf("I am here5");
    // Move the old tail to the front of the list
    tail->next = *stack;
    ft_printf("I am here6");
    tail->prev = NULL;
    ft_printf("I am here7");
    if (*stack)
        (*stack)->prev = tail;
    ft_printf("I am here8");
    *stack = tail; // Update the head pointer
}




void rra(t_list **stack_a)
{
    reverse_rotate(stack_a);
    ft_printf("rra\n");
}
void rrb(t_list **stack_b)
{
    reverse_rotate(stack_b);
    ft_printf("rrb\n");
}
void rrr(t_list **stack_a, t_list **stack_b)
{
    reverse_rotate(stack_a);
    reverse_rotate(stack_b);
    ft_printf("rrr\n");
}