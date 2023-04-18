/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykarabul <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 13:34:26 by ykarabul          #+#    #+#             */
/*   Updated: 2023/03/02 10:11:43 by ykarabul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	xpm_controls(void)
{
	int	fd_bchar;
	int	fd_lchar;
	int	fd_fchar;
	int	fd_rchar;

	fd_bchar = open("./img/back_char.xpm", O_RDONLY);
	fd_lchar = open("./img/left_char.xpm", O_RDONLY);
	fd_fchar = open("./img/front_char.xpm", O_RDONLY);
	fd_rchar = open("./img/right_char.xpm", O_RDONLY);
	if (fd_bchar <= 0 || fd_fchar <= 0 || fd_lchar <= 0 || fd_rchar <= 0)
	{
		write (1, "Images Error\n", 13);
		close(fd_bchar);
		close(fd_lchar);
		close(fd_rchar);
		close(fd_fchar);
		exit(1);
	}
	close(fd_bchar);
	close(fd_lchar);
	close(fd_rchar);
	close(fd_fchar);
}

void	xpm_controls2(void)
{
	int	fd_bg;
	int	fd_block;
	int	fd_coin;
	int	fd_end;

	fd_bg = open("./img/bg.xpm", O_RDONLY);
	fd_block = open("./img/bg.xpm", O_RDONLY);
	fd_coin = open("./img/bg.xpm", O_RDONLY);
	fd_end = open("./img/bg.xpm", O_RDONLY);
	if (fd_bg <= 0 || fd_block <= 0 || fd_coin <= 0 || fd_end <= 0)
	{
		write(1, "Images Error\n", 13);
		close(fd_bg);
		close(fd_block);
		close(fd_coin);
		close(fd_end);
		exit(1);
	}
	close(fd_bg);
	close(fd_block);
	close(fd_coin);
	close(fd_end);
}
