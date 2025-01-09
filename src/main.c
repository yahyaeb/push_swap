/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bouk <yel-bouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 22:41:59 by yel-bouk          #+#    #+#             */
/*   Updated: 2025/01/09 16:20:56 by yel-bouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1)
		return (0);
	stack_a = process_input(argc, argv);
	if (!stack_a || has_duplicates(stack_a))
	{
		ft_printf("Error\n");
		free_stack(&stack_a);
		free_stack(&stack_a);
		return (1);
	}
	if (is_sorted(stack_a))
		free_stack(&stack_a);
	if (!is_sorted(stack_a))
		push_swap(stack_a, stack_b);
	return (0);
}
