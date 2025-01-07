/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bouk <yel-bouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 12:04:35 by yel-bouk          #+#    #+#             */
/*   Updated: 2025/01/07 18:16:40 by yel-bouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
