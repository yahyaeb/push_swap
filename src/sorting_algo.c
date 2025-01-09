/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bouk <yel-bouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 17:21:46 by yel-bouk          #+#    #+#             */
/*   Updated: 2025/01/09 13:33:42 by yel-bouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_to_stack_b(t_list **stack_a, t_list **stack_b, int index)
{
	int	stack_size_a;

	stack_size_a = stack_size(*stack_a);
	while (index != 0)
	{
		if (index <= stack_size_a / 2)
		{
			ra(stack_a);
			index--;
		}
		else
		{
			rra(stack_a);
			index++;
			if (index == stack_size_a)
				index = 0;
		}
	}
	pb(stack_a, stack_b);
}

void	sort_five(t_list **stack_a, t_list **stack_b)
{
	int	min_pos;
	int	size;

	if (is_sorted(*stack_a))
		return ;
	while (stack_size(*stack_a) > 3)
	{
		min_pos = find_min(*stack_a);
		size = stack_size(*stack_a);
		if (min_pos <= stack_size(*stack_a) / 2)
		{
			while (min_pos-- > 0)
				ra(stack_a);
		}
		else
		{
			while (min_pos++ < size)
				rra(stack_a);
		}
		pb(stack_a, stack_b);
	}
	sort_three(stack_a);
	while (stack_size(*stack_b) > 0)
		pa(stack_a, stack_b);
}

void	sort_three(t_list **stack_a)
{
	t_list	*biggest_node;

	if (stack_size(*stack_a) < 2)
		return ;
	else if (stack_size(*stack_a) == 2 && is_sorted(*stack_a) == 0)
	{
		sa(stack_a);
		return ;
	}
	else if (is_sorted(*stack_a))
		return ;
	biggest_node = find_max_node(*stack_a);
	if (biggest_node == *stack_a)
		ra(stack_a);
	else if ((*stack_a)->next == biggest_node)
		rra(stack_a);
	if ((*stack_a)->value > (*stack_a)->next->value)
		sa(stack_a);
}

void	sort_large(t_list **stack_a, t_list **stack_b)
{
	int	chunk_size;
	int	curr_min;
	int	curr_max;
	int	target_index;
	int	max_index;

	chunk_size = 20;
	curr_min = find_min_value(*stack_a);
	curr_max = curr_min + chunk_size;
	while (*stack_a)
	{
		while (has_elements_in_range(*stack_a, curr_min, curr_max))
		{
			target_index = find_closest_in_range(*stack_a, curr_min, curr_max);
			push_to_stack_b(stack_a, stack_b, target_index);
		}
		curr_min += chunk_size;
		curr_max += chunk_size;
	}
	while (*stack_b)
	{
		max_index = find_max(*stack_b);
		bring_to_top_b(stack_b, max_index);
		pa(stack_a, stack_b);
	}
}
