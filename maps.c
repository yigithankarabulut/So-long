/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykarabul <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:53:46 by ykarabul          #+#    #+#             */
/*   Updated: 2023/03/02 17:06:08 by ykarabul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	endln_control(char *line)
{
	if (*line == '\n')
	{
		write(1, "Empty Line In Map\n", 19);
		free (line);
		exit(1);
	}
}
	// system("leaks so_long");
	// 	exit(0);
char	*read_file(char *path, t_map *map)
{
	char	*line;
	char	*buff;
	int		fd;
	int		i;

	i = -1;
	fd = open(path, O_RDONLY);
	buff = NULL;
	line = NULL;
	while (1)
	{
		free (line);
		line = get_next_line(fd);
		if (!line)
			break ;
		endln_control(line);
		while (line[++i])
			if (line[i] == 'C')
				map->cb += 1;
		i = -1;
		strappend(&buff, line);
	}
	close(fd);
	free (line);
	return (buff);
}

t_map	*read_map(char *path)
{
	t_map	*ret;
	char	*map;

	ret = ft_calloc(1, sizeof(t_map));
	map = read_file(path, ret);
	ret->mappin = ft_split(map, '\n');
	ret->h = 0;
	while (ret->mappin[ret->h])
		ret->h++;
	ret->w = ft_strlen(ret->mappin[0]);
	free (map);
	return (ret);
}
