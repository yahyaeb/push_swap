/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bouk <yel-bouk@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:47:56 by yel-bouk          #+#    #+#             */
/*   Updated: 2024/12/19 16:43:48 by yel-bouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
// Allocates memory for an array of `count` elements 
//of `size` bytes each and initializes all bytes to zero.
void	*ft_calloc(size_t count, size_t size)
{
	char	*str;

	str = malloc((count * size));
	if (!str)
		return (NULL);
	ft_bzero(str, size * count);
	return (str);
}
