/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_util8_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyole <minkyole@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 14:47:37 by minkyole          #+#    #+#             */
/*   Updated: 2023/05/27 14:47:39 by minkyole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include "libft.h"

void	image_init(t_param *maps)
{
	maps->win = mlx_new_window(maps->mlx, maps->win_width * 64, \
			(maps->win_height + 1) * 64, "minkyole's so_long");
	maps->user.image = mlx_xpm_file_to_image(maps->mlx, \
			"texture/p.xpm", &maps->user.wi, &maps->user.he);
	maps->wall.image = mlx_xpm_file_to_image(maps->mlx, \
			"texture/1.xpm", &maps->wall.wi, &maps->wall.he);
	maps->land.image = mlx_xpm_file_to_image(maps->mlx, \
			"texture/0.xpm", &maps->land.wi, &maps->land.he);
	maps->chase.image = mlx_xpm_file_to_image(maps->mlx, \
			"texture/c.xpm", &maps->chase.wi, &maps->chase.he);
	maps->potal[0].image = mlx_xpm_file_to_image(maps->mlx, \
			"texture/close_potal.xpm", &maps->potal[0].wi, &maps->potal[0].he);
	maps->potal[1].image = mlx_xpm_file_to_image(maps->mlx, \
			"texture/open_potal.xpm", &maps->potal[1].wi, &maps->potal[1].he);
	user_sprite_init(maps);
	enemy_sprite_init(maps);
	attack_sprite_init1(maps);
	attack_sprite_init2(maps);
	attack_sprite_init3(maps);
	keybord_init(maps);
}

void	attack_sprite_init1(t_param *maps)
{
	maps->attack_sprite[0].image = mlx_xpm_file_to_image(maps->mlx, \
			"texture/right_attack1.xpm", &maps->attack_sprite[0].wi, \
			&maps->attack_sprite[0].he);
	maps->attack_sprite[1].image = mlx_xpm_file_to_image(maps->mlx, \
			"texture/right_attack2.xpm", &maps->attack_sprite[1].wi, \
			&maps->attack_sprite[1].he);
	maps->attack_sprite[2].image = mlx_xpm_file_to_image(maps->mlx, \
			"texture/right_attack3.xpm", &maps->attack_sprite[2].wi, \
			&maps->attack_sprite[2].he);
	maps->attack_sprite[3].image = mlx_xpm_file_to_image(maps->mlx, \
			"texture/right_attack4.xpm", &maps->attack_sprite[3].wi, \
			&maps->attack_sprite[3].he);
	maps->attack_sprite[4].image = mlx_xpm_file_to_image(maps->mlx, \
			"texture/right_attack5.xpm", &maps->attack_sprite[4].wi, \
			&maps->attack_sprite[4].he);
	maps->attack_sprite[5].image = mlx_xpm_file_to_image(maps->mlx, \
			"texture/right_attack6.xpm", &maps->attack_sprite[5].wi, \
			&maps->attack_sprite[5].he);
	maps->attack_sprite[6].image = mlx_xpm_file_to_image(maps->mlx, \
			"texture/left_attack1.xpm", &maps->attack_sprite[6].wi, \
			&maps->attack_sprite[6].he);
	maps->attack_sprite[7].image = mlx_xpm_file_to_image(maps->mlx, \
			"texture/left_attack2.xpm", &maps->attack_sprite[7].wi, \
			&maps->attack_sprite[7].he);
}

void	attack_sprite_init2(t_param *maps)
{
	maps->attack_sprite[8].image = mlx_xpm_file_to_image(maps->mlx, \
			"texture/left_attack3.xpm", &maps->attack_sprite[8].wi, \
			&maps->attack_sprite[8].he);
	maps->attack_sprite[9].image = mlx_xpm_file_to_image(maps->mlx, \
			"texture/left_attack4.xpm", &maps->attack_sprite[9].wi, \
			&maps->attack_sprite[9].he);
	maps->attack_sprite[10].image = mlx_xpm_file_to_image(maps->mlx, \
			"texture/left_attack5.xpm", &maps->attack_sprite[10].wi, \
			&maps->attack_sprite[10].he);
	maps->attack_sprite[11].image = mlx_xpm_file_to_image(maps->mlx, \
			"texture/left_attack6.xpm", &maps->attack_sprite[11].wi, \
			&maps->attack_sprite[11].he);
	maps->attack_sprite[12].image = mlx_xpm_file_to_image(maps->mlx, \
			"texture/up_attack1.xpm", &maps->attack_sprite[12].wi, \
			&maps->attack_sprite[12].he);
	maps->attack_sprite[13].image = mlx_xpm_file_to_image(maps->mlx, \
			"texture/up_attack2.xpm", &maps->attack_sprite[13].wi, \
			&maps->attack_sprite[13].he);
	maps->attack_sprite[14].image = mlx_xpm_file_to_image(maps->mlx, \
			"texture/up_attack3.xpm", &maps->attack_sprite[14].wi, \
			&maps->attack_sprite[14].he);
	maps->attack_sprite[15].image = mlx_xpm_file_to_image(maps->mlx, \
			"texture/up_attack4.xpm", &maps->attack_sprite[15].wi, \
			&maps->attack_sprite[15].he);
}

void	attack_sprite_init3(t_param *maps)
{
	maps->attack_sprite[16].image = mlx_xpm_file_to_image(maps->mlx, \
			"texture/up_attack5.xpm", &maps->attack_sprite[16].wi, \
			&maps->attack_sprite[16].he);
	maps->attack_sprite[17].image = mlx_xpm_file_to_image(maps->mlx, \
			"texture/up_attack6.xpm", &maps->attack_sprite[17].wi, \
			&maps->attack_sprite[17].he);
	maps->attack_sprite[18].image = mlx_xpm_file_to_image(maps->mlx, \
			"texture/down_attack1.xpm", &maps->attack_sprite[18].wi, \
			&maps->attack_sprite[18].he);
	maps->attack_sprite[19].image = mlx_xpm_file_to_image(maps->mlx, \
			"texture/down_attack2.xpm", &maps->attack_sprite[19].wi, \
			&maps->attack_sprite[19].he);
	maps->attack_sprite[20].image = mlx_xpm_file_to_image(maps->mlx, \
			"texture/down_attack3.xpm", &maps->attack_sprite[20].wi, \
			&maps->attack_sprite[20].he);
	maps->attack_sprite[21].image = mlx_xpm_file_to_image(maps->mlx, \
			"texture/down_attack4.xpm", &maps->attack_sprite[21].wi, \
			&maps->attack_sprite[21].he);
	maps->attack_sprite[22].image = mlx_xpm_file_to_image(maps->mlx, \
			"texture/down_attack5.xpm", &maps->attack_sprite[22].wi, \
			&maps->attack_sprite[22].he);
	maps->attack_sprite[23].image = mlx_xpm_file_to_image(maps->mlx, \
			"texture/down_attack6.xpm", &maps->attack_sprite[23].wi, \
			&maps->attack_sprite[23].he);
}

void	keybord_init(t_param *maps)
{
	maps->keybord[0].image = mlx_xpm_file_to_image(maps->mlx, \
			"texture/keybord0.xpm", &maps->keybord[0].wi, &maps->keybord[0].he);
	maps->keybord[1].image = mlx_xpm_file_to_image(maps->mlx, \
			"texture/keybord1.xpm", &maps->keybord[1].wi, &maps->keybord[1].he);
	maps->keybord[2].image = mlx_xpm_file_to_image(maps->mlx, \
			"texture/keybord2.xpm", &maps->keybord[2].wi, &maps->keybord[2].he);
	maps->keybord[3].image = mlx_xpm_file_to_image(maps->mlx, \
			"texture/keybord3.xpm", &maps->keybord[3].wi, &maps->keybord[3].he);
	maps->keybord[4].image = mlx_xpm_file_to_image(maps->mlx, \
			"texture/keybord4.xpm", &maps->keybord[4].wi, &maps->keybord[4].he);
	maps->keybord[5].image = mlx_xpm_file_to_image(maps->mlx, \
			"texture/keybord5.xpm", &maps->keybord[5].wi, &maps->keybord[5].he);
	maps->keybord[6].image = mlx_xpm_file_to_image(maps->mlx, \
			"texture/keybord6.xpm", &maps->keybord[6].wi, &maps->keybord[6].he);
	maps->keybord[7].image = mlx_xpm_file_to_image(maps->mlx, \
			"texture/keybord7.xpm", &maps->keybord[7].wi, &maps->keybord[7].he);
	maps->keybord[8].image = mlx_xpm_file_to_image(maps->mlx, \
			"texture/keybord8.xpm", &maps->keybord[8].wi, &maps->keybord[8].he);
	maps->keybord[9].image = mlx_xpm_file_to_image(maps->mlx, \
			"texture/keybord9.xpm", &maps->keybord[9].wi, &maps->keybord[9].he);
}
