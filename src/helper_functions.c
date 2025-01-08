/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bouk <yel-bouk@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 16:22:03 by yel-bouk          #+#    #+#             */
/*   Updated: 2025/01/08 22:55:50 by yel-bouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	bring_to_top_a(t_list **stack_a, int index_a)
{
	while (index_a > 0)
	{
		if (index_a <= stack_size(*stack_a) / 2)
		{
			ra(stack_a);
			index_a--;
		}
		else
		{
			rra(stack_a);
			index_a++;
			if (index_a == stack_size(*stack_a))
			{
				index_a = 0;
			}
		}
	}
}

void	bring_to_top_b(t_list **stack_b, int index_a)
{
	while (index_a > 0)
	{
		if (index_a <= stack_size(*stack_b) / 2)
		{
			rb(stack_b);
			index_a--;
		}
		else
		{
			rrb(stack_b);
			index_a++;
			if (index_a == stack_size(*stack_b))
			{
				index_a = 0;
			}
		}
	}
}

int	has_elements_in_range(t_list *stack, int min, int max)
{
	while (stack)
	{
		if (stack->value >= min && stack->value <= max)
			return (1);
		stack = stack->next;
	}
	return (0);
}

int	find_closest_in_range(t_list *stack, int min, int max)
{
	int	closest_index;
	int	current_index;

	closest_index = -1;
	current_index = 0;
	while (stack)
	{
		if (stack->value >= min && stack->value <= max)
			return (current_index);
		stack = stack->next;
		current_index++;
	}
	return (closest_index);
}
int	ft_word_count(const char *str)
{
	int	count;
	int	in_word;

	if (!str)
		return (0);
	count = 0;
	in_word = 0;
	while (*str)
	{
		if (*str == ' ' || *str == '\t')
			in_word = 0;
		else if (!in_word)
		{
			count++;
			in_word = 1;
		}
		str++;
	}
	return (count);
}
