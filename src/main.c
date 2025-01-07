/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bouk <yel-bouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 22:41:59 by yel-bouk          #+#    #+#             */
/*   Updated: 2025/01/07 19:06:58 by yel-bouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


int main(int argc, char *argv[]) {
	t_list *stack_a = NULL;
	t_list *stack_b = NULL;
	char *input_str = NULL;

	if (argc == 2) {
		stack_a = input_taker(argv[1]);
		if (!stack_a) {
			ft_printf("Error\n");
			return 1;
		}
		if (stack_size(stack_a) <= 3)
			sort_three(&stack_a);
		else if (stack_size(stack_a) <= 5 && !is_sorted(stack_a))
			sort_five(&stack_a, &stack_b);
		else 
			sort_large(&stack_a, &stack_b);
	} else if (argc > 2) {
		input_str = convert_args_to_string(argc, argv);  // Store the allocated string
		if (!input_str) {
			ft_printf("Error\n");
			return 1;
		}
		stack_a = input_taker(input_str);  // Pass input_str to input_taker
		free(input_str);  // Free the allocated string after use
		if (!stack_a) {
			ft_printf("Error\n");
			return 1;
		}
		if (stack_size(stack_a) <= 3)
			sort_three(&stack_a);
		else if (stack_size(stack_a) <= 5 && !is_sorted(stack_a))
			sort_five(&stack_a, &stack_b);
		else if (stack_size(stack_a) > 5 && !is_sorted(stack_a))
			sort_large(&stack_a, &stack_b);
	} else {
		write(1, "", 1);
	}

	free_stack(&stack_a);
	free_stack(&stack_b);

	return 0; // Exit successfully
}
