/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bouk <yel-bouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 12:04:35 by yel-bouk          #+#    #+#             */
/*   Updated: 2025/01/09 13:40:56 by yel-bouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	has_duplicates(t_list *stack)
{
	t_list	*current;
	t_list	*compare;

	current = (stack);
	while (current)
	{
		compare = current->next;
		while (compare)
		{
			if (current->value == compare->value)
				return (1);
			compare = compare->next;
		}
		current = current->next;
	}
	return (0);
}

int	check_int_array_values(int *array, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (array[i] < INT_MIN || array[i] > INT_MAX)
		{
			write(2, "Error\n", 6);
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_atoi_values(long n)
{
	if (n < INT_MIN || n > INT_MAX)
		return (1);
	return (0);
}

int	validate_input(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && str[i] != ' ' && str[i] != '-')
			return (0);
		if (str[i] == '-')
		{
			if (i > 0 && str[i - 1] != ' ')
				return (0);
			if (!ft_isdigit(str[i + 1]))
				return (0);
		}
		i++;
	}
	return (1);
}
