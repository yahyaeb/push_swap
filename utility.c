/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bouk <yel-bouk@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 22:12:21 by yel-bouk          #+#    #+#             */
/*   Updated: 2024/12/16 15:09:32 by yel-bouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_list *stack)
{
	while (stack && stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}
int	find_min(t_list *stack)
{
	int	min_value;
	
	min_value = stack->value;
	while (stack)
	{
		if(stack->value < min_value)
			min_value = stack->value;
		stack = stack->next;
	}
	return (min_value);
}
int	find_max(t_list *stack)
{
	int	max_value;
	
	max_value = stack->value;
	while(stack)
	{
		if(stack->value > max_value)
			max_value = stack->value;
		stack = stack->next;
	}
	return (max_value);
}
int	find_pos(t_list *stack, int value)
{
	int	pos;

	pos = 0;
	while(stack && stack->next)
	{
		if(stack->value == value)
			return pos;
		pos++;
		stack = stack->next;
	}
	return -1;
}
int	stack_size(t_list *stack)
{
	int	size;

	size = 0;
	while(stack)
	{
		stack = stack->next;
		size++;
	}
	return (size);
}