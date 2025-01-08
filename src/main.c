/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bouk <yel-bouk@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 22:41:59 by yel-bouk          #+#    #+#             */
/*   Updated: 2025/01/08 22:29:07 by yel-bouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


int main(int argc, char *argv[])
{
    t_list *stack_a = NULL;
    t_list *stack_b = NULL;

    stack_a = process_input(argc, argv);
    if (!stack_a || has_duplicates(stack_a)) {
        ft_printf("Error\n");
        free_stack(&stack_a);
        return 1;
    }

    push_swap(stack_a, stack_b);
    free_stack(&stack_a);
    free_stack(&stack_b);

    return 0;
}
