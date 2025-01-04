/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bouk <yel-bouk@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 14:55:05 by yel-bouk          #+#    #+#             */
/*   Updated: 2025/01/04 20:28:04 by yel-bouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_list* find_max(t_list *stack)
{
    long    max_value;
    t_list*  max_node;

    if(!stack)
        return (NULL);
    
    max_value   = LONG_MIN;

    while(stack)
    {
        if(stack->value > max_value)
        {
            max_value = stack->value;
            max_node = (stack);
        }
        stack = stack->next;
    }
    return (max_node);
}
t_list* find_min(t_list *stack)
{
    long    min_value;
    t_list*  min_node;

    if(!stack)
        return (NULL);
    
    min_value   = LONG_MIN;

    while(stack)
    {
        if(stack->value > min_value)
        {
            min_value = stack->value;
            min_node = (stack);
        }
        stack = stack->next;
    }
    return (min_node);
}

void debug_target_nodes(t_list *stack_a)
{
    t_list *current = stack_a;
    while (current)
    {
        if (!current->target)
            printf("Error: Target is NULL for value %d\n", current->value);
        else
            printf("Value: %d -> Target: %d\n", current->value, current->target->value);
        current = current->next;
    }
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

int stack_size(t_list *stack) {
    int size = 0;
    while (stack) {
        stack = stack->next;
        size++;
    }
    return size;
}
