/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykarabul <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 13:36:50 by ykarabul          #+#    #+#             */
/*   Updated: 2023/03/02 11:00:49 by ykarabul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	path_controls(char *str)
{
	int	i;

	i = ft_strlen(str);
	if (str[i - 1] != 'r' || str[i - 2] != 'e'
		|| str[i - 3] != 'b' || str[i - 4] != '.')
	{
		write(1, "Path Error\n", 11);
		exit(1);
	}
}

void	map_controls(char *map)
{
	int	fd;

	fd = open(map, O_RDONLY);
	if (fd <= 0)
	{
		write(1, "Maps Not Here\n", 14);
		close(fd);
		exit(1);
	}
	close(fd);
}

void	player_control(t_win *pnc)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (pnc->map->mappin[i])
	{
		while (pnc->map->mappin[i][j])
		{
			if (pnc->map->mappin[i][j] == 'P')
				pnc->map->p_cnt += 1;
			j++;
		}
		j = 0;
		i++;
	}
	if (pnc->map->p_cnt != 1)
	{
		ft_printf("Player Error\n");
		close_pnc(pnc);
	}
}

void	maps_charcontrol(t_win *pnc)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (pnc->map->mappin[i])
	{
		while (pnc->map->mappin[i][j])
		{
			if ((pnc->map->mappin[i][j] != 'P')
			&& (pnc->map->mappin[i][j] != 'C')
			&& (pnc->map->mappin[i][j] != 'E')
			&& (pnc->map->mappin[i][j] != '1')
			&& (pnc->map->mappin[i][j] != '0'))
			{
				ft_printf("Undifened Char\n");
				close_pnc(pnc);
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void	coin_control(t_win *pnc)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (pnc->map->mappin[++i])
	{
		while (pnc->map->mappin[i][++j])
		{
			if (pnc->map->mappin[i][j] == 'C')
				pnc->map->coin_cnt += 1;
		}
		j = 0;
	}
	if (pnc->map->coin_cnt <= 0)
	{
		ft_printf("Coin Error\n");
		close_pnc(pnc);
	}
}
