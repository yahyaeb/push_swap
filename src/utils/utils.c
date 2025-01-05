/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bouk <yel-bouk@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 14:55:05 by yel-bouk          #+#    #+#             */
/*   Updated: 2025/01/05 22:27:16 by yel-bouk         ###   ########.fr       */
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
t_list *find_min(t_list *stack) {
    if (!stack) return NULL;
    t_list *min_node = stack;
    while (stack) {
        if (stack->value < min_node->value) 
            min_node = stack;
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
int max(int a, int b)
{
    if (a > b) 
        return a; 
    else 
        return b; 
}
t_list *get_cheapest(t_list *stack) //Define a function that searches for the cheapest node, that is set by bool
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}
void	rotate_both(t_list **a,
						t_list **b,
						t_list *cheapest_node) //Define a function that rotates both the top `a` and `b` nodes to the bottom of their stacks, if it's the cheapest move
{
	while (*b != cheapest_node->target
		&& *a != cheapest_node) //As long as the current `b` node is not `a` cheapest node's target node, and the current top `a` node is not the top node
		rr(a, b); //Rotate both `a` and `b` nodes
	current_index(*a);
	current_index(*b);
}
void	rev_rotate_both(t_list **a,
								t_list **b,
								t_list *cheapest_node) //Define a function that rotates both the bottom `a` and `b` nodes to the top of their stacks, if it's the cheapest move
{
	while (*b != cheapest_node->target
		&& *a != cheapest_node) //As long as the current `b` node is not `a` cheapest node's target node && and the current `a` node is not the cheapest
		rrr(a, b); //Reverse rotate both `a` and `b` nodes
	current_index(*a); //Refresh current node positions
	current_index(*b);
}

void min_to_top(t_list **stack)
{
    if (!stack || !(*stack))  // Check for an empty stack
        return;

    t_list *min_node = find_min(*stack);  // Find the minimum node once and store it
    while ((*stack)->value != min_node->value)  // While the min value is not at the top
    {
        if (min_node->above_median)  // Check if the min node is above the median
            ra(stack);  // Rotate upwards
        else
            rra(stack);  // Rotate downwards
    }
}
