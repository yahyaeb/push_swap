/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_manipulation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bouk <yel-bouk@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 15:34:22 by yel-bouk          #+#    #+#             */
/*   Updated: 2024/12/19 18:11:52 by yel-bouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_list *create_node(int value)
{
    t_list *new_node;

    new_node = malloc(sizeof(t_list));
    if (!new_node)
        return NULL;
    new_node->value = value;
    new_node->next = NULL;
    return new_node;
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
void print_stack(t_list *stack, const char *name)
{
    ft_printf("%s: ", name);
    while (stack)
    {
        ft_printf("%d -> ", stack->value);
        stack = stack->next;
    }
    ft_printf("NULL\n");
}
t_list *create_list(int * array, int size)
{
    if(size == 0)
        return NULL;

        t_list * head;
        t_list *tail;
        t_list *new_node;
        int i;

        i = 1;
        head = create_node(array[0]);
        tail = head;
        while(i < size)
        {
            new_node = create_node(array[i]);
            tail->next = new_node;
            tail = new_node;
            i++;
        }
        return head;
}
