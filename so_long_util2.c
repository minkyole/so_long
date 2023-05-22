/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_util2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyole <minkyole@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 21:55:05 by minkyole          #+#    #+#             */
/*   Updated: 2023/05/22 14:51:49 by minkyole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"

void	draw_image(int flag, t_param *maps, unsigned long long i)
{
	if (flag == 1)
		mlx_put_image_to_window(maps->mlx, maps->win, \
			(maps->land).image, i % (maps->win_width + 1) * 64, \
			i / (maps->win_width + 1) * 64);
	else if (flag == 2)
		mlx_put_image_to_window(maps->mlx, maps->win, \
			(maps->wall).image, i % (maps->win_width + 1) * 64, \
			i / (maps->win_width + 1) * 64);
	else if (flag == 3)
		mlx_put_image_to_window(maps->mlx, maps->win, \
			(maps->user).image, i % (maps->win_width + 1) * 64, \
			i / (maps->win_width + 1) * 64);
	else if (flag == 4)
		mlx_put_image_to_window(maps->mlx, maps->win, \
			(maps->chase).image, i % (maps->win_width + 1) * 64, \
			i / (maps->win_width + 1) * 64);
	else if (flag == 5)
		mlx_put_image_to_window(maps->mlx, maps->win, \
			(maps->potal).image, i % (maps->win_width + 1) * 64, \
			i / (maps->win_width + 1) * 64);
/*
	else if (flag == 6)
		mlx_put_image_to_window(maps->mlx, maps->win, \
			(maps->enemy).image, i % (maps->win_width + 1) * 64, \
			i / (maps->win_width + 1) * 64);
			*/
}

void	draw_enemy_r(int cnt, t_param *maps, unsigned long long i)
{
	if (cnt % 80 <= 20)
		mlx_put_image_to_window(maps->mlx, maps->win, \
			(maps->enemy_sprite[0]).image, i % (maps->win_width + 1) * 64, \
			i / (maps->win_width + 1) * 64);
	else if (cnt % 80 <= 40)
		mlx_put_image_to_window(maps->mlx, maps->win, \
			(maps->enemy_sprite[1]).image, i % (maps->win_width + 1) * 64, \
			i / (maps->win_width + 1) * 64);
	else if (cnt % 80 <= 60)
		mlx_put_image_to_window(maps->mlx, maps->win, \
			(maps->enemy_sprite[2]).image, i % (maps->win_width + 1) * 64, \
			i / (maps->win_width + 1) * 64);
	else
		mlx_put_image_to_window(maps->mlx, maps->win, \
			(maps->enemy_sprite[3]).image, i % (maps->win_width + 1) * 64, \
			i / (maps->win_width + 1) * 64);
}

void	draw_enemy_l(int cnt, t_param *maps, unsigned long long i)
{
	if (cnt % 80 <= 20)
		mlx_put_image_to_window(maps->mlx, maps->win, \
			(maps->enemy_sprite[4]).image, i % (maps->win_width + 1) * 64, \
			i / (maps->win_width + 1) * 64);
	else if (cnt % 80 <= 40)
		mlx_put_image_to_window(maps->mlx, maps->win, \
			(maps->enemy_sprite[5]).image, i % (maps->win_width + 1) * 64, \
			i / (maps->win_width + 1) * 64);
	else if (cnt % 80 <= 60)
		mlx_put_image_to_window(maps->mlx, maps->win, \
			(maps->enemy_sprite[6]).image, i % (maps->win_width + 1) * 64, \
			i / (maps->win_width + 1) * 64);
	else
		mlx_put_image_to_window(maps->mlx, maps->win, \
			(maps->enemy_sprite[7]).image, i % (maps->win_width + 1) * 64, \
			i / (maps->win_width + 1) * 64);
}

