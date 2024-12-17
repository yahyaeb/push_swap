/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_helper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bouk <yel-bouk@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 17:25:17 by yel-bouk          #+#    #+#             */
/*   Updated: 2024/12/17 23:51:26 by yel-bouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push_min_to_b(t_list **stack_a, t_list **stack_b)
{
    int min;
    int position;
    int size;

    min = find_min(*stack_a);
    size = stack_size(*stack_a);
    position = find_pos(*stack_a, min);

    while (find_pos(*stack_a, min) != 0)
    {
        if (position <= size / 2)
            ra(stack_a);
        else
            rra(stack_a);
    }
    pb(stack_a, stack_b);
}