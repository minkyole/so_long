/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_util9.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyole <minkyole@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 21:23:02 by minkyole          #+#    #+#             */
/*   Updated: 2023/05/24 21:23:04 by minkyole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"

void	draw_right_attack(int cnt, t_param *maps, int i, int width)
{
	if (cnt % 30 <= 5)
		mlx_put_image_to_window(maps->mlx, maps->win, \
			(maps->attack_sprite[0]).image, i % width * 64, i / width * 64);
	else if (cnt % 30 <= 10)
		mlx_put_image_to_window(maps->mlx, maps->win, \
			(maps->attack_sprite[1]).image, i % width * 64, i / width * 64);
	else if (cnt % 30 <= 15)
		mlx_put_image_to_window(maps->mlx, maps->win, \
			(maps->attack_sprite[2]).image, i % width * 64, i / width * 64);
	else if (cnt % 30 <= 20)
		mlx_put_image_to_window(maps->mlx, maps->win, \
			(maps->attack_sprite[3]).image, i % width * 64, i / width * 64);
	else if (cnt % 30 <= 25)
		mlx_put_image_to_window(maps->mlx, maps->win, \
			(maps->attack_sprite[4]).image, i % width * 64, i / width * 64);
	else if (cnt % 30 <= 30)
		mlx_put_image_to_window(maps->mlx, maps->win, \
			(maps->attack_sprite[5]).image, i % width * 64, i / width * 64);
	if (cnt % 30 == 29)
		maps->check_attack = 0;
}

void	draw_left_attack(int cnt, t_param *maps, int i, int width)
{
	if (cnt % 30 <= 5)
		mlx_put_image_to_window(maps->mlx, maps->win, \
			(maps->attack_sprite[6]).image, i % width * 64, i / width * 64);
	else if (cnt % 30 <= 10)
		mlx_put_image_to_window(maps->mlx, maps->win, \
			(maps->attack_sprite[7]).image, i % width * 64, i / width * 64);
	else if (cnt % 30 <= 15)
		mlx_put_image_to_window(maps->mlx, maps->win, \
			(maps->attack_sprite[8]).image, i % width * 64, i / width * 64);
	else if (cnt % 30 <= 20)
		mlx_put_image_to_window(maps->mlx, maps->win, \
			(maps->attack_sprite[9]).image, i % width * 64, i / width * 64);
	else if (cnt % 30 <= 25)
		mlx_put_image_to_window(maps->mlx, maps->win, \
			(maps->attack_sprite[10]).image, i % width * 64, i / width * 64);
	else if (cnt % 30 <= 30)
		mlx_put_image_to_window(maps->mlx, maps->win, \
			(maps->attack_sprite[11]).image, i % width * 64, i / width * 64);
	if (cnt % 30 == 29)
		maps->check_attack = 0;
}

void	draw_up_attack(int cnt, t_param *maps, int i, int width)
{
	if (cnt % 30 <= 5)
		mlx_put_image_to_window(maps->mlx, maps->win, \
			(maps->attack_sprite[12]).image, i % width * 64, i / width * 64);
	else if (cnt % 30 <= 10)
		mlx_put_image_to_window(maps->mlx, maps->win, \
			(maps->attack_sprite[13]).image, i % width * 64, i / width * 64);
	else if (cnt % 30 <= 15)
		mlx_put_image_to_window(maps->mlx, maps->win, \
			(maps->attack_sprite[14]).image, i % width * 64, i / width * 64);
	else if (cnt % 30 <= 20)
		mlx_put_image_to_window(maps->mlx, maps->win, \
			(maps->attack_sprite[15]).image, i % width * 64, i / width * 64);
	else if (cnt % 30 <= 25)
		mlx_put_image_to_window(maps->mlx, maps->win, \
			(maps->attack_sprite[16]).image, i % width * 64, i / width * 64);
	else if (cnt % 30 <= 30)
		mlx_put_image_to_window(maps->mlx, maps->win, \
			(maps->attack_sprite[17]).image, i % width * 64, i / width * 64);
	if (cnt % 30 == 29)
		maps->check_attack = 0;
}

void	draw_down_attack(int cnt, t_param *maps, int i, int width)
{
	if (cnt % 30 <= 5)
		mlx_put_image_to_window(maps->mlx, maps->win, \
			(maps->attack_sprite[18]).image, i % width * 64, i / width * 64);
	else if (cnt % 30 <= 10)
		mlx_put_image_to_window(maps->mlx, maps->win, \
			(maps->attack_sprite[19]).image, i % width * 64, i / width * 64);
	else if (cnt % 30 <= 15)
		mlx_put_image_to_window(maps->mlx, maps->win, \
			(maps->attack_sprite[20]).image, i % width * 64, i / width * 64);
	else if (cnt % 30 <= 20)
		mlx_put_image_to_window(maps->mlx, maps->win, \
			(maps->attack_sprite[21]).image, i % width * 64, i / width * 64);
	else if (cnt % 30 <= 25)
		mlx_put_image_to_window(maps->mlx, maps->win, \
			(maps->attack_sprite[22]).image, i % width * 64, i / width * 64);
	else if (cnt % 30 <= 30)
		mlx_put_image_to_window(maps->mlx, maps->win, \
			(maps->attack_sprite[23]).image, i % width * 64, i / width * 64);
	if (cnt % 30 == 29)
		maps->check_attack = 0;
}
