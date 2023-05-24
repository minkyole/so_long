/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_util2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyole <minkyole@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 21:55:05 by minkyole          #+#    #+#             */
/*   Updated: 2023/05/24 20:24:18 by minkyole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"

void	draw_attack(t_param *maps, int i, int score_end, int move_cnt)
{
	static int	attack_cnt;

	while (i <= score_end)
	{
		draw_image(1, maps, score_end);
		draw_score1(move_cnt % 10, maps, score_end);
		draw_score2(move_cnt % 10, maps, score_end);
		move_cnt = move_cnt / 10;
		score_end--;
	}
	if (maps->check_attack == 1)
		draw_right_attack(attack_cnt, maps, \
		maps->user.x + 1, (maps->win_width + 1));
	else if (maps->check_attack == 2)
		draw_left_attack(attack_cnt, maps, \
		maps->user.x - 2, (maps->win_width + 1));
	else if (maps->check_attack == 3)
		draw_up_attack(attack_cnt, maps, \
		maps->user.x - maps->win_width - 1, (maps->win_width + 1));
	else if (maps->check_attack == 4)
		draw_down_attack(attack_cnt, maps, \
		maps->user.x, (maps->win_width + 1));
	else
		attack_cnt = 0;
	attack_cnt++;
}

void	draw_map(t_param *maps, unsigned long long i, int cnt)
{
	draw_image(1, maps, i);
	if (maps->map[i] == '1')
		draw_image(2, maps, i);
	else if (maps->map[i] == 'P' && \
	(maps->user.direction == 1 || maps->user.direction == 3))
		draw_user_r(cnt, maps, i);
	else if (maps->map[i] == 'P' && \
	(maps->user.direction == 2 || maps->user.direction == 4))
		draw_user_l(cnt, maps, i);
	else if (maps->map[i] == 'C')
		draw_image(4, maps, i);
	else if (maps->map[i] == 'E' && maps->collection == 0)
		draw_image(6, maps, i);
	else if (maps->map[i] == 'E')
		draw_image(5, maps, i);
	else if (maps->map[i] == 'R')
		draw_enemy_r(cnt, maps, i);
	else if (maps->map[i] == 'L')
		draw_enemy_l(cnt, maps, i);
}

int	draw(t_param *maps)
{
	unsigned long long	i;
	static long long	cnt;

	i = 0;
	while (maps->map[i])
	{
		draw_map(maps, i, cnt);
		i++;
	}
	draw_attack(maps, i, ((maps->win_width + 1) * \
	(maps->win_height + 1)) - 2, maps->move_cnt);
	cnt++;
	return (0);
}

void	map_cnt(t_param *maps)
{
	int	i;
	int	max_win_width;
	int	max_win_height;

	maps->win_height = 0;
	maps->win_width = 0;
	maps->collection = 0;
	i = 0;
	while (maps->map[i])
	{
		if (maps->map[i] == '\n')
			maps->win_height += 1;
		else if (maps->map[i] == 'C')
			maps->collection += 1;
		i++;
	}
	maps->win_width = (i - maps->win_height) / maps->win_height;
	mlx_get_screen_size(maps->mlx, &max_win_width, &max_win_height);
	if (max_win_width < maps->win_width * 64 || \
	max_win_height < (maps->win_height + 1) * 64)
		error(4);
	maps->move_cnt = 0;
}

int	so_long(char *game_map)
{
	t_param	maps;

	maps.map = game_map;
	map_cnt(&maps);
	enemy_add(&maps, 0, 0, 500);
	maps.mlx = mlx_init();
	image_init(&maps);
	maps.user.x = 0;
	maps.user.direction = 1;
	maps.check_attack = 0;
	maps.waitting_attack = 0;
	mlx_key_hook(maps.win, &key_press, &maps);
	mlx_loop_hook(maps.mlx, &draw, &maps);
	mlx_hook(maps.win, 17, 0, &red_botton_delete, &maps);
	mlx_loop(maps.mlx);
	return (0);
}
