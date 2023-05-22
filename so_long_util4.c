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

int	key_press(int keycode, t_param *maps)
{
	if (move_land(keycode, maps))
	{
		maps->move_cnt += 1;
		ft_printf("%d\n", maps->move_cnt);
	}
	else if (move_chase(keycode, maps))
	{
		maps->move_cnt += 1;
		maps->collection -= 1;
		ft_printf("%d\n", maps->move_cnt);
	}
	else if (move_potal(keycode, maps))
	{
		maps->move_cnt += 1;
		ft_printf("%d\n", maps->move_cnt);
		exit(0);
	}
	else if (check_enemy(keycode, maps))
		exit(0);
	else if (keycode == KEY_ESC)
		exit(0);
	check_enemy2(maps);
	enemy_set(maps);
	return (0);
}

void enemy_set(t_param *maps)
{
	int i;

	i = 0;
	while (maps->map[i])
	{
		if (maps->map[i] == 'G')
			enemy_move(maps, i);
		i++;
	}
	i = 0;
	while (maps->map[i])
	{
		if (maps->map[i] == 'g')
			maps->map[i] = 'G';
		i++;
	}

}

void	move_enemy(t_param *maps, int flag, int enemy_position)
{
	if (flag == 1)
	{
		(maps->map)[enemy_position] = '0';
		(maps->map)[enemy_position - maps->win_width - 1] = 'g';
	}
	else if (flag == 2)
	{
		(maps->map)[enemy_position] = '0';
		(maps->map)[enemy_position + maps->win_width + 1] = 'g';
	}
	else if (flag == 3)
	{
		(maps->map)[enemy_position] = '0';
		(maps->map)[enemy_position - 1] = 'g';
	}
	else if (flag == 4)
	{
		(maps->map)[enemy_position] = '0';
		(maps->map)[enemy_position + 1] = 'g';
	}
}

void enemy_move(t_param *maps, int enemy_position)
{
	int keycode;
	int cnt;

	cnt = 0;
	while(1)
	{
		keycode = (rand() % 4) + 123;
		if (keycode == KEY_UP && \
				(maps->map)[enemy_position - maps->win_width - 1] == '0')
		{
			move_enemy(maps, 1, enemy_position);
			return ;
		}
		else if (keycode == KEY_DOWN && \
				(maps->map)[enemy_position + maps->win_width + 1] == '0')
		{
			move_enemy(maps, 2, enemy_position);
			return ;
		}
		else if (keycode == KEY_LEFT && (maps->map)[enemy_position - 1] == '0')
		{
			move_enemy(maps, 3, enemy_position);
			return ;
		}
		else if (keycode == KEY_RIGHT && (maps->map)[enemy_position + 1] == '0')
		{
			move_enemy(maps, 4, enemy_position);
			return ;
		}
		cnt++;
		if (cnt == 10)
			return ;
	}
}

void enemy_add(t_param *maps)
{
	int enemy;
	unsigned int	enemy_position;

	enemy = 0;
	if (maps->win_width * maps->win_height < 60)
		enemy = 1;
	else if (maps->win_width * maps->win_height < 120)
		enemy = 2;
	else if (maps->win_width * maps->win_height < 180)
		enemy = 3;
	else if (maps->win_width * maps->win_height < 240)
		enemy = 4;
	else
		enemy = 5;
	srand(maps->win_width);
	while (enemy != 0)
	{
		enemy_position = rand() % ((maps->win_width + 1) * maps->win_height);
		if ((maps->map)[enemy_position] == '0')
		{
			(maps->map)[enemy_position] = 'G';
			enemy--;
		}
	}
}