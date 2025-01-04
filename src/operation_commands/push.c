/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bouk <yel-bouk@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 13:41:50 by yel-bouk          #+#    #+#             */
/*   Updated: 2025/01/04 19:37:56 by yel-bouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void push(t_list **dest, t_list **src)
{
    if (!src || !(*src))
        return;

    t_list *head = *src;
    (*src) = (*src)->next;
    if (*src)
        (*src)->prev = NULL;

    head->next = (*dest);
    if ((*dest))
        (*dest)->prev = head;

    head->prev = NULL;
    (*dest) = head;
}


void    pa(t_list **stack_a, t_list **stack_b)
{
    push(stack_a, stack_b);
    ft_printf("pa\n");
}
void    pb(t_list **stack_a, t_list **stack_b)
{
    push(stack_b, stack_a);
    ft_printf("pb\n");
}