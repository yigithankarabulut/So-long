/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykarabul <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 02:50:38 by ykarabul          #+#    #+#             */
/*   Updated: 2022/12/24 02:50:38 by ykarabul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>
# include <unistd.h>
# include <stdbool.h>
# include <stdarg.h>

int	ft_printf(const char *str, ...);
int	ft_format(va_list *args, char c);
int	ft_int(int a);
int	ft_hex(unsigned int a, char c);
int	ft_point(unsigned long a, int sign);
int	ft_string(char *str);
int	ft_unsigned(unsigned int a);

#endif