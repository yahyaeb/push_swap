/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argc_to_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bouk <yel-bouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 14:40:30 by yel-bouk          #+#    #+#             */
/*   Updated: 2025/01/07 18:30:03 by yel-bouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

char	*convert_args_to_string(int argc, char **argv)
{
	char	*result;
	char	*temp;
	int		i;

	result = ft_strdup("");
	if (!result)
		return (NULL);
	i = 1;
	while (i < argc)
	{
		temp = result;
		result = ft_strjoin(result, argv[i]);
		free(temp);
		if (i < argc - 1)
		{
			temp = result;
			result = ft_strjoin(result, " ");
			free(temp);
		}
		i++;
	}
	return (result);
}
