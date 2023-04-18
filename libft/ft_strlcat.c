/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykarabul <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 00:24:34 by ykarabul          #+#    #+#             */
/*   Updated: 2022/12/18 00:24:34 by ykarabul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t	i;
	size_t	a;
	size_t	d;
	size_t	s;

	a = ft_strlen(dst);
	d = ft_strlen(dst);
	s = ft_strlen(src);
	i = 0;
	if (n <= d)
		return (n + s);
	while (src[i] && a < n - 1)
	{
		dst[a] = src[i];
		i++;
		a++;
	}
	dst[a] = '\0';
	return (d + s);
}
