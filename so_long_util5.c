/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_util5.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyole <minkyole@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 17:31:46 by minkyole          #+#    #+#             */
/*   Updated: 2023/05/22 17:31:48 by minkyole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"

int	red_botton_delete(void)
{
	exit(0);
}

int	check_enemy(int keycode, t_param *maps)
{
	if (keycode == KEY_UP && \
			((maps->map)[maps->user.x - maps->win_width - 1] == 'R' || \
			(maps->map)[maps->user.x - maps->win_width - 1] == 'L'))
		return (1);
	else if (keycode == KEY_DOWN && \
			((maps->map)[maps->user.x + maps->win_width + 1] == 'R' || \
			(maps->map)[maps->user.x + maps->win_width + 1] == 'L'))
		return (1);
	else if (keycode == KEY_LEFT && ((maps->map)[maps->user.x - 1] == 'R' || \
	(maps->map)[maps->user.x - 1] == 'L'))
		return (1);
	else if (keycode == KEY_RIGHT && ((maps->map)[maps->user.x + 1] == 'R' || \
	(maps->map)[maps->user.x + 1] == 'L'))
		return (1);
	return (0);
}

void	check_enemy2(t_param *maps)
{
	int	i;

	i = 0;
	while (maps->map[i])
	{
		if (maps->map[i] == 'L' || maps->map[i] == 'R')
		{
			if (maps->map[i - 1] == 'P')
				exit(0);
			else if (maps->map[i + 1] == 'P')
				exit(0);
		}
		i++;
	}
}

void	user_sprite_init(t_param *maps)
{
	maps->user_sprite[0].image = mlx_xpm_file_to_image(maps->mlx, \
		"texture/rp1.xpm", &maps->user_sprite[0].wi, &maps->user_sprite[0].he);
	maps->user_sprite[1].image = mlx_xpm_file_to_image(maps->mlx, \
		"texture/rp2.xpm", &maps->user_sprite[1].wi, &maps->user_sprite[1].he);
	maps->user_sprite[2].image = mlx_xpm_file_to_image(maps->mlx, \
		"texture/rp3.xpm", &maps->user_sprite[2].wi, &maps->user_sprite[2].he);
	maps->user_sprite[3].image = mlx_xpm_file_to_image(maps->mlx, \
		"texture/rp4.xpm", &maps->user_sprite[3].wi, &maps->user_sprite[3].he);
	maps->user_sprite[4].image = mlx_xpm_file_to_image(maps->mlx, \
		"texture/lp1.xpm", &maps->user_sprite[4].wi, &maps->user_sprite[4].he);
	maps->user_sprite[5].image = mlx_xpm_file_to_image(maps->mlx, \
		"texture/lp2.xpm", &maps->user_sprite[5].wi, &maps->user_sprite[5].he);
	maps->user_sprite[6].image = mlx_xpm_file_to_image(maps->mlx, \
		"texture/lp3.xpm", &maps->user_sprite[6].wi, &maps->user_sprite[6].he);
	maps->user_sprite[7].image = mlx_xpm_file_to_image(maps->mlx, \
		"texture/lp4.xpm", &maps->user_sprite[7].wi, &maps->user_sprite[7].he);
}
