/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bouk <yel-bouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 14:47:49 by yel-bouk          #+#    #+#             */
/*   Updated: 2025/01/02 16:46:21 by yel-bouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sort_three(t_list **a) //Define a function that handles when stack `a` has three nodes, and sorts it
{
	t_list	*biggest_node; //To store a pointer to the biggest node in stack `a`

	biggest_node = find_max(*a);
	if (biggest_node == *a) //Check if the current node is the biggest
		ra(a); //If so, rotate the top node to the bottom of the stack
	else if ((*a)->next == biggest_node) //Check if the second node is the biggest
		rra(a); //If so, reverse rotate the bottom node, to the top of the stack
	if ((*a)->value > (*a)->next->value) //Check if the bottom node is the biggest, but the top node is higher than the second node
		sa(a); //If so, simply swap the top and second nodes
        return;
}