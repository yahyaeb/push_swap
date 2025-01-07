/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_manipulation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bouk <yel-bouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 15:34:22 by yel-bouk          #+#    #+#             */
/*   Updated: 2025/01/06 17:07:55 by yel-bouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_list	*create_node(int value)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->next = NULL;
	return (new_node);
}

void	free_stack(t_list **stack)
{
	t_list	*temp;

	while (*stack)
	{
		temp = *stack;
		*stack = (*stack)->next;
		free(temp);
	}
}

t_list	*create_list(int *array, int size)
{
	int			i;
	t_list		*head;
	t_list		*tail;
	t_list		*new_node;

	if (size == 0)
		return (NULL);
	i = 1;
	head = create_node(array[0]);
	tail = head;
	while (i < size)
	{
		new_node = create_node(array[i]);
		tail->next = new_node;
		tail = new_node;
		i++;
	}
	return (head);
}
