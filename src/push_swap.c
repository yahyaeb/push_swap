/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bouk <yel-bouk@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 22:12:24 by yel-bouk          #+#    #+#             */
/*   Updated: 2024/12/19 12:59:40 by yel-bouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
    ft_printf("sa\n");
}
void sb(t_list **stack)
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
    ft_printf("sb\n");
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
    ft_printf("pa\n");
}

void pb(t_list **stack_b, t_list **stack_a)
{
    t_list *original_head_a;

    if(*stack_a == NULL)
        return;
    original_head_a = (*stack_a);
    (*stack_a) = (*stack_a)->next;
    original_head_a->next = (*stack_b);
    *stack_b = original_head_a;

    total_operations++;
    ft_printf("pb\n");
}
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
    ft_printf("ra\n");
}
void    rb(t_list **stack_b)
{
    t_list *original_head;
    t_list *current_node;

    if((*stack_b) == NULL || (*stack_b)->next == NULL)
        return ;
    current_node = (*stack_b);
    original_head = (*stack_b);
    while(current_node->next != NULL)
    {
       current_node = current_node->next;
    }

    current_node->next = original_head;
    *stack_b = original_head->next;
    original_head->next = NULL;

    total_operations++;
    ft_printf("rb\n");
}
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
    ft_printf("rra\n");
}
void rrb(t_list **stack_b)
{
    if((*stack_b) == NULL || (*stack_b)->next == NULL)
        return;

    t_list *original_head;
    t_list *second_last;

    original_head = (*stack_b);
    second_last = (*stack_b);
    while(second_last->next->next)
    {
        second_last = second_last->next;
    }
    (*stack_b) = second_last->next;
    second_last->next = NULL;
    (*stack_b)->next = original_head;

    total_operations++;
    ft_printf("rrb\n");
}
void rrr(t_list **array_a, t_list **array_b)
{
    rra(array_a); 
    rrb(array_b);
    ft_printf("rrr\n");
}
void rr(t_list **array_a,t_list **array_b)
{
    ra(array_a);
    rb(array_b);
}