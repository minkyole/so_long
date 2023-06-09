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
