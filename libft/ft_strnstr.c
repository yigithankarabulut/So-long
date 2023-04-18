/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykarabul <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 21:20:14 by ykarabul          #+#    #+#             */
/*   Updated: 2022/12/17 21:20:14 by ykarabul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	n_len;

	i = 0;
	n_len = ft_strlen(needle);
	if (!haystack)
		return (NULL);
	if (!n_len || haystack == needle)
		return ((char *)haystack);
	while (((char *)(haystack))[i] != '\0' && i < len)
	{
		j = 0;
		while (((char *)(haystack))[i + j] && needle[j] &&
		(((char *)(haystack))[i + j] == needle[j] && i + j < len))
			j++;
		if (j == n_len)
			return ((char *)haystack + i);
		i++;
	}
	return (NULL);
}
