/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bouk <yel-bouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 14:55:05 by yel-bouk          #+#    #+#             */
/*   Updated: 2025/01/02 16:12:46 by yel-bouk         ###   ########.fr       */
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