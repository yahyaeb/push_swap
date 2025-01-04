/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bouk <yel-bouk@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 22:50:11 by yel-bouk          #+#    #+#             */
/*   Updated: 2025/01/04 20:45:27 by yel-bouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void push_to_base_case(t_list **stack_a, t_list **stack_b)
{
    while (stack_size(*stack_a) > 3 && stack_size(*stack_b) < 2)
        pb(stack_a, stack_b);
}
t_list *find_target_node(t_list *stack_b, int value_a) {
    if (!stack_b) {
        printf("Error: stack_b is empty. Cannot find target for value %d.\n", value_a);
        return NULL;
    }

    t_list *target_node = NULL;
    t_list *max_node = find_max(stack_b);
    long best_match = LONG_MIN;

    while (stack_b) {
        if (stack_b->value < value_a && stack_b->value > best_match) {
            best_match = stack_b->value;
            target_node = stack_b;
        }
        stack_b = stack_b->next;
    }

    if (!target_node) {
        target_node = max_node;
    }

    return target_node;
}




void assign_target_nodes(t_list *stack_a, t_list *stack_b) {
    t_list *current_a = stack_a;
    while (current_a) {
        t_list *target_node = find_target_node(stack_b, current_a->value);
        if (!target_node) {
            printf("Error: No target node found for value %d\n", current_a->value);
            current_a->target = NULL;
        } else {
            printf("Assigned target for value %d: %d\n", current_a->value, target_node->value);
            current_a->target = target_node;
        }
        current_a = current_a->next;
    }
}





int calculate_position(t_list *stack, t_list *node) {
    int position = 0;
    printf("Calculating position for node with value: %d\n", node->value);
    
    while (stack) {
        printf("Current stack value: %d\n", stack->value);  // Debug: Print current stack value
        if (stack == node) {
            printf("Node found at position: %d\n", position);
            return position;
        }
        stack = stack->next;
        position++;
    }
    
    // Node not found in the stack
    printf("Error: Node with value %d not found in stack.\n", node->value);
    return -1;
}






void calculate_costs(t_list *stack_a, t_list *stack_b) {
    t_list *current_b = stack_b;
    print_stack(stack_b, "stack_b");
    print_stack(current_b, "current_b");
    
    while (current_b) {
        if (!current_b->target) {
            printf("Error: Target node is NULL for value %d in stack_b.\n", current_b->value);
            exit(1);
        }

        int pos_a = calculate_position(stack_a, current_b);
        int pos_b = calculate_position(stack_b, current_b);

        if (pos_a == -1 || pos_b == -1) {
            printf("Error: Invalid position calculated for nodes in stacks.\n");
            exit(1);
        }

        current_b->cost_a = (pos_a <= stack_size(stack_a) / 2) ? pos_a : stack_size(stack_a) - pos_a;
        current_b->cost_b = (pos_b <= stack_size(stack_b) / 2) ? pos_b : stack_size(stack_b) - pos_b;
        current_b->total_cost = current_b->cost_a + current_b->cost_b;
        current_b = current_b->next;
    }
}


// t_list *find_cheapest_move(t_list *stack_b)
// {
//     t_list *cheapest_node = stack_b;
//     t_list *current = stack_b;

//     if (!stack_b) {
//         printf("Error: stack_b is empty.\n");
//         return NULL;
//     }

//     while (current)
//     {
//         printf("Node value: %d, Total cost: %d\n", current->value, current->total_cost);
//         if (current->total_cost < cheapest_node->total_cost)
//             cheapest_node = current;
//         current = current->next;
//     }

//     printf("Found cheapest node: %d with total cost %d\n", cheapest_node->value, cheapest_node->total_cost);
//     return cheapest_node;
// }

// void debug_and_push_cheapest(t_list **stack_a, t_list **stack_b)
// {
//     t_list *cheapest_node = find_cheapest_move(*stack_b);

//     if (!cheapest_node) {
//         printf("Error: No cheapest node found.\n");
//         return;
//     }
//     if (!cheapest_node->target) {
//         printf("Error: Cheapest node %d has no target.\n", cheapest_node->value);
//         return;
//     }

//     printf("Cheapest move:\n");
//     printf("- Value: %d\n", cheapest_node->value);
//     printf("- Cost A (to top of stack_a): %d\n", cheapest_node->cost_a);
//     printf("- Cost B (to top of stack_b): %d\n", cheapest_node->cost_b);
//     printf("- Total cost: %d\n", cheapest_node->total_cost);
//     printf("- Target in stack_a: %d\n", cheapest_node->target->value);

//     if (cheapest_node->cost_a < 0 || cheapest_node->cost_b < 0) {
//         printf("Error: Negative costs detected for value %d.\n", cheapest_node->value);
//         exit(1);
//     }

//     pa(stack_a, stack_b);
// }


