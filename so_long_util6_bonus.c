/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_util6_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyole <minkyole@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 14:47:10 by minkyole          #+#    #+#             */
/*   Updated: 2023/05/27 14:47:12 by minkyole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
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
			(maps->potal[0]).image, i % (maps->win_width + 1) * 64, \
			i / (maps->win_width + 1) * 64);
	else if (flag == 6)
		mlx_put_image_to_window(maps->mlx, maps->win, \
			(maps->potal[1]).image, i % (maps->win_width + 1) * 64, \
			i / (maps->win_width + 1) * 64);
}

void	draw_score1(int flag, t_param *maps, unsigned long long i)
{
	if (flag == 0)
		mlx_put_image_to_window(maps->mlx, maps->win, \
			(maps->keybord[0]).image, i % (maps->win_width + 1) * 64, \
			i / (maps->win_width + 1) * 64);
	else if (flag == 1)
		mlx_put_image_to_window(maps->mlx, maps->win, \
			(maps->keybord[1]).image, i % (maps->win_width + 1) * 64, \
			i / (maps->win_width + 1) * 64);
	else if (flag == 2)
		mlx_put_image_to_window(maps->mlx, maps->win, \
			(maps->keybord[2]).image, i % (maps->win_width + 1) * 64, \
			i / (maps->win_width + 1) * 64);
	else if (flag == 3)
		mlx_put_image_to_window(maps->mlx, maps->win, \
			(maps->keybord[3]).image, i % (maps->win_width + 1) * 64, \
			i / (maps->win_width + 1) * 64);
	else if (flag == 4)
		mlx_put_image_to_window(maps->mlx, maps->win, \
			(maps->keybord[4]).image, i % (maps->win_width + 1) * 64, \
			i / (maps->win_width + 1) * 64);
}

void	draw_score2(int flag, t_param *maps, unsigned long long i)
{
	if (flag == 5)
		mlx_put_image_to_window(maps->mlx, maps->win, \
			(maps->keybord[5]).image, i % (maps->win_width + 1) * 64, \
			i / (maps->win_width + 1) * 64);
	else if (flag == 6)
		mlx_put_image_to_window(maps->mlx, maps->win, \
			(maps->keybord[6]).image, i % (maps->win_width + 1) * 64, \
			i / (maps->win_width + 1) * 64);
	else if (flag == 7)
		mlx_put_image_to_window(maps->mlx, maps->win, \
			(maps->keybord[7]).image, i % (maps->win_width + 1) * 64, \
			i / (maps->win_width + 1) * 64);
	else if (flag == 8)
		mlx_put_image_to_window(maps->mlx, maps->win, \
			(maps->keybord[8]).image, i % (maps->win_width + 1) * 64, \
			i / (maps->win_width + 1) * 64);
	else if (flag == 9)
		mlx_put_image_to_window(maps->mlx, maps->win, \
			(maps->keybord[9]).image, i % (maps->win_width + 1) * 64, \
			i / (maps->win_width + 1) * 64);
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