void	draw_user(int cnt, t_param *maps, unsigned long long i, int direction)
{
	if (direction == 1)
	{
		if (cnt % 80 <= 20)
			mlx_put_image_to_window(maps->mlx, maps->win, \
				(maps->user_sprite[0]).image, i % (maps->win_width + 1) * 64, \
				i / (maps->win_width + 1) * 64);
		else if (cnt % 80 <= 40)
			mlx_put_image_to_window(maps->mlx, maps->win, \
				(maps->user_sprite[1]).image, i % (maps->win_width + 1) * 64, \
				i / (maps->win_width + 1) * 64);
		else if (cnt % 80 <= 60)
			mlx_put_image_to_window(maps->mlx, maps->win, \
				(maps->user_sprite[2]).image, i % (maps->win_width + 1) * 64, \
				i / (maps->win_width + 1) * 64);
		else
			mlx_put_image_to_window(maps->mlx, maps->win, \
				(maps->user_sprite[3]).image, i % (maps->win_width + 1) * 64, \
				i / (maps->win_width + 1) * 64);
	}
	else if (direction == 2)
	{
		if (cnt % 80 <= 20)
			mlx_put_image_to_window(maps->mlx, maps->win, \
				(maps->user_sprite[4]).image, i % (maps->win_width + 1) * 64, \
				i / (maps->win_width + 1) * 64);
		else if (cnt % 80 <= 40)
			mlx_put_image_to_window(maps->mlx, maps->win, \
				(maps->user_sprite[5]).image, i % (maps->win_width + 1) * 64, \
				i / (maps->win_width + 1) * 64);
		else if (cnt % 80 <= 60)
			mlx_put_image_to_window(maps->mlx, maps->win, \
				(maps->user_sprite[6]).image, i % (maps->win_width + 1) * 64, \
				i / (maps->win_width + 1) * 64);
		else
			mlx_put_image_to_window(maps->mlx, maps->win, \
				(maps->user_sprite[7]).image, i % (maps->win_width + 1) * 64, \
				i / (maps->win_width + 1) * 64);
	}
}

int	draw(t_param *maps)
{
	unsigned long long	i;
	static long long	cnt;

	i = 0;
	while (i < ft_strlen(maps->map))
	{
		draw_image(1, maps, i);
		if (maps->map[i] == '1')
			draw_image(2, maps, i);
		else if (maps->map[i] == 'P')
		{
			draw_user(cnt, maps, i, maps->user.direction);
			maps->user.x = i;
		}
		else if (maps->map[i] == 'C')
			draw_image(4, maps, i);
		else if (maps->map[i] == 'E')
			draw_image(5, maps, i);
		else if (maps->map[i] == 'R')
			draw_enemy_r(cnt, maps, i);
		else if (maps->map[i] == 'L')
			draw_enemy_l(cnt, maps, i);
		i++;
	}
	cnt++;
	return (0);
}

void	map_cnt(t_param *maps)
{
	int	i;
	int	max_win_width;
	int	max_win_height;

	maps->win_height = 0;
	maps->win_width = 0;
	maps->collection = 0;
	i = 0;
	while (maps->map[i])
	{
		if (maps->map[i] == '\n')
			maps->win_height += 1;
		else if (maps->map[i] == 'C')
			maps->collection += 1;
		i++;
	}
	maps->win_width = (i - maps->win_height) / maps->win_height;
	mlx_get_screen_size(maps->mlx, &max_win_width, &max_win_height);
	if (max_win_width < maps->win_width * 64 || \
	max_win_height < maps->win_height * 64)
		error(4);
	maps->move_cnt = 0;
}

