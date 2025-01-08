/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bouk <yel-bouk@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 22:18:36 by yel-bouk          #+#    #+#             */
/*   Updated: 2025/01/08 22:31:20 by yel-bouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void push_swap(t_list *stack_a, t_list *stack_b)
{
		if (stack_size(stack_a) <= 3)
			sort_three(&stack_a);
		else if (stack_size(stack_a) <= 5 && !is_sorted(stack_a))
			sort_five(&stack_a, &stack_b);
		else sort_large(&stack_a, &stack_b);
}

t_list *process_input(int argc, char *argv[])
{
    char *input_str = NULL;
    t_list *stack_a = NULL;

    if (argc == 2) {
        stack_a = input_taker(argv[1]);
    } else if (argc > 2) {
        input_str = convert_args_to_string(argc, argv);
        if (!input_str)
            return NULL;

        stack_a = input_taker(input_str);
        free(input_str);
    }

    return stack_a;
}
