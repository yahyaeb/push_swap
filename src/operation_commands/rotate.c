/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bouk <yel-bouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 14:34:30 by yel-bouk          #+#    #+#             */
/*   Updated: 2025/01/02 14:45:12 by yel-bouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void    rotate(t_list **stack)
{
    if(!(*stack) || !(*stack)->next)
        return;
    
    t_list* tail;
    t_list* old_head;

    tail = (*stack);
    old_head = (*stack);

    while(tail->next)
        tail = tail->next;

    tail->next = old_head;
    old_head->prev = tail;
    (*stack) = old_head->next;
    (*stack)->prev = NULL;
    old_head->next = NULL;
}
void ra(t_list **stack_a)
{
    rotate(stack_a);
    ft_printf("ra\n");
}
void rb(t_list **stack_b)
{
    rotate(stack_b);
    ft_printf("rb\n");
}
void rr(t_list **stack_a, t_list **stack_b)
{
    rotate(stack_a);
    rotate(stack_b);
    ft_printf("rr\n");
}