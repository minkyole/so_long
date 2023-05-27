/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyole <minkyole@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 19:45:21 by minkyole          #+#    #+#             */
/*   Updated: 2023/05/20 19:49:26 by minkyole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H
# include "mlx/mlx_bonus.h"
# include <fcntl.h>
# include <time.h>
# define KEY_ESC	53
# define KEY_UP		126
# define KEY_DOWN	125
# define KEY_LEFT	123
# define KEY_RIGHT	124
# define KEY_ATTACK	7

typedef struct s_map
{
	int		wi;
	int		he;
	int		x;
	void	*image;
	int		direction;
}			t_map;

typedef struct s_param
{
	t_map	user;
	t_map	user_sprite[8];
	t_map	wall;
	t_map	land;
	t_map	chase;
	t_map	potal[2];
	t_map	enemy_sprite[8];
	t_map	attack_sprite[24];
	t_map	keybord[10];
	void	*mlx;
	void	*win;
	int		move_cnt;
	int		win_width;
	int		win_height;
	int		collection;
	char	*map;
	int		check_attack;
	int		waitting_attack;
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

void			dfs(char *map, t_map_check *map_check, int player);
int				check_map_closed(char *map, t_map_check *map_check, int i);
int				check_map_item(char *map, t_map_check *map_check, int i);
void			init_map(t_map_check *map_check);
int				check_map(char *map);
int				check_map_name(char *arr);
void			main2(int fd, unsigned long long len);
int				main(int argc, char **argv);
int				move_land(int keycode, t_param *maps);
int				move_chase(int keycode, t_param *maps);
int				move_potal(int keycode, t_param *maps);
int				key_press(int keycode, t_param *maps);
int				draw(t_param *maps);
void			map_cnt(t_param *maps);
int				red_botton_delete(void);
int				so_long(char *game_map);
void			draw_image(int flag, t_param *maps, unsigned long long i);
void			user_move(t_param *maps, int flag);
void			error(int flag);
int				check_enemy(int keycode, t_param *maps);
void			check_enemy2(t_param *maps);
void			enemy_add(t_param *maps, int enemy, \
					int enemy_position, int cnt);
void			enemy_move(t_param *maps, int enemy_position);
void			move_enemy(t_param *maps, int flag, int enemy_position);
void			enemy_set(t_param *maps);
void			image_init(t_param *maps);
void			draw_user_l(int cnt, t_param *maps, unsigned long long i);
void			draw_user_r(int cnt, t_param *maps, unsigned long long i);
void			draw_enemy_r(int cnt, t_param *maps, unsigned long long i);
void			draw_enemy_l(int cnt, t_param *maps, unsigned long long i);
void			user_sprite_init(t_param *maps);
void			enemy_sprite_init(t_param *maps);
void			attack_sprite_init1(t_param *maps);
void			attack_sprite_init2(t_param *maps);
void			attack_sprite_init3(t_param *maps);
void			keybord_init(t_param *maps);
int				key_attack_left_right(int keycode, t_param *maps, int user);
int				key_attack_up_down(int keycode, t_param *maps);
void			draw_right_attack(int cnt, t_param *maps, int i, int width);
void			draw_left_attack(int cnt, t_param *maps, int i, int width);
void			draw_down_attack(int cnt, t_param *maps, int i, int width);
void			draw_up_attack(int cnt, t_param *maps, int i, int width);
void			draw_score1(int flag, t_param *maps, unsigned long long i);
void			draw_score2(int flag, t_param *maps, unsigned long long i);
#endif
