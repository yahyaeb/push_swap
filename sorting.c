/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bouk <yel-bouk@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 22:41:59 by yel-bouk          #+#    #+#             */
/*   Updated: 2024/12/18 13:42:53 by yel-bouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void sort_three(t_list **stack_a)
{
    if (!*stack_a || is_sorted(*stack_a))
        return;

    int max = find_max(*stack_a);
    int min = find_min(*stack_a);

    if (find_pos(*stack_a, max) == 0)
        ra(stack_a);
    else if (find_pos(*stack_a, min) == 1)
        sa(stack_a);
    else if (find_pos(*stack_a, max) == 1)
        sa(stack_a);
    if (!is_sorted(*stack_a))
    {
        if (find_pos(*stack_a, min) == 1)
            sa(stack_a);
        else if (find_pos(*stack_a, max) == 0)
            rra(stack_a);
    }
    if(!is_sorted(*stack_a) && find_pos(*stack_a, min) == 0 && find_pos(*stack_a, max) == 1)
    {
        ra(stack_a);
        sa(stack_a);
        rra(stack_a);
    }
}


void free_stack(t_list **stack)
{
    t_list *temp;
    while (*stack)
    {
        temp = *stack;
        *stack = (*stack)->next;
        free(temp);
    }
}
t_list *create_node(int value)
{
    t_list *new_node = malloc(sizeof(t_list));
    if (!new_node)
        return NULL;
    new_node->value = value;
    new_node->next = NULL;
    return new_node;
}

// Helper function to print a stack
void print_stack(t_list *stack, const char *name)
{
    printf("%s: ", name);
    while (stack)
    {
        printf("%d -> ", stack->value);
        stack = stack->next;
    }
    printf("NULL\n");
}

void push_node_back(t_list **stack, int value)
{
    t_list *new_node = create_node(value);
    t_list *current;

    if (!new_node)
        return;
    if (!*stack) // If stack is empty, new node becomes the head
    {
        *stack = new_node;
        return;
    }
    current = *stack;
    while (current->next != NULL)
        current = current->next; // Traverse to the end
    current->next = new_node;    // Append the new node
}


int main()
{
    // Case: 100 elements - Mixed order with positive and negative values
    t_list *stack_a;
    //Add more nodes to complete 100 elements
    for (int i = 1; i <= 500; i++)
{
    int value = i * ((i % 2 == 0) ? -1 : 1); // Generate value
    if (find_pos(stack_a, value) == -1)     // Check if value already exists
        push_node_back(&stack_a, value);    // Add value only if it's unique
}

    t_list *stack_b = NULL;

    printf("Before sorting 100 elements:\n");
    print_stack(stack_a, "stack_a");

    // Sort the list
    sort_large(&stack_a, &stack_b);

    printf("\nAfter sorting 100 elements:\n");
    print_stack(stack_a, "stack_a ");
    printf("Total operations performed: %d\n", total_operations);
    // Free memory
    free_stack(&stack_a);
    free_stack(&stack_b);

    return 0;
}
