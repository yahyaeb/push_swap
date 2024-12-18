/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_large.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bouk <yel-bouk@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 17:21:46 by yel-bouk          #+#    #+#             */
/*   Updated: 2024/12/18 13:36:38 by yel-bouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_large(t_list **stack_a, t_list **stack_b)
{

	if (!stack_a || !*stack_a)
	    return;
	if (!stack_b)
	    return;

	
	if (*stack_a)
	{
		while(stack_size(*stack_a) > 3)
			push_min_to_b(stack_a,stack_b);
			
		sort_three(stack_a);
		if (*stack_b && (*stack_b)->next && (*stack_b)->value < (*stack_b)->next->value)
			sb(stack_b);
		while(stack_size(*stack_b) > 0)
			pa(stack_a, stack_b);
	}	
}