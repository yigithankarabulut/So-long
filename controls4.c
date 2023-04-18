/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykarabul <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 20:40:31 by ykarabul          #+#    #+#             */
/*   Updated: 2023/03/01 23:27:07 by ykarabul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_element(char c, t_win *pnc, int x, int y)
{
	mlx_put_image_to_window(pnc->mlx, pnc->win, pnc->img_bg, x, y);
	if (c == 'P')
	{
		pnc->chr->l_x = x;
		pnc->chr->l_y = y;
		mlx_put_image_to_window(pnc->mlx, pnc->win, pnc->chr->chr_cur, x, y);
	}
	if (c == '1')
		mlx_put_image_to_window(pnc->mlx, pnc->win, pnc->block_bg, x, y);
	if (c == 'C')
		mlx_put_image_to_window(pnc->mlx, pnc->win, pnc->coin_bg, x, y);
	if (c == 'E')
	{
		pnc->map->gate_x = x;
		pnc->map->gate_y = y;
		mlx_put_image_to_window(pnc->mlx, pnc->win, pnc->end_bg, x, y);
	}
}

void	score_plus(t_win *pnc)
{
	char	*score;

	score = ft_itoa(pnc->chr->point);
	mlx_string_put(pnc->mlx, pnc->win, 20, 20, 0xFFFFFFFF, score);
	free(score);
}

void	render_map(t_win *pnc)
{
	int	i;
	int	j;
	int	x;
	int	y;

	x = 0;
	y = 0;
	i = 0;
	j = 0;
	while (pnc->map->mappin[i])
	{
		x = 0;
		j = 0;
		while (pnc->map->mappin[i][j])
		{
			render_element(pnc->map->mappin[i][j], pnc, x, y);
			score_plus(pnc);
			x += 64;
			j++;
		}
		y += 64;
		i++;
	}
}
