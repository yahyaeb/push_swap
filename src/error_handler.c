/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bouk <yel-bouk@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 12:04:35 by yel-bouk          #+#    #+#             */
/*   Updated: 2025/01/08 22:55:56 by yel-bouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int has_duplicates(t_list *stack)
{
    t_list *current;
    t_list *compare;

    current = (stack);
    while (current)
    {
       	compare = current->next;
        while (compare)
        {
            if (current->value == compare->value)
                return 1;
            compare = compare->next;
        }
        current = current->next;
    }
    return 0;  // No duplicates found
}

int	check_int_array_values(int *array, int size)
{
	int	i;

	for (i = 0; i < size; i++)
	{
		if (array[i] < INT_MIN || array[i] > INT_MAX)
		{
			write(2, "Error\n", 6);  // Print error message
			return (0);  // Return 0 to indicate an out-of-range value
		}
	}
	return (1);  // Return 1 if all values are valid
}
int	check_atoi_values(long n)
{
	if (n < INT_MIN || n > INT_MAX)  // Check if the value is outside the int range
		return (1);  // Return 1 if it's out of range (error)
	return (0);  // Return 0 if it's valid
}
int validate_input(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (!ft_isdigit(str[i]) && str[i] != ' ' && str[i] != '-')
            return (0);  // Return 0 if any non-digit, non-space, and non-minus sign character is found
        if (str[i] == '-')
        {
            // Check if '-' is at a valid position
            if (i > 0 && str[i - 1] != ' ')
                return (0); // Return 0 if '-' is not preceded by a space
            if (!ft_isdigit(str[i + 1]))
                return (0); // Return 0 if '-' is not followed by a digit
        }
        i++;
    }
    return (1);  // Return 1 if all characters are valid
}