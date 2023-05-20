/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyole <minkyole@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 19:45:21 by minkyole          #+#    #+#             */
/*   Updated: 2023/05/20 19:49:26 by minkyole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "mlx/mlx.h"
# include <fcntl.h>
# define KEY_ESC	53
# define KEY_UP		126
# define KEY_DOWN	125
# define KEY_LEFT	123
# define KEY_RIGHT	124

typedef struct s_map
{
	int		wi;
	int		he;
	int		x;
	int		y;
	void	*image;
}			t_map;

typedef struct s_param
{
	t_map	user;
	t_map	wall;
	t_map	land;
	t_map	chase;
	t_map	potal;
	void	*mlx;
	void	*win;
	int		move_cnt;
	int		win_width;
	int		win_height;
	int		collection;
	char	*map;
}			t_param;

typedef struct s_map_check
{
	int	x;
	int	y;
	int	player;
	int	dfs_c;
	int	dfs_e;
	int	c;
	int	p;
	int	e;
	int	*dfs_map;
}		t_map_check;

void	dfs(char *map, t_map_check *map_check, int player);
int		check_map_closed(char *map, t_map_check *map_check, int i);
int		check_map_item(char *map, t_map_check *map_check, int i);
void	init_map(t_map_check *map_check);
int		check_map(char *map);
int		check_map_name(char *arr);
void	main2(int fd, unsigned long long len);
int		main(int argc, char **argv);
int		move_land(int keycode, t_param *maps);
int		move_chase(int keycode, t_param *maps);
int		move_potal(int keycode, t_param *maps);
int		key_press(int keycode, t_param *maps);
int		draw(t_param *maps);
void	map_cnt(char *temp, t_param *maps);
int		red_botton_delete(void);
int		so_long(char *game_map);
void	draw_image(int flag, t_param *maps, unsigned long long i);
void	user_move(t_param *maps, int flag);

#endif
