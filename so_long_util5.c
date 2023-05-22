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
			if (maps->map[i - maps->win_width - 1] == 'P')
				exit(0);
			else if (maps->map[i - maps->win_width + 1] == 'P')
				exit(0);
			else if (maps->map[i - 1] == 'P')
				exit(0);
			else if (maps->map[i + 1] == 'P')
				exit(0);
		}
		i++;
	}
}
