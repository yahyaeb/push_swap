/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bouk <yel-bouk@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 22:12:24 by yel-bouk          #+#    #+#             */
/*   Updated: 2024/12/18 13:35:42 by yel-bouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
int total_operations = 0;
// sa (swap a): Swap the first 2 elements at the top of stack a.
// Do nothing if there is only one or no elements.

void sa(t_list **stack)
{
    t_list *original_head;
    t_list *second_node;
    
    if((*stack) == NULL || (*stack)->next == NULL)
        return;
    original_head = *stack; 
    second_node = (*stack)->next;
    *stack = second_node;
    original_head->next = second_node->next;
    (*stack)->next = original_head;
    total_operations++;
}

// sb (swap b): Swap the first 2 elements at the top of stack b.
// Do nothing if there is only one or no elements.
void sb(t_list **stack)
{
	sa(stack);
    total_operations++;
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
    total_operations++;
}

// pb (push b): Take the first element at the top of a and put it at the top of b.
// Do nothing if a is empty.
void pb(t_list **stack_b, t_list **stack_a)
{
    pa(stack_a, stack_b);
    total_operations++;
}

// ra (rotate a): Shift up all elements of stack a by 1.
// The first element becomes the last one.
void ra(t_list **stack_a)
{
    t_list *original_head;
    t_list *current_node;
    
    if((*stack_a) == NULL || (*stack_a)->next == NULL)
        return ;
    current_node = (*stack_a);
    original_head = (*stack_a);
    while(current_node->next != NULL)
    {
       current_node = current_node->next;
    }
    
    current_node->next = original_head;
    *stack_a = original_head->next;
    original_head->next = NULL;
    total_operations++;
}
void    rb(t_list **stack_b)
{
    ra(stack_b);
    total_operations++;
}
// rra (reverse rotate a): Shift down all elements of stack a by 1.
// The last element becomes the first one.
void rra(t_list **stack_a)
{
    if((*stack_a) == NULL || (*stack_a)->next == NULL)
        return;

    t_list *original_head;
    t_list *second_last;

    original_head = (*stack_a);
    second_last = (*stack_a);
    while(second_last->next->next)
    {
        second_last = second_last->next;
    }
    (*stack_a) = second_last->next;
    second_last->next = NULL;
    (*stack_a)->next = original_head;
    total_operations++;
}

// rrb (reverse rotate b): Shift down all elements of stack b by 1.
// The last element becomes the first one.
void rrb(t_list **stack_b)
{
   rra(stack_b);
   total_operations++;
}
// rrr : rra and rrb at the same time.
void rrr(t_list **array_a, t_list **array_b)
{
    rra(array_a);
	rrb(array_b);
    total_operations++;
}
void rr(t_list **array_a,t_list **array_b)
{
    ra(array_a);
    rb(array_b);
    total_operations++;
}