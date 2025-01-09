/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   value_finder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bouk <yel-bouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 16:43:05 by yel-bouk          #+#    #+#             */
/*   Updated: 2025/01/09 13:26:56 by yel-bouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	find_min_value(t_list *stack)
{
	int	min_value;

	min_value = stack->value;
	while (stack)
	{
		if (stack->value < min_value)
			min_value = stack->value;
		stack = stack->next;
	}
	return (min_value);
}

int	find_min(t_list *stack)
{
	int	min_value;
	int	min_index;
	int	i;

	if (!stack)
		return (-1);
	min_value = stack->value;
	min_index = 0;
	i = 0;
	while (stack)
	{
		if (stack->value < min_value)
		{
			min_value = stack->value;
			min_index = i;
		}
		stack = stack->next;
		i++;
	}
	return (min_index);
}

int	find_max(t_list *stack)
{
	int	max_value;
	int	max_index;
	int	i;

	if (!stack)
		return (-1);
	max_value = stack->value;
	max_index = 0;
	i = 0;
	while (stack)
	{
		if (stack->value > max_value)
		{
			max_value = stack->value;
			max_index = i;
		}
		stack = stack->next;
		i++;
	}
	return (max_index);
}

int	find_pos(t_list *stack, int value)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (stack->value == value)
			return (pos);
		pos++;
		stack = stack->next;
	}
	return (-1);
}

t_list	*find_max_node(t_list *stack)
{
	long			max;
	t_list			*max_node;

	if (!stack)
		return (NULL);
	max = stack->value;
	max_node = stack;
	while (stack)
	{
		if (stack->value > max)
		{
			max = stack->value;
			max_node = stack;
		}
		stack = stack->next;
	}
	return (max_node);
}
