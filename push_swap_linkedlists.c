#include "push_swap.h"

// sa (swap a): Swap the first 2 elements at the top of stack a.
// Do nothing if there is only one or no elements.



void sa(t_list **stack)
{
    t_list *original_head;
    t_list *second_node;

    // Storing the original node and the second node in temp struct pointers
    original_head = *stack;          // Save the original head (Node1)
    second_node = (*stack)->next;    // Save the second node (Node2)

    // Setting up the head of the list to be equal to the second node
    *stack = second_node;            // Now the new head is Node2

    // Now the second node is equal to the original head
    (*stack)->next = original_head;  // Node2->next = Node1

    // The current second node, which was the original node, points to the third node
    original_head->next = second_node->next; // Node1->next = Node3 (or NULL if there's no Node3)
}

// sb (swap b): Swap the first 2 elements at the top of stack b.
// Do nothing if there is only one or no elements.
void sa(t_list **stack)
{
	t_list *original_node;
	t_list *second_node;

	original_node = (*stack);
	second_node = (*stack)->next;
	(*stack)= second_node;
	(*stack)->next = original_node;
	original_node->next = second_node->next;
}

void pa(t_list **stack_a, t_list **stack_b)
{
    t_list *original_head_b;
    
    if(*stack_b == NULL)
        return;
    original_head_b = (*stack_b);
    (*stack_b) = (*stack_b)->next;
    original_head_b->next = (*stack_a);
    *stack_a = original_head_b;
}

// pb (push b): Take the first element at the top of a and put it at the top of b.
// Do nothing if a is empty.
void pb(t_list **stack_b, t_list **stack_a)
{
    t_list *original_a;

    if(*stack_a == NULL)
        return;
    
    original_a = (*stack_a);
    (*stack_a) = (*stack_a)->next;
    original_a->next = (*stack_b);
    (*stack_b) = original_a;
}