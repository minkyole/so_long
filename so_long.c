/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyole <minkyole@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 19:27:43 by minkyole          #+#    #+#             */
/*   Updated: 2023/05/20 19:44:41 by minkyole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"

void	error(int flag)
{
	if (flag == 1)
		ft_printf("Error\nMap Input Error");
	else if (flag == 2)
		ft_printf("Error\nMap Extension Error");
	else if (flag == 3)
		ft_printf("Error\nMap Open Error");
	else if (flag == 4)
		ft_printf("Error\nMap Size is Out of Scrren Size");
	exit(0);
}

void	init_map(t_map_check *map_check)
{
	map_check->x = 0;
	map_check->y = 0;
	map_check->player = 0;
	map_check->dfs_c = 0;
	map_check->dfs_e = 0;
	map_check->c = 0;
	map_check->p = 0;
	map_check->e = 0;
}

void	main2(int fd, unsigned long long len)
{
	char	*parr;
	char	*map;

	parr = get_next_line(fd);
	map = parr;
	len = ft_strlen(map);
	while (parr)
	{
		if (len != ft_strlen(parr))
		{
			if (!(len -1 == ft_strlen(map) && get_next_line(fd) == NULL))
				error(1);
		}
		parr = get_next_line(fd);
		map = ft_strjoin(map, parr);
	}
	if (check_map(map))
		error(1);
	so_long(map);
	free (map);
}

int	main(int argc, char **argv)
{
	int	fd;

	if (argc == 2)
	{
		if (check_map_name(argv[1]))
			error(2);
		else
		{
			fd = open(argv[1], O_RDONLY);
			if (fd == -1)
				error(3);
			else
				main2(fd, 0);
		}
	}
	else
		error(1);
}
