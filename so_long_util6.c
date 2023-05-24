/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_util6.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyole <minkyole@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 23:41:03 by minkyole          #+#    #+#             */
/*   Updated: 2023/05/22 23:41:04 by minkyole         ###   ########.fr       */
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
			(maps->potal[0]).image, i % (maps->win_width + 1) * 64, \
			i / (maps->win_width + 1) * 64);
	else if (flag == 6)
		mlx_put_image_to_window(maps->mlx, maps->win, \
			(maps->potal[1]).image, i % (maps->win_width + 1) * 64, \
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

void	draw_user_l(int cnt, t_param *maps, unsigned long long i)
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
	maps->user.x = i;
}

void	draw_user_r(int cnt, t_param *maps, unsigned long long i)
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
	maps->user.x = i;
}

void draw_right_attack(int cnt, t_param *maps, int i)
{
	if (cnt % 30 <= 5)
		mlx_put_image_to_window(maps->mlx, maps->win, \
			(maps->attack_sprite[0]).image, i % (maps->win_width + 1) * 64, \
			i / (maps->win_width + 1) * 64);
	else if (cnt % 30 <= 10)
		mlx_put_image_to_window(maps->mlx, maps->win, \
			(maps->attack_sprite[1]).image, i % (maps->win_width + 1) * 64, \
			i / (maps->win_width + 1) * 64);
	else if (cnt % 30 <= 15)
		mlx_put_image_to_window(maps->mlx, maps->win, \
			(maps->attack_sprite[2]).image, i % (maps->win_width + 1) * 64, \
			i / (maps->win_width + 1) * 64);
	else if (cnt % 30 <= 20)
		mlx_put_image_to_window(maps->mlx, maps->win, \
			(maps->attack_sprite[3]).image, i % (maps->win_width + 1) * 64, \
			i / (maps->win_width + 1) * 64);
	else if (cnt % 30 <= 25)
		mlx_put_image_to_window(maps->mlx, maps->win, \
			(maps->attack_sprite[4]).image, i % (maps->win_width + 1) * 64, \
			i / (maps->win_width + 1) * 64);
	else if (cnt % 30 <= 30)
		mlx_put_image_to_window(maps->mlx, maps->win, \
			(maps->attack_sprite[5]).image, i % (maps->win_width + 1) * 64, \
			i / (maps->win_width + 1) * 64);	
	if (cnt % 30 == 29)
		maps->check_attack = 0;
}

void draw_left_attack(int cnt, t_param *maps, int i)
{
	if (cnt % 30 <= 5)
		mlx_put_image_to_window(maps->mlx, maps->win, \
			(maps->attack_sprite[6]).image, i % (maps->win_width + 1) * 64, \
			i / (maps->win_width + 1) * 64);
	else if (cnt % 30 <= 10)
		mlx_put_image_to_window(maps->mlx, maps->win, \
			(maps->attack_sprite[7]).image, i % (maps->win_width + 1) * 64, \
			i / (maps->win_width + 1) * 64);
	else if (cnt % 30 <= 15)
		mlx_put_image_to_window(maps->mlx, maps->win, \
			(maps->attack_sprite[8]).image, i % (maps->win_width + 1) * 64, \
			i / (maps->win_width + 1) * 64);
	else if (cnt % 30 <= 20)
		mlx_put_image_to_window(maps->mlx, maps->win, \
			(maps->attack_sprite[9]).image, i % (maps->win_width + 1) * 64, \
			i / (maps->win_width + 1) * 64);
	else if (cnt % 30 <= 25)
		mlx_put_image_to_window(maps->mlx, maps->win, \
			(maps->attack_sprite[10]).image, i % (maps->win_width + 1) * 64, \
			i / (maps->win_width + 1) * 64);
	else if (cnt % 30 <= 30)
		mlx_put_image_to_window(maps->mlx, maps->win, \
			(maps->attack_sprite[11]).image, i % (maps->win_width + 1) * 64, \
			i / (maps->win_width + 1) * 64);	
	if (cnt % 30 == 29)
		maps->check_attack = 0;
}
