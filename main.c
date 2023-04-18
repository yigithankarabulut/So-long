/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykarabul <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 13:33:48 by ykarabul          #+#    #+#             */
/*   Updated: 2023/03/02 17:05:51 by ykarabul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_img(t_win *pnc, int x, int y)
{
	pnc->height = pnc->map->h * 64;
	pnc->width = pnc->map->w * 64;
	pnc->mlx = mlx_init();
	pnc->win = mlx_new_window(pnc->mlx, pnc->width, pnc->height, "ft_Irobot");
	pnc->chr = ft_calloc(1, sizeof(t_char));
	pnc->chr->l_x = 0;
	pnc->chr->l_y = 0;
	pnc->chr->point = 0;
	pnc->chr->chr_front = mlx_xpm_file_to_image(pnc->mlx, \
			"./img/front_char.xpm", &x, &y);
	pnc->chr->chr_back = mlx_xpm_file_to_image(pnc->mlx, \
			"./img/back_char.xpm", &x, &y);
	pnc->chr->chr_cur = pnc->chr->chr_front;
	pnc->chr->chr_left = mlx_xpm_file_to_image(pnc->mlx, \
			"./img/left_char.xpm", &x, &y);
	pnc->chr->chr_right = mlx_xpm_file_to_image(pnc->mlx, \
			"./img/right_char.xpm", &x, &y);
	pnc->block_bg = mlx_xpm_file_to_image(pnc->mlx, \
			"./img/block.xpm", &x, &y);
	pnc->coin_bg = mlx_xpm_file_to_image(pnc->mlx, \
			"./img/coin.xpm", &x, &y);
	pnc->end_bg = mlx_xpm_file_to_image(pnc->mlx, \
			"./img/endgate.xpm", &x, &y);
	pnc->img_bg = mlx_xpm_file_to_image(pnc->mlx, \
			"./img/bg.xpm", &x, &y);
}

void	open_windows(t_win *pnc, char *path)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	pnc->map = read_map(path);
		system("leaks so_long");
		exit(0);
	get_img(pnc, x, y);
	player_control(pnc);
	map_lencontrol(pnc);
	wall_control(pnc);
	end_control(pnc);
	coin_control(pnc);
	maps_charcontrol(pnc);
}

int	main(int ac, char **av)
{
	t_win	pnc;

	if (ac == 2)
	{
		xpm_controls();
		xpm_controls2();
		path_controls(av[1]);
		map_controls(av[1]);
		open_windows(&pnc, av[1]);
		render_map(&pnc);
		path_finder(&pnc);
		mlx_hook(pnc.win, 2, 0, walk, &pnc);
		mlx_hook(pnc.win, 17, 0, close_pnc, &pnc);
		mlx_loop(pnc.mlx);
	}
	else
	{
		write(1, "missing argument\n", 18);
	}
	// system("leaks so_long");
	return (0);
}
