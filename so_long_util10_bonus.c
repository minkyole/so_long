/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_util10_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyole <minkyole@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 14:45:30 by minkyole          #+#    #+#             */
/*   Updated: 2023/05/27 14:45:33 by minkyole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
