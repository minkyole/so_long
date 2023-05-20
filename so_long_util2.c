/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_util2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyole <minkyole@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 21:55:05 by minkyole          #+#    #+#             */
/*   Updated: 2023/05/20 21:55:06 by minkyole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"

void	draw_image(int flag, t_param *maps, unsigned long long i)
{
	if (flag == 1)
		mlx_put_image_to_window(maps->mlx, maps->win, \
			(maps->land).image, i % (maps->win_width + 1) * 32, \
			i / (maps->win_width + 1) * 32);
	else if (flag == 2)
		mlx_put_image_to_window(maps->mlx, maps->win, \
			(maps->wall).image, i % (maps->win_width + 1) * 32, \
			i / (maps->win_width + 1) * 32);
	else if (flag == 3)
		mlx_put_image_to_window(maps->mlx, maps->win, \
			(maps->user).image, i % (maps->win_width + 1) * 32, \
			i / (maps->win_width + 1) * 32);
	else if (flag == 4)
		mlx_put_image_to_window(maps->mlx, maps->win, \
			(maps->chase).image, i % (maps->win_width + 1) * 32, \
			i / (maps->win_width + 1) * 32);
	else if (flag == 5)
		mlx_put_image_to_window(maps->mlx, maps->win, \
			(maps->potal).image, i % (maps->win_width + 1) * 32, \
			i / (maps->win_width + 1) * 32);
}

int	draw(t_param *maps)
{
	unsigned long long	i;

	i = 0;
	mlx_clear_window(maps->mlx, maps->win);
	while (i < ft_strlen(maps->map))
	{
		draw_image(1, maps, i);
		if (maps->map[i] == '1')
			draw_image(2, maps, i);
		else if (maps->map[i] == 'P')
		{
			draw_image(3, maps, i);
			(maps->user).x = i;
		}
		else if (maps->map[i] == 'C')
			draw_image(4, maps, i);
		else if (maps->map[i] == 'E')
			draw_image(5, maps, i);
		i++;
	}
	return (0);
}

int	red_botton_delete(void)
{
	exit(0);
}

void	map_cnt(char *temp, t_param *maps)
{
	int	x;
	int	y;
	int	i;
	int	c;

	i = 0;
	y = 0;
	c = 0;
	while (temp[i])
	{
		if (temp[i] == '\n')
			y++;
		else if (temp[i] == 'C')
			c++;
		i++;
	}
	x = (i - y) / y;
	maps->win_width = x;
	maps->win_height = y;
	maps->collection = c;
	maps->move_cnt = 0;
}

int	so_long(char *game_map)
{
	t_param	maps;

	maps.map = game_map;
	map_cnt(maps.map, &maps);
	maps.mlx = mlx_init();
	maps.win = mlx_new_window(maps.mlx, maps.win_width * 32, \
			maps.win_height * 32, "DrawMap");
	maps.user.image = mlx_xpm_file_to_image(maps.mlx, \
			"imgs/p.xpm", &maps.user.he, &maps.user.he);
	maps.wall.image = mlx_xpm_file_to_image(maps.mlx, \
			"imgs/1.xpm", &maps.wall.he, &maps.wall.he);
	maps.land.image = mlx_xpm_file_to_image(maps.mlx, \
			"imgs/0.xpm", &maps.land.he, &maps.land.he);
	maps.chase.image = mlx_xpm_file_to_image(maps.mlx, \
			"imgs/c.xpm", &maps.chase.he, &maps.chase.he);
	maps.potal.image = mlx_xpm_file_to_image(maps.mlx, \
			"imgs/e.xpm", &maps.potal.he, &maps.potal.he);
	maps.user.x = 0;
	maps.user.y = 0;
	mlx_key_hook(maps.win, &key_press, &maps);
	mlx_loop_hook(maps.mlx, &draw, &maps);
	mlx_hook(maps.win, 17, 0, &red_botton_delete, &maps);
	mlx_loop(maps.mlx);
	return (0);
}
