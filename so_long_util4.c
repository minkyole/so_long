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
	else if (keycode == KEY_ESC)
		exit(0);
	return (0);
}
