#include "../includes/push_swap.h"

int total_operations = 0;

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

            sort_three(&stack_a);
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