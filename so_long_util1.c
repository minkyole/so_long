/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_util1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyole <minkyole@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 21:52:31 by minkyole          #+#    #+#             */
/*   Updated: 2023/05/20 21:52:33 by minkyole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"

void	dfs(char *map, t_map_check *map_check, int player)
{
	map_check->dfs_map[player] = 1;
	if (map[player] == 'C')
		map_check->dfs_c += 1;
	if (map[player - map_check->x - 1] != '1' && \
			map_check->dfs_map[player - map_check->x - 1] != 1)
	{
		if (map[player - map_check->x - 1] == 'E')
			map_check->dfs_e += 1;
		else
			dfs(map, map_check, player - map_check->x - 1);
	}
	if (map[player + 1] != '1' && \
			map_check->dfs_map[player + 1] != 1)
	{
		if (map[player + 1] == 'E')
			map_check->dfs_e += 1;
		else
			dfs(map, map_check, player + 1);
	}
	if (map[player - 1] != '1' && \
			map_check->dfs_map[player - 1] != 1)
	{
		if (map[player - 1] == 'E')
			map_check->dfs_e += 1;
		else
			dfs(map, map_check, player - 1);
	}
	if (map[player + map_check->x + 1] != '1' && \
			map_check->dfs_map[player + map_check->x + 1] != 1)
	{
		if (map[player + map_check->x + 1] == 'E')
			map_check->dfs_e += 1;
		else
			dfs(map, map_check, player + map_check->x + 1);
	}
}

int	check_map_closed(char *map, t_map_check *map_check, int i)
{
	while (map[i])
	{
		if (i < map_check->x && map[i] != '1')
			return (1);
		else if (i % (map_check->x + 1) == 0 && map[i] != '1')
			return (1);
		else if ((i % (map_check->x + 1)) == map_check->x - 1 && map[i] != '1')
			return (1);
		else if (i >= (map_check->x + 1) * (map_check->y - 1) && \
				i < ((map_check->x + 1) * map_check->y) - 1)
		{
			if (map[i] != '1')
				return (1);
		}
		i++;
	}
	return (0);
}

int	check_map_item(char *map, t_map_check *map_check, int i)
{
	while (map[i])
	{
		if (map[i] == 'C')
			map_check->c += 1;
		else if (map[i] == 'P')
		{
			map_check->player = i;
			map_check->p += 1;
		}
		else if (map[i] == 'E')
			map_check->e += 1;
		else if (map[i] == '0' || map[i] == '1')
			;
		else if (map[i] == '\n')
			map_check->y += 1;
		else
			return (1);
		i++;
	}
	if (map_check->p != 1 || map_check->e != 1 || map_check->c <= 0)
		return (1);
	return (0);
}

int	check_map_name(char *arr)
{
	unsigned long long	len;

	len = ft_strlen(arr);
	if (len <= 4)
		return (1);
	if (arr[len - 1] == 'r' && arr[len - 2] == 'e' && \
			arr[len - 3] == 'b' && arr[len - 4] == '.')
		return (0);
	return (1);
}

int	check_map(char *map)
{
	t_map_check	map_check;

	init_map(&map_check);
	if (check_map_item(map, &map_check, 0))
		return (1);
	map_check.x = (ft_strlen(map) - map_check.y) / map_check.y;
	if (check_map_closed(map, &map_check, 0))
		return (1);
	map_check.dfs_map = ft_calloc(ft_strlen(map), 4);
	if (map_check.dfs_map == NULL)
		return (1);
	dfs(map, &map_check, map_check.player);
	if (map_check.dfs_c == map_check.c && map_check.dfs_e >= 1)
	{
		free(map_check.dfs_map);
		return (0);
	}
	free(map_check.dfs_map);
	return (1);
}
