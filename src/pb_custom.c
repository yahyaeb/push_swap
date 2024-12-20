/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb_custom.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bouk <yel-bouk@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 17:25:17 by yel-bouk          #+#    #+#             */
/*   Updated: 2024/12/19 18:52:22 by yel-bouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
void push_min_to_b(t_list **stack_a, t_list **stack_b)
{
    int min;
    int position;
    int size;

    min = find_min(*stack_a);
    size = stack_size(*stack_a);

    while ((position = find_pos(*stack_a, min)) != 0)
    {
        if (position <= size / 2)
            ra(stack_a);
        else
            rra(stack_a);
    }
    pb(stack_b, stack_a);
}


