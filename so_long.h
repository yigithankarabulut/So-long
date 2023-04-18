/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykarabul <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 22:19:47 by ykarabul          #+#    #+#             */
/*   Updated: 2023/03/02 16:44:03 by ykarabul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./minilibx/mlx.h"
# include "./libft/libft.h"
# include "./printf/ft_printf.h"
# include <stdlib.h>
# include <fcntl.h>
# include "./gnl/get_next_line.h"

typedef struct s_char
{
	int		l_x;
	int		l_y;
	int		point;
	void	*chr_front;
	void	*chr_back;
	void	*chr_left;
	void	*chr_right;
	void	*chr_cur;
}	t_char;

typedef struct s_map
{
	char	**mappin;
	int		w;
	int		h;
	int		cb;
	int		gate_x;
	int		gate_y;
	int		p_cnt;
	int		end_cnt;
	int		coin_cnt;
}	t_map;

typedef struct l_int_map
{
	int		read_count;
	int		step_count;
}			t_int_map;

typedef struct s_win
{
	t_map		*map;
	t_char		*chr;
	t_int_map	i_map;
	void		*win;
	void		*mlx;
	void		*img_bg;
	void		*block_bg;
	void		*coin_bg;
	void		*end_bg;
	int			height;
	int			width;
}	t_win;

void	path_finder(t_win *pnc);
void	placeholder(t_win *list, int x, int y, int print_active);
void	open_windows(t_win *pnc, char *path);
void	path_controls(char *str);
void	map_controls(char *map);
void	endln_control(char *line);
char	*read_file(char *path, t_map *map);
t_map	*read_map(char *path);
void	player_control(t_win *pnc);
int		close_pnc(void *param);
void	map_lencontrol(t_win *pnc);
void	wall_control(t_win *pnc);
void	end_control(t_win *pnc);
void	coin_control(t_win *pnc);
void	maps_charcontrol(t_win *pnc);
void	render_map(t_win *pnc);
void	render_element(char c, t_win *pnc, int x, int y);
void	score_plus(t_win *pnc);
int		walk(int keycode, void *param);
void	xpm_controls(void);
void	xpm_controls2(void);

#endif