void	image_init(t_param *maps)
{
	maps->win = mlx_new_window(maps->mlx, maps->win_width * 64, \
			maps->win_height * 64, "DrawMap");
	maps->user.image = mlx_xpm_file_to_image(maps->mlx, \
			"texture/p.xpm", &maps->user.he, &maps->user.he);
	maps->wall.image = mlx_xpm_file_to_image(maps->mlx, \
			"texture/1.xpm", &maps->wall.he, &maps->wall.he);
	maps->land.image = mlx_xpm_file_to_image(maps->mlx, \
			"texture/0.xpm", &maps->land.he, &maps->land.he);
	maps->chase.image = mlx_xpm_file_to_image(maps->mlx, \
			"texture/c.xpm", &maps->chase.he, &maps->chase.he);
	maps->potal.image = mlx_xpm_file_to_image(maps->mlx, \
			"texture/e.xpm", &maps->potal.he, &maps->potal.he);
	maps->enemy_sprite[0].image = mlx_xpm_file_to_image(maps->mlx, \
			"texture/rg1.xpm", &maps->enemy_sprite[0].he, &maps->enemy_sprite[0].he);
	maps->enemy_sprite[1].image = mlx_xpm_file_to_image(maps->mlx, \
			"texture/rg2.xpm", &maps->enemy_sprite[1].he, &maps->enemy_sprite[1].he);
	maps->enemy_sprite[2].image = mlx_xpm_file_to_image(maps->mlx, \
			"texture/rg3.xpm", &maps->enemy_sprite[2].he, &maps->enemy_sprite[2].he);
	maps->enemy_sprite[3].image = mlx_xpm_file_to_image(maps->mlx, \
			"texture/rg4.xpm", &maps->enemy_sprite[3].he, &maps->enemy_sprite[3].he);
	maps->enemy_sprite[4].image = mlx_xpm_file_to_image(maps->mlx, \
			"texture/lg1.xpm", &maps->enemy_sprite[4].he, &maps->enemy_sprite[4].he);
	maps->enemy_sprite[5].image = mlx_xpm_file_to_image(maps->mlx, \
			"texture/lg2.xpm", &maps->enemy_sprite[5].he, &maps->enemy_sprite[5].he);
	maps->enemy_sprite[6].image = mlx_xpm_file_to_image(maps->mlx, \
			"texture/lg3.xpm", &maps->enemy_sprite[6].he, &maps->enemy_sprite[6].he);
	maps->enemy_sprite[7].image = mlx_xpm_file_to_image(maps->mlx, \
			"texture/lg4.xpm", &maps->enemy_sprite[7].he, &maps->enemy_sprite[7].he);
	maps->user_sprite[0].image = mlx_xpm_file_to_image(maps->mlx, \
			"texture/rp1.xpm", &maps->user_sprite[0].he, &maps->user_sprite[0].he);
	maps->user_sprite[1].image = mlx_xpm_file_to_image(maps->mlx, \
			"texture/rp2.xpm", &maps->user_sprite[1].he, &maps->user_sprite[1].he);
	maps->user_sprite[2].image = mlx_xpm_file_to_image(maps->mlx, \
			"texture/rp3.xpm", &maps->user_sprite[2].he, &maps->user_sprite[2].he);
	maps->user_sprite[3].image = mlx_xpm_file_to_image(maps->mlx, \
			"texture/rp4.xpm", &maps->user_sprite[3].he, &maps->user_sprite[3].he);
	maps->user_sprite[4].image = mlx_xpm_file_to_image(maps->mlx, \
			"texture/lp1.xpm", &maps->user_sprite[4].he, &maps->user_sprite[4].he);
	maps->user_sprite[5].image = mlx_xpm_file_to_image(maps->mlx, \
			"texture/lp2.xpm", &maps->user_sprite[5].he, &maps->user_sprite[5].he);
	maps->user_sprite[6].image = mlx_xpm_file_to_image(maps->mlx, \
			"texture/lp3.xpm", &maps->user_sprite[6].he, &maps->user_sprite[6].he);
	maps->user_sprite[7].image = mlx_xpm_file_to_image(maps->mlx, \
			"texture/lp4.xpm", &maps->user_sprite[7].he, &maps->user_sprite[7].he);
}

int	so_long(char *game_map)
{
	t_param	maps;

	maps.map = game_map;
	map_cnt(&maps);
	enemy_add(&maps);
	maps.mlx = mlx_init();
	image_init(&maps);
	maps.user.x = 0;
	maps.user.direction = 1;
	mlx_key_hook(maps.win, &key_press, &maps);
	mlx_loop_hook(maps.mlx, &draw, &maps);
	mlx_hook(maps.win, 17, 0, &red_botton_delete, &maps);
	mlx_loop(maps.mlx);
	return (0);
}
