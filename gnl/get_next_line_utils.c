/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykarabul <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 00:15:46 by ykarabul          #+#    #+#             */
/*   Updated: 2023/03/02 00:57:08 by ykarabul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	f_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (*str++)
		i++;
	return (i);
}

char	*f_strdup(const char *s1)
{
	char	*str;
	size_t	i;

	if (!s1)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (f_strlen((char *)s1) + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (*s1)
	{
		str[i] = *s1;
		s1++;
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*f_strjoin(char *str, char *str2)
{
	char	*ret;
	int		i;

	i = 0;
	ret = (char *)malloc(sizeof(char) * (f_strlen(str) + f_strlen(str2) + 1));
	if (!ret)
		return (0);
	while (str && *str)
		ret[i++] = *str++;
	while (str2 && *str2)
		ret[i++] = *str2++;
	ret[i] = '\0';
	return (ret);
}

char	*f_substr(char *s, unsigned int start, size_t len)
{
	char	*ret;
	char	*start_ptr;
	size_t	i;

	if (s == NULL)
		return (NULL);
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (ret == NULL)
		return (NULL);
	start_ptr = (char *)s + start;
	i = 0;
	while (i < len && *start_ptr)
	{
		ret[i] = *start_ptr;
		start_ptr++;
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

char	*f_strchr(const char *s, int c)
{
	while (s && *s)
		if (*s++ == (char)c)
			return ((char *)s);
	return (NULL);
}
