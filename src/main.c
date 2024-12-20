/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bouk <yel-bouk@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 22:41:59 by yel-bouk          #+#    #+#             */
/*   Updated: 2024/12/19 18:22:17 by yel-bouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int total_operations = 0;
// int main(void)
// {
//         // Case: 100 elements - Mixed order with positive and negative values
//         int array[] = {100, 231, 1, 3, 9, 4, 2};
        
//         t_list *stack_a;
//         stack_a = create_list(array, 7);
        
//         t_list *stack_b = NULL;
        
//         printf("Before sorting 100 elements:\n");
//         print_stack(stack_a, "stack_a");
    
//         // Sort the list
//         sort_large(&stack_a, &stack_b);

//         printf("\nAfter sorting 100 elements:\n");
//         print_stack(stack_a, "stack_a ");
//         ft_printf("Total operations performed: %d\n", total_operations);
//         // Free memory
//         free_stack(&stack_a);
//         free_stack(&stack_b);

//     return 0;
// }


int main(int argc, char *argv[])
{
    t_list *stack_a = NULL;
    t_list *stack_b = NULL;

    // Check for valid input
    if (argc == 2)
    {
        stack_a = input_taker(argv[1]);

        // Handle invalid or empty input
        if (!stack_a)
        {
            ft_printf("Error\n");
            return 1; // Exit with error code
        }

        ft_printf("Before sorting:\n");
        print_stack(stack_a, "stack_a");

        // Sort the list
        sort_large(&stack_a, &stack_b);

        ft_printf("\nAfter sorting:\n");
        print_stack(stack_a, "stack_a");
        ft_printf("Total operations performed: %d\n", total_operations);
    }
    else
        write(1, "\n", 1);

    // Free allocated memory
    free_stack(&stack_a);
    free_stack(&stack_b);

    return 0; // Exit successfully
}
