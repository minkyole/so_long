/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_util3_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyole <minkyole@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 14:46:17 by minkyole          #+#    #+#             */
/*   Updated: 2023/05/27 14:46:20 by minkyole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long_bonus.h"

void	user_move(t_param *maps, int flag)
{
	if (flag == 1)
	{
		(maps->map)[maps->user.x] = '0';
		(maps->map)[maps->user.x - maps->win_width - 1] = 'P';
	}
	else if (flag == 2)
	{
		(maps->map)[maps->user.x] = '0';
		(maps->map)[maps->user.x + maps->win_width + 1] = 'P';
	}
	else if (flag == 3)
	{
		(maps->map)[maps->user.x] = '0';
		(maps->map)[maps->user.x - 1] = 'P';
	}
	else if (flag == 4)
	{
		(maps->map)[maps->user.x] = '0';
		(maps->map)[maps->user.x + 1] = 'P';
	}
}

int	move_land(int keycode, t_param *maps)
{
	if (keycode == KEY_UP && \
			(maps->map)[maps->user.x - maps->win_width - 1] == '0')
	{
		user_move(maps, 1);
		return (1);
	}
	else if (keycode == KEY_DOWN && \
			(maps->map)[maps->user.x + maps->win_width + 1] == '0')
	{
		user_move(maps, 2);
		return (1);
	}
	else if (keycode == KEY_LEFT && (maps->map)[maps->user.x - 1] == '0')
	{
		user_move(maps, 3);
		return (1);
	}
	else if (keycode == KEY_RIGHT && (maps->map)[maps->user.x + 1] == '0')
	{
		user_move(maps, 4);
		return (1);
	}
	return (0);
}

int	move_chase(int keycode, t_param *maps)
{
	if (keycode == KEY_UP && \
			(maps->map)[maps->user.x - maps->win_width - 1] == 'C')
	{
		user_move(maps, 1);
		return (1);
	}
	else if (keycode == KEY_DOWN && \
			(maps->map)[maps->user.x + maps->win_width + 1] == 'C')
	{
		user_move(maps, 2);
		return (1);
	}
	else if (keycode == KEY_LEFT && (maps->map)[maps->user.x - 1] == 'C')
	{
		user_move(maps, 3);
		return (1);
	}
	else if (keycode == KEY_RIGHT && (maps->map)[maps->user.x + 1] == 'C')
	{
		user_move(maps, 4);
		return (1);
	}
	return (0);
}

int	move_potal(int keycode, t_param *maps)
{
	if (keycode == KEY_UP && (maps->map)[maps->user.x - maps->win_width - 1] \
			== 'E' && maps->collection == 0)
		return (1);
	else if (keycode == KEY_DOWN && (maps->map)[maps->user.x + \
			maps->win_width + 1] == 'E' && maps->collection == 0)
		return (1);
	else if (keycode == KEY_LEFT && \
			(maps->map)[maps->user.x - 1] == 'E' && maps->collection == 0)
		return (1);
	else if (keycode == KEY_RIGHT && \
			(maps->map)[maps->user.x + 1] == 'E' && maps->collection == 0)
		return (1);
	return (0);
}
