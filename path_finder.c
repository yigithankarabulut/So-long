/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykarabul <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 19:13:37 by ykarabul          #+#    #+#             */
/*   Updated: 2023/03/02 16:35:47 by ykarabul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	recur_func(int **int_map, t_win *pnc, int x, int y)
{
	if (pnc->map->mappin[y][x] == 'P' || pnc->map->mappin[y][x] == 'C')
		pnc->i_map.read_count++;
	if (pnc->map->mappin[y][x + 1] != '1' && int_map[y][x + 1] < 1)
	{
		int_map[y][x + 1] = int_map[y][x] + 1;
		recur_func(int_map, pnc, x + 1, y);
	}
	if (pnc->map->mappin[y + 1][x] != '1' && int_map[y + 1][x] < 1)
	{
		int_map[y + 1][x] = int_map[y][x] + 1;
		recur_func(int_map, pnc, x, y + 1);
	}
	if (pnc->map->mappin[y][x - 1] != '1' && int_map[y][x - 1] < 1)
	{
		int_map[y][x - 1] = int_map[y][x] + 1;
		recur_func(int_map, pnc, x - 1, y);
	}
	if (pnc->map->mappin[y - 1][x] != '1' && int_map[y - 1][x] < 1)
	{
		int_map[y - 1][x] = int_map[y][x] + 1;
		recur_func(int_map, pnc, x, y - 1);
	}
	return (0);
}

static void	print(t_win *pnc, int **int_map, int print_active)
{
	int	x;
	int	k;

	x = 0;
	k = 0;
	if (print_active)
	{
		if (pnc->i_map.read_count == pnc->map->coin_cnt + 1)
			ft_printf("\n\n>>>> MAP OK\n");
		ft_printf("\n>>>>Accessible Objects: %d", pnc->i_map.read_count);
		ft_printf("\n\n↓ VIRTUAL MAP ↓\n");
		while (x < pnc->map->h)
		{
			k = 0;
			ft_printf("\n");
			while (k < pnc->map->w)
			{
				ft_printf("%d", int_map[x][k]);
				k++;
			}
			x++;
		}
		ft_printf(" \n\n");
	}
}

static void	int_map_free(int **int_map, t_win *pnc)
{
	int	i;

	i = 0;
	while (i < pnc->map->h)
	{
		free(int_map[i]);
		i++;
	}
	free(int_map);
}

void	placeholder(t_win *pnc, int x, int y, int print_active)
{
	int	**int_map;
	int	i;
	int	j;

	i = 0;
	j = 0;
	int_map = (int **)malloc(sizeof(int *) * pnc->map->h);
	while (i < pnc->map->h)
	{
		int_map[i] = (int *)malloc(sizeof(int) * pnc->map->w);
		j = 0;
		while (j < pnc->map->w)
		{
			int_map[i][j] = 0;
			j++;
		}
		i++;
	}
	int_map[y][x] = 1;
	pnc->i_map.read_count = 0;
	pnc->i_map.step_count = 0;
	recur_func(int_map, pnc, x, y);
	print(pnc, int_map, print_active);
	int_map_free(int_map, pnc);
}

void	path_finder(t_win *pnc)
{
	int	print_active;
	int	x;
	int	y;

	x = pnc->map->gate_x / 64;
	y = pnc->map->gate_y / 64;
	print_active = 1;
	placeholder(pnc, x, y, print_active);
	if (pnc->i_map.read_count != pnc->map->coin_cnt + 1)
	{
		write(1, "Map is wrong\n", 13);
		exit(0);
	}
}
