/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bouk <yel-bouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:20:04 by yel-bouk          #+#    #+#             */
/*   Updated: 2025/01/09 13:31:56 by yel-bouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	process_value(char **array, int *int_array, int *index, int size)
{
	long		value;
	int			i;
	int			j;

	i = *index;
	value = ft_atoi(array[i]);
	if (check_atoi_values(value))
	{
		j = i;
		while (j < size)
			free(array[j++]);
		free(array);
		free(int_array);
		return (0);
	}
	int_array[i] = (int)value;
	free(array[i]);
	*index = i + 1;
	return (1);
}

int	*convert_to_int_array(char **array, int size)
{
	int	*int_array;
	int	i;

	int_array = malloc(size * sizeof(int));
	if (!int_array)
	{
		free_table(array);
		return (NULL);
	}
	i = 0;
	while (i < size)
	{
		if (!process_value(array, int_array, &i, size))
			return (NULL);
	}
	free(array);
	return (int_array);
}

int	*string_to_int(char *str)
{
	int			size;
	int			*int_array;
	char		**array;

	if (!validate_input(str))
		return (NULL);
	array = ft_split(str, ' ');
	if (!array)
		return (NULL);
	size = ft_word_count(str);
	int_array = convert_to_int_array(array, size);
	return (int_array);
}

t_list	*input_taker(char *str)
{
	int			size;
	int			*array;
	t_list		*list;

	if (!str || !*str)
	{
		return (NULL);
	}
	size = ft_word_count(str);
	array = string_to_int(str);
	if (!array)
		return (NULL);
	if (check_int_array_values(array, size) == 0)
	{
		free(array);
		return (NULL);
	}
	list = create_list(array, size);
	free(array);
	return (list);
}

int	*stack_to_array(t_list *stack, int size)
{
	int			i;
	int			*array;
	t_list		*current;

	array = malloc(size * sizeof(int));
	if (!array)
		return (NULL);
	current = stack;
	i = 0;
	while (i < size && current)
	{
		array[i] = current->value;
		current = current->next;
		i++;
	}
	return (array);
}
