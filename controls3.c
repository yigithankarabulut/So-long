/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykarabul <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 17:21:42 by ykarabul          #+#    #+#             */
/*   Updated: 2023/03/02 11:33:46 by ykarabul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	str_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	close_pnc(void *param)
{
	int		i;
	t_win	*pnc;

	pnc = param;
	i = 0;
	mlx_destroy_image(pnc->mlx, pnc->chr->chr_front);
	mlx_destroy_image(pnc->mlx, pnc->chr->chr_back);
	mlx_destroy_image(pnc->mlx, pnc->chr->chr_right);
	mlx_destroy_image(pnc->mlx, pnc->chr->chr_left);
	mlx_destroy_image(pnc->mlx, pnc->block_bg);
	mlx_destroy_image(pnc->mlx, pnc->coin_bg);
	mlx_destroy_image(pnc->mlx, pnc->end_bg);
	mlx_destroy_image(pnc->mlx, pnc->img_bg);
	free(pnc->chr);
	while (pnc->map->mappin[i])
		free(pnc->map->mappin[i++]);
	free(pnc->map->mappin);
	free(pnc->map);
	mlx_destroy_window(pnc->mlx, pnc->win);
	exit(1);
	return (1);
}

void	map_lencontrol(t_win *pnc)
{
	int	len;
	int	i;

	len = pnc->map->w;
	i = 0;
	while (pnc->map->mappin[i])
	{
		if (str_len(pnc->map->mappin[i]) != len)
		{
			ft_printf("Map Size Error\n");
			close_pnc(pnc);
		}
		i++;
	}
}

void	wall_control(t_win *pnc)
{
	int	i;
	int	last;

	i = -1;
	while (pnc->map->mappin[0][++i])
	{
		if (pnc->map->mappin[0][i] != '1' ||
			pnc->map->mappin[pnc->map->h - 1][i] != '1')
		{
			write(1, "Wall Error\n", 12);
			close_pnc(pnc);
		}
	}
	i = -1;
	last = pnc->map->w - 1;
	while (pnc->map->mappin[++i])
	{
		if (pnc->map->mappin[i][0] != '1' || pnc->map->mappin[i][last] != '1')
		{
			write(1, "Wall Error\n", 12);
			close_pnc(pnc);
		}
	}
}

void	end_control(t_win *pnc)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (pnc->map->mappin[i])
	{
		while (pnc->map->mappin[i][j])
		{
			if (pnc->map->mappin[i][j] == 'E')
				pnc->map->end_cnt += 1;
			j++;
		}
		j = 0;
		i++;
	}
	if (pnc->map->end_cnt != 1)
	{
		ft_printf("End Gate Error\n");
		close_pnc(pnc);
	}
}
