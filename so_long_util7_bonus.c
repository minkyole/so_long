/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_util7_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyole <minkyole@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 14:47:21 by minkyole          #+#    #+#             */
/*   Updated: 2023/05/27 14:47:27 by minkyole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include "libft.h"

void	move_enemy(t_param *maps, int flag, int enemy_position)
{
	if (flag == 1)
	{
		(maps->map)[enemy_position] = '0';
		(maps->map)[enemy_position - maps->win_width - 1] = 'l';
	}
	else if (flag == 2)
	{
		(maps->map)[enemy_position] = '0';
		(maps->map)[enemy_position + maps->win_width + 1] = 'r';
	}
	else if (flag == 3)
	{
		(maps->map)[enemy_position] = '0';
		(maps->map)[enemy_position - 1] = 'l';
	}
	else if (flag == 4)
	{
		(maps->map)[enemy_position] = '0';
		(maps->map)[enemy_position + 1] = 'r';
	}
}

void	enemy_move(t_param *maps, int enemy_position)
{
	int	keycode;
	int	cnt;

	cnt = 0;
	while (1)
	{
		keycode = (rand() % 4) + 123;
		if (keycode == KEY_UP && \
				(maps->map)[enemy_position - maps->win_width - 1] == '0')
			return (move_enemy(maps, 1, enemy_position));
		else if (keycode == KEY_DOWN && \
				(maps->map)[enemy_position + maps->win_width + 1] == '0')
			return (move_enemy(maps, 2, enemy_position));
		else if (keycode == KEY_LEFT && (maps->map)[enemy_position - 1] == '0')
			return (move_enemy(maps, 3, enemy_position));
		else if (keycode == KEY_RIGHT && (maps->map)[enemy_position + 1] == '0')
			return (move_enemy(maps, 4, enemy_position));
		cnt++;
		if (cnt == 10)
			return ;
	}
}

void	enemy_add(t_param *maps, int enemy, int enemy_position, int cnt)
{
	if (maps->win_width * maps->win_height < 90)
		enemy = 1;
	else if (maps->win_width * maps->win_height < 150)
		enemy = 2;
	else if (maps->win_width * maps->win_height < 210)
		enemy = 3;
	else if (maps->win_width * maps->win_height < 270)
		enemy = 4;
	else
		enemy = 5;
	srand(time(NULL));
	while (enemy != 0 && cnt != 0)
	{
		enemy_position = rand() % ((maps->win_width + 1) * maps->win_height);
		if ((maps->map)[enemy_position] == '0')
		{
			(maps->map)[enemy_position] = 'L';
			enemy--;
		}
		cnt--;
	}
}

void	enemy_sprite_init(t_param *maps)
{
	maps->enemy_sprite[0].image = mlx_xpm_file_to_image(maps->mlx, \
		"texture/rg1.xpm", &maps->enemy_sprite[0].wi, \
		&maps->enemy_sprite[0].he);
	maps->enemy_sprite[1].image = mlx_xpm_file_to_image(maps->mlx, \
		"texture/rg2.xpm", &maps->enemy_sprite[1].wi, \
		&maps->enemy_sprite[1].he);
	maps->enemy_sprite[2].image = mlx_xpm_file_to_image(maps->mlx, \
		"texture/rg3.xpm", &maps->enemy_sprite[2].wi, \
		&maps->enemy_sprite[2].he);
	maps->enemy_sprite[3].image = mlx_xpm_file_to_image(maps->mlx, \
		"texture/rg4.xpm", &maps->enemy_sprite[3].wi, \
		&maps->enemy_sprite[3].he);
	maps->enemy_sprite[4].image = mlx_xpm_file_to_image(maps->mlx, \
		"texture/lg1.xpm", &maps->enemy_sprite[4].wi, \
		&maps->enemy_sprite[4].he);
	maps->enemy_sprite[5].image = mlx_xpm_file_to_image(maps->mlx, \
		"texture/lg2.xpm", &maps->enemy_sprite[5].wi, \
		&maps->enemy_sprite[5].he);
	maps->enemy_sprite[6].image = mlx_xpm_file_to_image(maps->mlx, \
		"texture/lg3.xpm", &maps->enemy_sprite[6].wi, \
		&maps->enemy_sprite[6].he);
	maps->enemy_sprite[7].image = mlx_xpm_file_to_image(maps->mlx, \
		"texture/lg4.xpm", &maps->enemy_sprite[7].wi, \
		&maps->enemy_sprite[7].he);
}
