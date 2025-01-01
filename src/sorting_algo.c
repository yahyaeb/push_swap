/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bouk <yel-bouk@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 17:21:46 by yel-bouk          #+#    #+#             */
/*   Updated: 2025/01/01 21:45:23 by yel-bouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
void push_to_stack_b(t_list **stack_a, t_list **stack_b, int index)
{
    int stack_size_a = stack_size(*stack_a); // Get the size of stack_a

    while (index != 0) // Loop until the target is at the top
    {
        if (index <= stack_size_a / 2) // If index is in the top half
        {
            ra(stack_a); // Rotate stack_a up
            total_operations++;
	    ft_printf("ra\n");
            index--; // Decrease index since we're rotating up
        }
        else // If index is in the bottom half
        {
            rra(stack_a); // Rotate stack_a down
            ft_printf("rra\n");
            total_operations++;
            index++; // Increase index since we're rotating down

            // Reset the index to 0 if it matches stack_size (logical wrap-around)
            if (index == stack_size_a)
                index = 0;
        }
    }

    // Push the top element of stack_a to stack_b
    pb(stack_b, stack_a);
    ft_printf("pb\n");
    total_operations++;
}


void sort_five(t_list **stack_a, t_list **stack_b)
{
    if (is_sorted(*stack_a))
        return;
    while (stack_size(*stack_a) > 3)
    {
        int min_pos = find_min(*stack_a);
	int size = stack_size(*stack_a);
        if (min_pos <= stack_size(*stack_a) / 2)
        {
                while (min_pos-- > 0)
		{
			ra(stack_a);
			total_operations++;
			ft_printf("ra\n");	
		}
        }
        else
        {
		while (min_pos++ < size)
		{
			rra(stack_a);
			total_operations++;
			ft_printf("rra\n");
		}

        }
        pb(stack_b, stack_a);
	ft_printf("pb\n");
	total_operations++;
    }
    sort_three(stack_a);

    while (stack_size(*stack_b) > 0)
        pa(stack_a, stack_b);
	ft_printf("pa\n");
	total_operations++;
}


void sort_three(t_list **stack_a)
{
    if (!*stack_a || is_sorted(*stack_a))
        return;

    int first = (*stack_a)->value;
    int second = (*stack_a)->next->value;
    int third = (*stack_a)->next->next->value;

    if (first > second && second < third && third > first)
    {
        sa(stack_a); // Case: 2 1 3
	ft_printf("sa\n");
	total_operations++;
    }
    else if (first > second && second > third && third < first)
    {
        sa(stack_a);
        rra(stack_a); // Case: 3 2 1
	total_operations+=2;
	ft_printf("sa\nrra\n");
    }
    else if (first > second && second < third && third < first)
	{
        	ra(stack_a); // Case: 2 3 1
		total_operations++;
		ft_printf("ra\n");
	}
    else if (first < second && second > third && third > first)
    {
        sa(stack_a);
        ra(stack_a); // Case: 1 3 2
	total_operations++;
	ft_printf("sa\nra\n");
    }
    else if (first < second && second > third && third < first)
    {
        rra(stack_a); // Case: 3 1 2
	total_operations++;
	ft_printf("rra\n");
    }
}
void sort_large(t_list **stack_a, t_list **stack_b)
{
    int chunk_size = stack_size(*stack_a) > 100 ? 20 : 10;
    int current_min = find_min_value(*stack_a);
    int current_max = current_min + chunk_size;

    // Step 1: Push chunks to Stack B
    while (*stack_a)
    {
        while (has_elements_in_range(*stack_a, current_min, current_max))
        {
            int target_index = find_closest_in_range(*stack_a, current_min, current_max);
            push_to_stack_b(stack_a, stack_b, target_index); // Push to Stack B
        }
        current_min += chunk_size;
        current_max += chunk_size;
    }
    if(stack_size(*stack_a) <= 5)
	sort_five(stack_a, stack_b);
    while (*stack_b)
    {
        int max_index = find_max(*stack_b);
         bring_to_top(stack_b, max_index);
	  // Bring the largest to the top of Stack B
        pa(stack_a, stack_b); // Push to Stack A
	ft_printf("pa\n");
    }
    if(is_sorted(*stack_a))
	ft_printf("\n------\nis sorted\n------\n");
}


