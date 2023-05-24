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
			((maps->map)[maps->user.x - maps->win_width - 1] == 'R' || (maps->map)[maps->user.x - maps->win_width - 1] == 'L'))
		return (1);
	else if (keycode == KEY_DOWN && \
			((maps->map)[maps->user.x + maps->win_width + 1] == 'R' || (maps->map)[maps->user.x + maps->win_width + 1] == 'L'))
		return (1);
	else if (keycode == KEY_LEFT && ((maps->map)[maps->user.x - 1] == 'R' || (maps->map)[maps->user.x - 1] == 'L'))
		return (1);
	else if (keycode == KEY_RIGHT && ((maps->map)[maps->user.x + 1] == 'R' || (maps->map)[maps->user.x + 1] == 'L'))
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

void	enemy_sprite_init(t_param *maps)
{
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
}

void	attack_sprite_init(t_param *maps)
{
	maps->attack_sprite[0].image = mlx_xpm_file_to_image(maps->mlx, \
			"texture/right_attack1.xpm", &maps->attack_sprite[0].he, &maps->attack_sprite[0].he);
	maps->attack_sprite[1].image = mlx_xpm_file_to_image(maps->mlx, \
			"texture/right_attack2.xpm", &maps->attack_sprite[1].he, &maps->attack_sprite[1].he);
	maps->attack_sprite[2].image = mlx_xpm_file_to_image(maps->mlx, \
			"texture/right_attack3.xpm", &maps->attack_sprite[2].he, &maps->attack_sprite[2].he);
	maps->attack_sprite[3].image = mlx_xpm_file_to_image(maps->mlx, \
			"texture/right_attack4.xpm", &maps->attack_sprite[3].he, &maps->attack_sprite[3].he);
	maps->attack_sprite[4].image = mlx_xpm_file_to_image(maps->mlx, \
			"texture/right_attack5.xpm", &maps->attack_sprite[4].he, &maps->attack_sprite[4].he);
	maps->attack_sprite[5].image = mlx_xpm_file_to_image(maps->mlx, \
			"texture/right_attack6.xpm", &maps->attack_sprite[5].he, &maps->attack_sprite[5].he);
	maps->attack_sprite[6].image = mlx_xpm_file_to_image(maps->mlx, \
			"texture/left_attack1.xpm", &maps->attack_sprite[6].he, &maps->attack_sprite[6].he);
	maps->attack_sprite[7].image = mlx_xpm_file_to_image(maps->mlx, \
			"texture/left_attack2.xpm", &maps->attack_sprite[7].he, &maps->attack_sprite[7].he);
	maps->attack_sprite[8].image = mlx_xpm_file_to_image(maps->mlx, \
			"texture/left_attack3.xpm", &maps->attack_sprite[8].he, &maps->attack_sprite[8].he);
	maps->attack_sprite[9].image = mlx_xpm_file_to_image(maps->mlx, \
			"texture/left_attack4.xpm", &maps->attack_sprite[9].he, &maps->attack_sprite[9].he);
	maps->attack_sprite[10].image = mlx_xpm_file_to_image(maps->mlx, \
			"texture/left_attack5.xpm", &maps->attack_sprite[10].he, &maps->attack_sprite[10].he);
	maps->attack_sprite[11].image = mlx_xpm_file_to_image(maps->mlx, \
			"texture/left_attack6.xpm", &maps->attack_sprite[11].he, &maps->attack_sprite[11].he);
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
	maps->potal[0].image = mlx_xpm_file_to_image(maps->mlx, \
			"texture/close_potal.xpm", &maps->potal[0].he, &maps->potal[0].he);
	maps->potal[1].image = mlx_xpm_file_to_image(maps->mlx, \
			"texture/open_potal.xpm", &maps->potal[1].he, &maps->potal[1].he);
	user_sprite_init(maps);
	enemy_sprite_init(maps);
	attack_sprite_init(maps);
}
