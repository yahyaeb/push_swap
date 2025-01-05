/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bouk <yel-bouk@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 22:50:11 by yel-bouk          #+#    #+#             */
/*   Updated: 2025/01/05 22:26:51 by yel-bouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void push_to_base_case(t_list **stack_a, t_list **stack_b)
{
    while (stack_size(*stack_a) > 3 && stack_size(*stack_b) < 2) // Push until stack_b has 2 elements
        pb(stack_a, stack_b);
}

void current_index(t_list *stack)
{
    int i = 0;         // Index of the current node
    int median;        // Position of the median of the stack

    if (!stack)        // Check if the stack is empty
        return;

    median = stack_size(stack) / 2;  // Calculate the median index

    while (stack) {  
        stack->index = i;  
        
        // Optional change: Determine above_median based on the desired logic
        stack->above_median = (i > median);  // True only if strictly above the median
        stack = stack->next;  // Move to the next node
        ++i;  // Increment the index
    }
}

void set_target_a(t_list *stack_a, t_list *stack_b)
{
    t_list *current_b;
    t_list *target_node;
    long best_match_index;

    while (stack_a)
    {
        best_match_index = LONG_MIN;
        target_node = NULL;  // Reset the target node for each node in `a`
        current_b = stack_b;

        while (current_b)
        {
            if (current_b->value < stack_a->value && current_b->value > best_match_index)
            {
                best_match_index = current_b->value;
                target_node = current_b;
            }
            current_b = current_b->next;
        }

        if (!target_node)  // If no valid target was found
            target_node = find_max(stack_b);
        stack_a->target = target_node;  // Assign the target node
        stack_a = stack_a->next;
    }
}
void set_target_b(t_list *stack_a, t_list *top_b) {
    t_list *current_a = stack_a;
    t_list *target_node = NULL;
    long best_match_value = LONG_MAX;

    // Iterate through stack_a to find the closest larger value
    while (current_a) {
        if (current_a->value > top_b->value && current_a->value < best_match_value) {
            best_match_value = current_a->value;
            target_node = current_a;
        }
        current_a = current_a->next;
    }

    // If no valid target was found, assign the smallest value in stack_a
    if (!target_node) {
        target_node = find_min(stack_a);
    }
    top_b->target = target_node;  // Assign the target node
}




void calculate_costs(t_list *stack_a, t_list *stack_b)
{
    int stack_a_size = stack_size(stack_a);
    int stack_b_size = stack_size(stack_b);

    t_list *current = stack_a;

    while (current) {
        if (!current->target) {
            printf("Error: Target node for value %d is NULL.\n", current->value);
            current = current->next;
            continue;
        }

        int pos_a = current->index;  // Position of the node in stack_a
        int pos_b = current->target->index;  // Position of the target node in stack_b

        // Calculate rotation cost for stack_a
        int cost_a = (pos_a <= stack_a_size / 2) ? pos_a : stack_a_size - pos_a;

        // Calculate rotation cost for stack_b
        int cost_b = (pos_b <= stack_b_size / 2) ? pos_b : stack_b_size - pos_b;

        // Special case: If both nodes are already at the top, cost is 0
        if (pos_a == 0 && pos_b == 0) {
            current->total_cost = 0;
        }
        // Special case: If the positions are the same, use combined rotations (rr or rrr)
        else if (pos_a == pos_b) {
            current->total_cost = (pos_a <= stack_a_size / 2) ? pos_a : stack_a_size - pos_a;
        }
        // General case: Sum of individual rotation costs
        else {
            current->total_cost = cost_a + cost_b;
        }
        current = current->next;
    }
}
void set_cheapest(t_list *stack)
{
    if (!stack)  // Check if the stack is empty
        return;

    long cheapest_value = LONG_MAX;
    t_list *cheapest_node = NULL;

    // Reset all nodes' "cheapest" flags to false before finding the new cheapest node
    t_list *current = stack;
    while (current)
    {
        current->cheapest = false;  // Reset the flag
        current = current->next;
    }

    // Find the node with the minimum push_cost
    current = stack;
    while (current)
    {
        if (current->total_cost < cheapest_value)
        {
            cheapest_value = current->total_cost;
            cheapest_node = current;
        }
        current = current->next;
    }

    if (cheapest_node)  // Set the cheapest node's "cheapest" attribute to true
		cheapest_node->cheapest = true;

}
void prep_for_push(t_list **stack, t_list *top_node, char stack_name)
{
    // Rotate until the `top_node` is at the top of the stack
    while (*stack != top_node)
    {
        if (stack_name == 'a')
        {
            if (top_node->above_median)
                ra(stack);  // Rotate `stack_a` (ra)
            else
                rra(stack);  // Reverse rotate `stack_a` (rra)
        }
        else if (stack_name == 'b')
        {
            if (top_node->above_median)
                rb(stack);  // Rotate `stack_b` (rb)
            else
                rrb(stack);  // Reverse rotate `stack_b` (rrb)
        }
    }
}
void move_a_to_b(t_list **stack_a, t_list **stack_b)
{
    t_list *cheapest_node = get_cheapest(*stack_a);  // Get the cheapest node in stack_a

    if (cheapest_node->above_median && cheapest_node->target->above_median)
    {
        rotate_both(stack_a, stack_b, cheapest_node);  // Perform double rotate (`rr`)
    }
    else if (!cheapest_node->above_median && !cheapest_node->target->above_median)
    {
        rev_rotate_both(stack_a, stack_b, cheapest_node);  // Perform double reverse rotate (`rrr`)
    }
    
    // Rotate stack_a and stack_b separately to prepare for `pb`.
    prep_for_push(stack_a, cheapest_node, 'a');
    prep_for_push(stack_b, cheapest_node->target, 'b');
    pb(stack_a, stack_b);  // Push the node from stack_a to stack_b
}
void move_b_to_a(t_list **stack_a, t_list **stack_b)
{
    	current_index(*stack_a);  // Update indices for stack_a
    	current_index(*stack_b);  // Update indices for stack_b
    	set_target_b(*stack_a, *stack_b);  // Assign targets for stack_b
	prep_for_push(stack_a, (*stack_b)->target, 'a');
	pa(stack_a, stack_b);
}

void	init_nodes_a(t_list *stack_a, t_list *stack_b)
{
	current_index(stack_a);
	current_index(stack_b);
	set_target_a(stack_a, stack_b);
	calculate_costs(stack_a, stack_b);
	set_cheapest(stack_a);
}
void sort_stacks(t_list **stack_a, t_list **stack_b) {
    int stack_size_a;

    stack_size_a = stack_size(*stack_a);
    if (stack_size_a-- > 3 && !is_sorted(*stack_a))
        pb(stack_a, stack_b);
    if (stack_size_a-- > 3 && !is_sorted(*stack_a))
        pb(stack_a, stack_b);

	
    while (stack_size_a-- > 3 && !is_sorted(*stack_a)) 
    {
        init_nodes_a(*stack_a, *stack_b);
        move_a_to_b(stack_a, stack_b);
    }
    sort_three(stack_a);

   while (*stack_b)
    	move_b_to_a(stack_a, stack_b);
    current_index(*stack_a);
    min_to_top(stack_a);
}
