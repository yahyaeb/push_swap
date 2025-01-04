/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bouk <yel-bouk@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 14:47:49 by yel-bouk          #+#    #+#             */
/*   Updated: 2025/01/03 15:15:44 by yel-bouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sort_three(t_list **stack_a)
{
	if ((*stack_a)->value > (*stack_a)->next->value
		&& (*stack_a)->next->value < (*stack_a)->next->next->value
		&& (*stack_a)->next->next->value > (*stack_a)->value)
		sa(stack_a);
	else if ((*stack_a)->value > (*stack_a)->next->value
		&& (*stack_a)->next->value > (*stack_a)->next->next->value)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if ((*stack_a)->value > (*stack_a)->next->value
		&& (*stack_a)->next->value < (*stack_a)->next->next->value
		&& (*stack_a)->next->next->value < (*stack_a)->value)
		ra(stack_a);
	else if ((*stack_a)->value < (*stack_a)->next->value
		&& (*stack_a)->next->value > (*stack_a)->next->next->value
		&& (*stack_a)->next->next->value > (*stack_a)->value)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if ((*stack_a)->value < (*stack_a)->next->value
		&& (*stack_a)->next->value > (*stack_a)->next->next->value
		&& (*stack_a)->next->next->value < (*stack_a)->value)
		rra(stack_a);
}
void	sort_three_or_two(t_list **stack_a)
{
	if(stack_size(*stack_a) == 2 && !is_sorted(*stack_a))
			sa(stack_a);
	else if(stack_size(*stack_a) == 3 && !is_sorted(*stack_a))
		sort_three(stack_a);
	else if(stack_size(*stack_a) == 1)
		return;
}