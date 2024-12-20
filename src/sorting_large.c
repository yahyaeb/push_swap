/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_large.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bouk <yel-bouk@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 17:21:46 by yel-bouk          #+#    #+#             */
/*   Updated: 2024/12/19 18:50:16 by yel-bouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void sort_large(t_list **stack_a, t_list **stack_b)
{
    if (!stack_a || !*stack_a)
        return;
    if (is_sorted(*stack_a))
        return;
    while (stack_size(*stack_a) > 3) // Push elements to stack_b, leaving three in stack_a
        push_min_to_b(stack_a, stack_b);

    sort_three(stack_a); // Sort the remaining three elements in stack_a

    if (*stack_b && (*stack_b)->next && (*stack_b)->value < (*stack_b)->next->value)
        sb(stack_b); // Ensure stack_b is in descending order for optimal pa

    while (stack_size(*stack_b) > 0) // Push all elements back to stack_a
        pa(stack_a, stack_b);
}

void sort_three(t_list **stack_a)
{
    if (!*stack_a || is_sorted(*stack_a))
        return;

    int first = (*stack_a)->value;
    int second = (*stack_a)->next->value;
    int third = (*stack_a)->next->next->value;

    if (first > second && second < third && third > first)
        sa(stack_a); // Case: 2 1 3
    else if (first > second && second > third && third < first)
    {
        sa(stack_a);
        rra(stack_a); // Case: 3 2 1
    }
    else if (first > second && second < third && third < first)
        ra(stack_a); // Case: 2 3 1
    else if (first < second && second > third && third > first)
    {
        sa(stack_a);
        ra(stack_a); // Case: 1 3 2
    }
    else if (first < second && second > third && third < first)
        rra(stack_a); // Case: 3 1 2
}



