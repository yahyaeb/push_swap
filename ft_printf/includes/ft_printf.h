/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bouk <yel-bouk@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 14:45:43 by yel-bouk          #+#    #+#             */
/*   Updated: 2024/12/17 21:32:33 by yel-bouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

void	ft_putstr(char *s);
void	ft_putchar(char c);
size_t	ft_strlen(char *str);
int		ft_intlen(int n);
int		ft_unsigned_len(unsigned int n);
int		handle_strings(char *str);
int		handle_char(char c);
int		handle_pointers(void *ptr);
int		handle_unsigned(unsigned int num);
int		ft_putnbr(int n);
int		ft_putnbr_unsigned(unsigned int n);
int		ft_printf(const char *format, ...);
int		ft_print_pointer(uintptr_t num);
int		ft_putnbr_hex_upper(unsigned int num);
int		ft_putnbr_hex_lower(unsigned int num);
#endif
