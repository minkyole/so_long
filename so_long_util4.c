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
#include <stdio.h>

int	key_press(int keycode, t_param *maps)
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
	if (check_enemy(keycode, maps))
		exit(0);
	if (keycode == KEY_ESC)
		exit(0);
	check_enemy2(maps);
	enemy_set(maps);
	return (0);
}

void	enemy_set(t_param *maps)
{
	int	i;

	i = 0;
	while (maps->map[i])
	{
		if (maps->map[i] == 'R' || maps->map[i] == 'L')
			enemy_move(maps, i);
		i++;
	}
	i = 0;
	while (maps->map[i])
	{
		if (maps->map[i] == 'r')
			maps->map[i] = 'R';
		else if (maps->map[i] == 'l')
			maps->map[i] = 'L';
		i++;
	}
}

void	move_enemy(t_param *maps, int flag, int enemy_position)
{
	if (flag == 1)
	{
		(maps->map)[enemy_position] = '0';
		(maps->map)[enemy_position - maps->win_width - 1] = 'l';
	}
	else if (flag == 2)
	{
		(maps->map)[enemy_position] = '0';
		(maps->map)[enemy_position + maps->win_width + 1] = 'r';
	}
	else if (flag == 3)
	{
		(maps->map)[enemy_position] = '0';
		(maps->map)[enemy_position - 1] = 'l';
	}
	else if (flag == 4)
	{
		(maps->map)[enemy_position] = '0';
		(maps->map)[enemy_position + 1] = 'r';
	}
}

void	enemy_move(t_param *maps, int enemy_position)
{
	int	keycode;
	int	cnt;

	cnt = 0;
	while (1)
	{
		keycode = (rand() % 4) + 123;
		if (keycode == KEY_UP && \
				(maps->map)[enemy_position - maps->win_width - 1] == '0')
			return (move_enemy(maps, 1, enemy_position));
		else if (keycode == KEY_DOWN && \
				(maps->map)[enemy_position + maps->win_width + 1] == '0')
			return (move_enemy(maps, 2, enemy_position));
		else if (keycode == KEY_LEFT && (maps->map)[enemy_position - 1] == '0')
			return (move_enemy(maps, 3, enemy_position));
		else if (keycode == KEY_RIGHT && (maps->map)[enemy_position + 1] == '0')
			return (move_enemy(maps, 4, enemy_position));
		cnt++;
		if (cnt == 10)
			return ;
	}
}

void	enemy_add(t_param *maps)
{
	int	enemy;
	int	enemy_position;

	enemy = 0;
	if (maps->win_width * maps->win_height < 90)
		enemy = 1;
	else if (maps->win_width * maps->win_height < 150)
		enemy = 2;
	else if (maps->win_width * maps->win_height < 210)
		enemy = 3;
	else if (maps->win_width * maps->win_height < 270)
		enemy = 4;
	else
		enemy = 5;
	srand(time(NULL));
	while (enemy != 0)
	{
		enemy_position = rand() % ((maps->win_width + 1) * maps->win_height);
		if ((maps->map)[enemy_position] == '0')
		{
			(maps->map)[enemy_position] = 'L';
			enemy--;
		}
	}
}
