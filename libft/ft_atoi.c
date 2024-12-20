/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bouk <yel-bouk@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:29:40 by yel-bouk          #+#    #+#             */
/*   Updated: 2024/12/19 16:43:41 by yel-bouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Description: Converts a string to an integer

#include "../includes/push_swap.h"

int	ft_atoi(const char *str)
{
	size_t		i;
	int			sign;
	int			results;

	i = 0;
	sign = 1;
	results = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-')
	{
		sign = sign * -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		results = results * 10 + (str[i] - '0');
		i++;
	}
	return (results * sign);
}
