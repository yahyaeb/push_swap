/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bouk <yel-bouk@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:20:04 by yel-bouk          #+#    #+#             */
/*   Updated: 2025/01/01 21:39:34 by yel-bouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int validate_input(char *str)
{
    int i = 0;

    while (str[i])
    {
        if (!ft_isdigit(str[i]) && str[i] != ' ' && str[i] != '-' && str[i] != '+')
            return 0;
        if ((str[i] == '-' || str[i] == '+') && (!ft_isdigit(str[i + 1]) || 
            (i > 0 && str[i - 1] != ' ')))
            return 0;
        i++;
    }
    return 1;
}
//char *array[] = {"42", "-15", "0", "23", "99"};
//int *array[] = {42, -15, 0, 23, 99};
int *convert_to_int_array(char **array, int size)
{
    int *int_array = malloc(size * sizeof(int));
    int i = 0;

    if (!int_array)
        return NULL;

    while (i < size)
    {
        int_array[i] = ft_atoi(array[i]);
        free(array[i]);
        i++;
    }
    free(array);
    return int_array;
}
//char *str = "42 -15 0 23 99";
//int *int_array = {42, -15, 0, 23, 99};
int *string_to_int(char *str)
{
    int size;
    char **array;
    int *int_array;

    if (!validate_input(str))
    {
        ft_printf("Error\n");
        return NULL;
    }

    array = ft_split(str, ' ');
    if (!array)
        return NULL;

    size = ft_wordcount(str, ' '); // Libft function to count words
    int_array = convert_to_int_array(array, size);
    return int_array;
}
t_list *input_taker(char *str)
{
    int size;
    int *array;
    t_list *list;

    if (!str || !*str) // Check for NULL or empty input
    {
        ft_printf("Error\n");
        return NULL;
    }

    size = ft_wordcount(str, ' '); // Libft function to count words
    array = string_to_int(str);    // Convert input string to integer array

    if (!array)
    {
        ft_printf("Error\n");
        return NULL;
    }

    list = create_list(array, size);
    free(array);                 
    return list;
}
int *stack_to_array(t_list *stack, int size) {
    int *array = malloc(size * sizeof(int));
    t_list *current = stack;
    for (int i = 0; i < size; i++) {
        array[i] = current->value;
        current = current->next;
    }
    return array;
}
