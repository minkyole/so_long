/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_util4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyole <minkyole@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 22:44:09 by minkyole          #+#    #+#             */
/*   Updated: 2023/05/20 22:44:12 by minkyole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"

int	key_attack_up_down(int keycode, t_param *maps)
{
	if (maps->waitting_attack == 1 && keycode == KEY_UP)
	{
		if (maps->map[maps->user.x - maps->win_width - 1] == 'L' || \
		maps->map[maps->user.x - maps->win_width - 1] == 'R')
			maps->map[maps->user.x - maps->win_width - 1] = '0';
		maps->user.direction = 3;
		maps->check_attack = 3;
		maps->waitting_attack = 0;
		return (1);
	}
	if (maps->waitting_attack == 1 && keycode == KEY_DOWN)
	{
		if (maps->map[maps->user.x + maps->win_width + 1] == 'L' || \
		maps->map[maps->user.x + maps->win_width + 1] == 'R')
			maps->map[maps->user.x + maps->win_width + 1] = '0';
		maps->user.direction = 4;
		maps->check_attack = 4;
		maps->waitting_attack = 0;
		return (1);
	}
	return (0);
}

int	key_attack_left_right(int keycode, t_param *maps, int user)
{
	if (maps->waitting_attack == 1 && keycode == KEY_RIGHT)
	{
		if (maps->map[user + 2] == 'L' || maps->map[user + 2] == 'R')
			maps->map[user + 2] = '0';
		if (maps->map[user + 1] == 'L' || maps->map[user + 1] == 'R')
			maps->map[user + 1] = '0';
		maps->user.direction = 1;
		maps->check_attack = 1;
		maps->waitting_attack = 0;
		return (1);
	}
	if (maps->waitting_attack == 1 && keycode == KEY_LEFT)
	{
		if (maps->map[user - 2] == 'L' || maps->map[user - 2] == 'R')
			maps->map[user - 2] = '0';
		if (maps->map[user - 1] == 'L' || maps->map[user - 1] == 'R')
			maps->map[user - 1] = '0';
		maps->user.direction = 2;
		maps->check_attack = 2;
		maps->waitting_attack = 0;
		return (1);
	}
	return (0);
}

void	move_map(int keycode, t_param *maps)
{
	if (move_land(keycode, maps))
	{
		maps->move_cnt += 1;
		ft_printf("%d\n", maps->move_cnt);
	}
	if (move_chase(keycode, maps))
	{
		maps->move_cnt += 1;
		maps->collection -= 1;
		ft_printf("%d\n", maps->move_cnt);
	}
	if (move_potal(keycode, maps))
	{
		maps->move_cnt += 1;
		ft_printf("%d\n", maps->move_cnt);
		exit(0);
	}
	maps->waitting_attack = 0;
}

int	key_press(int keycode, t_param *maps)
{
	if (keycode == KEY_ESC)
		exit(0);
	if (keycode == KEY_ATTACK)
	{
		maps->waitting_attack = 1;
		return (0);
	}
	if (key_attack_up_down(keycode, maps) || \
	key_attack_left_right(keycode, maps, maps->user.x))
		return (0);
	if (keycode == KEY_RIGHT)
		maps->user.direction = 1;
	else if (keycode == KEY_LEFT)
		maps->user.direction = 2;
	else if (keycode == KEY_UP)
		maps->user.direction = 3;
	else if (keycode == KEY_DOWN)
		maps->user.direction = 4;
	else
		return (0);
	move_map(keycode, maps);
	return (0);
}
