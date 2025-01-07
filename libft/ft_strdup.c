/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bouk <yel-bouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 14:42:26 by yel-bouk          #+#    #+#             */
/*   Updated: 2025/01/06 17:29:17 by yel-bouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

char	*ft_strdup(char *str)
{
	char	*cpy;
	int		len;

	len = ft_strlen(str) + 1;
	cpy = malloc((len) * sizeof(char));
	if (!cpy)
		return (NULL);
	ft_strlcpy(cpy, str, len);
	return (cpy);
}
