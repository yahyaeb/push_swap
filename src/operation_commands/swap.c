/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bouk <yel-bouk@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 13:15:08 by yel-bouk          #+#    #+#             */
/*   Updated: 2025/01/05 16:48:41 by yel-bouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void swap(t_list **stack)
{
    if (!(*stack) || !(*stack)->next)
        return;

    t_list* first = (*stack);
    t_list* second = (*stack)->next;

    first->next = second->next;
    if (second->next)
        second->next->prev = first;
    
    second->prev = NULL;
    second->next = first;
    first->prev = second;

    (*stack) = second;
}
void sa(t_list ** stack_a)
{
    swap(stack_a);
    ft_printf("sa\n");
}
void sb(t_list **stack_b)
{
    swap(stack_b);
    ft_printf("sb\n");
}