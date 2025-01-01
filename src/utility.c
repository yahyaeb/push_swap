/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bouk <yel-bouk@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 22:12:21 by yel-bouk          #+#    #+#             */
/*   Updated: 2025/01/01 21:42:18 by yel-bouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int find_min_value(t_list *stack) {
    int min_value = stack->value;
    while (stack) {
        if (stack->value < min_value)
            min_value = stack->value;
        stack = stack->next;
    }
    return min_value;
}
void bring_to_top(t_list **stack_a, int index_a)
{
    while (index_a > 0)
    {
        if (index_a <= stack_size(*stack_a) / 2)
        {
            ra(stack_a);
            ft_printf("ra\n");
            index_a--;
        }
        else
        {
            rra(stack_a);
            ft_printf("rra\n");
            index_a++;
            // Reset index_a to 0 if it equals the stack size (logical wrap-around)
            if (index_a == stack_size(*stack_a))
            {
                index_a = 0;
            }
        }
    }
}

int has_elements_in_range(t_list *stack, int min, int max)
{
    while (stack)
    {
        if (stack->value >= min && stack->value <= max)
            return 1;
        stack = stack->next;
    }
    return 0;
}
int find_closest_in_range(t_list *stack, int min, int max)
{
    int closest_index = -1;
    int current_index = 0;

    while (stack)
    {
        if (stack->value >= min && stack->value <= max)
            return current_index;
        stack = stack->next;
        current_index++;
    }

    return closest_index;
}
int is_sorted(t_list *stack) {
    while (stack && stack->next) 
    {
        if (stack->value > stack->next->value) 
		return 0;
        stack = stack->next;
    }
    return 1;
}

int find_min(t_list *stack)
{
    if (!stack)
        return -1;

    int min_value = stack->value;
    int min_index = 0;
    int i = 0;
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

    return min_index; 
}
int find_max(t_list *stack)
{
    if (!stack)
        return -1;

    int max_value = stack->value; 
    int max_index = 0;             
    int i = 0;          

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

    return max_index; 
}
int	find_pos(t_list *stack, int value)
{
	int	pos;

	pos = 0;
	while(stack)
	{
		if(stack->value == value)
			return pos;
		pos++;
		stack = stack->next;
	}
	return -1;
}
int stack_size(t_list *stack) {
    int size = 0;
    while (stack) {
        size++;
        stack = stack->next;
    }
    return size;
}