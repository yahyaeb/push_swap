/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bouk <yel-bouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:20:04 by yel-bouk          #+#    #+#             */
/*   Updated: 2025/01/07 19:21:23 by yel-bouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	validate_input(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && str[i] != ' '
			&& str[i] != '-' && str[i] != '+')
			return (0);
		if ((str[i] == '-' || str[i] == '+') && (!ft_isdigit(str[i + 1])
				|| (i > 0 && str[i - 1] != ' ')))
			return (0);
		i++;
	}
	return (1);
}

int *convert_to_int_array(char **array, int size) {
    int *int_array;
    int i;
    long value;

    int_array = malloc(size * sizeof(int));
    if (!int_array) {
        free_table(array);  // Ensure array is freed if int_array allocation fails
        return (NULL);
	}

    for (i = 0; i < size; i++) {
        value = ft_atoi(array[i]);  // Get the result of ft_atoi as long
        if (check_atoi_values(value)) {  // Check if the value is out of int bounds
            // Free only remaining elements to prevent double-free
            for (int j = i; j < size; j++) {
                free(array[j]);
            }
            free(array);
            free(int_array);  // Free the allocated int_array
            return (NULL);
        }
        int_array[i] = (int)value;  // Safe cast to int after validation
        free(array[i]);
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
	if(check_int_array_values(array, size) == 0)
	{
		free(array);
		return NULL;
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
