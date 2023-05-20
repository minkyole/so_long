
#include <stdlib.h>
#include <stdio.h>
#include "mlx/mlx.h"
#include <fcntl.h>
#include "libft.h"

typedef struct s_map
{
	int wi;
	int he;
	int x;
	int y;
	void	*image;
	void	*g;
	void	*w;
} t_map;

typedef struct s_param
{
	t_map	user;
	t_map	wall;
	t_map	land;
	t_map	chase;
	t_map	potal;
	void	*mlx;
	void	*win;
	int		move_cnt;
	int		win_width;
	int		win_height;
	int		collection;
	char	*map;
}	t_param;

int	so_long(char *map);

void	dfs(char *map, int x, int y, int player, int *c, int *e, int *dfs_map)
{
	dfs_map[player] = 1;
	if (map[player] == 'C')
		*c += 1;
	else if (map[player] == 'E')
		*e += 1;
	if (map[player - x - 1] != '1' && dfs_map[player - x - 1] != 1) // up
		dfs(map, x, y, player - x - 1, c, e, dfs_map);
	if (map[player + 1] != '1' && dfs_map[player + 1] != 1) // right
		dfs(map, x, y, player + 1, c, e, dfs_map);
	if (map[player - 1] != '1' && dfs_map[player - 1] != 1) // left
		dfs(map, x, y, player - 1, c, e, dfs_map);
	if (map[player + x + 1] != '1' && dfs_map[player + x + 1] != 1) // down
		dfs(map, x, y, player + x + 1, c, e, dfs_map);
}

int	check_map(char *map, int c, int p, int e)
{
	int i;
	int x;
	int y = 0;
	int	player;
	int dfs_c = 0;
	int	dfs_e = 0;
	int *dfs_map;

	x = -1;
	i = 0;
	while (map[i])
	{
		if (map[i] == 'C')
			c++;
		else if (map[i] == 'P')
		{
			player = i;
			p++;
		}
		else if (map[i] == 'E')
			e++;
		else if (map[i] == '0' || map[i] == '1')
			;
		else if (map[i] == '\n')
			y++;
		else
			return(1);
		i++;
	}
	if (p > 1 || e > 1)
		return (1);
	x = (i - y) / y;
	i = 0;
	while (map[i])
	{
		if (i < x && map[i] != '1')
		{
			ft_printf("up error\n");
			return (1);
		}
		else if (i % (x + 1) == 0 && map[i] != '1')
		{
			ft_printf("left error\n");
			return (1);
		}
		else if ((i % (x + 1)) == x - 1 && map[i] != '1')
		{
			ft_printf("right error\n");
			return (1);
		}
		else if (i >= (x + 1) * (y - 1) && i < ((x + 1) * y) - 1)
		{
			if (map[i] != '1')
			{
				ft_printf("down error\n");
				return (1);
			}
		}
		i++;
	}
	dfs_map = ft_calloc(i, 4);
	dfs(map, x, y, player, &dfs_c, &dfs_e, dfs_map);
	if (dfs_c == c && dfs_e == e)
	{
		free(dfs_map);
		return (0);
	}
	free(dfs_map);
	return (1);
}

int	check_map_name(char *arr)
{
	unsigned long long len = ft_strlen(arr);
	if (len <= 4)
		return (0);
	if (arr[len - 1] == 'r' && arr[len - 2] == 'e' && arr[len - 3] == 'b' && arr[len - 4] == '.')
		return (1);
	return (0);
}

int main(int argc, char **argv)
{
	int	fd;
	char	*parr;
	char	*map;
	unsigned long long	len;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd != -1 && check_map_name(argv[1]))
		{
			parr = get_next_line(fd);
			map = parr;
			len = ft_strlen(map);
			while (parr)
			{
				if (len != ft_strlen(parr))
				{
					if (!(len -1 == ft_strlen(map) && get_next_line(fd) == NULL))
					{
						ft_printf("error\nmep_error");
						exit(0);
					}
				}
				parr = get_next_line(fd);
				map = ft_strjoin(map, parr);
			}
			printf("%s", map);
			if (check_map(map, 0, 0, 0))
			{
				ft_printf("error\nmap error");
				exit(0);
			}
			so_long(map);
		}
	}
}

//1. 지형지물 파싱해서 출력 구조체만들기 움직일필요 x
//2. win 구조체만들기
//3. 유저 구조체 만들기 이동해야됨

#define KEY_ESC		53
#define KEY_UP		126
#define KEY_DOWN	125
#define KEY_LEFT	123
#define KEY_RIGHT	124

int move_land(int keycode, t_param *maps)
{
	if (keycode == KEY_UP && (maps->map)[maps->user.x - maps->win_width - 1] == '0')
	{
		(maps->map)[maps->user.x] = '0';
		(maps->map)[maps->user.x - maps->win_width - 1] = 'P';
		return (1);
	}
	else if (keycode == KEY_DOWN && (maps->map)[maps->user.x + maps->win_width + 1] == '0')
	{
		(maps->map)[maps->user.x] = '0';
		(maps->map)[maps->user.x + maps->win_width + 1] = 'P';
		return (1);
	}
	else if (keycode == KEY_LEFT && (maps->map)[maps->user.x - 1] == '0')
	{
		(maps->map)[maps->user.x] = '0';
		(maps->map)[maps->user.x - 1] = 'P';
		return (1);
	}
	else if (keycode == KEY_RIGHT && (maps->map)[maps->user.x + 1] == '0')
	{
		(maps->map)[maps->user.x] = '0';
		(maps->map)[maps->user.x + 1] = 'P';
		return (1);
	}
	return (0);
}

int move_chase(int keycode, t_param *maps)
{
	if (keycode == KEY_UP && (maps->map)[maps->user.x - maps->win_width - 1] == 'C')
	{
		(maps->map)[maps->user.x] = '0';
		(maps->map)[maps->user.x - maps->win_width - 1] = 'P';
		return (1);
	}
	else if (keycode == KEY_DOWN && (maps->map)[maps->user.x + maps->win_width + 1] == 'C')
	{
		(maps->map)[maps->user.x] = '0';
		(maps->map)[maps->user.x + maps->win_width + 1] = 'P';
		return (1);
	}
	else if (keycode == KEY_LEFT && (maps->map)[maps->user.x - 1] == 'C')
	{
		(maps->map)[maps->user.x] = '0';
		(maps->map)[maps->user.x - 1] = 'P';
		return (1);
	}
	else if (keycode == KEY_RIGHT && (maps->map)[maps->user.x + 1] == 'C')
	{
		(maps->map)[maps->user.x] = '0';
		(maps->map)[maps->user.x + 1] = 'P';
		return (1);
	}
	return (0);
}

int move_potal(int keycode, t_param *maps)
{
	if (keycode == KEY_UP && (maps->map)[maps->user.x - maps->win_width - 1] == 'E' && maps->collection == 0)
		return (1);
	else if (keycode == KEY_DOWN && (maps->map)[maps->user.x + maps->win_width + 1] == 'E' && maps->collection == 0)
		return (1);
	else if (keycode == KEY_LEFT && (maps->map)[maps->user.x - 1] == 'E' && maps->collection == 0)
		return (1);
	else if (keycode == KEY_RIGHT && (maps->map)[maps->user.x + 1] == 'E' && maps->collection == 0)
		return (1);
	return (0);
}

int	key_press(int keycode, t_param *maps)
// 입력에따라 좌표로 사용할 값을 증감시킴
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

int	draw(t_param *maps)
{
	unsigned long long i = 0;

	mlx_clear_window(maps->mlx, maps->win); //기존에 그려놨던 윈도우를 지워줌
	while (i < ft_strlen(maps->map))
	{
		mlx_put_image_to_window(maps->mlx, maps->win, (maps->land).image, i % (maps->win_width + 1) * 32, i / (maps->win_width + 1) * 32);
		if (maps->map[i] == '1')
			mlx_put_image_to_window(maps->mlx, maps->win, (maps->wall).image, i % (maps->win_width + 1) * 32, i / (maps->win_width + 1) * 32);
		else if (maps->map[i] == 'P')
		{
			mlx_put_image_to_window(maps->mlx, maps->win, (maps->user).image, i % (maps->win_width + 1) * 32, i / (maps->win_width + 1) * 32);
			(maps->user).x = i;
		}
		else if (maps->map[i] == 'C')
			mlx_put_image_to_window(maps->mlx, maps->win, (maps->chase).image, i % (maps->win_width + 1) * 32, i / (maps->win_width + 1) * 32);
		else if (maps->map[i] == 'E')
			mlx_put_image_to_window(maps->mlx, maps->win, (maps->potal).image, i % (maps->win_width + 1) * 32, i / (maps->win_width + 1) * 32);
		i++;
	}
    //새로운 좌표를 이용한 새 위치에 이미지를 그려줌
	return (0);
}

void	map_cnt(char *temp, t_param *maps)
{
	int x;
	int y;
	int i;
	int c;

	i = 0;
	y = 0;
	c = 0;
	while (temp[i])
	{
		if (temp[i] == '\n')
			y++;
		else if (temp[i] == 'C')
			c++;
		i++;
	}
	x = (i - y) / y;
	maps->win_width = x;
	maps->win_height = y;
	maps->collection = c;
	maps->move_cnt = 0;
}

int	so_long(char *game_map)
{
	t_param	maps;

	maps.map = game_map;
	map_cnt(maps.map, &maps);
	maps.mlx = mlx_init();
	maps.win = mlx_new_window(maps.mlx, maps.win_width * 32, maps.win_height * 32, "DrawMap");
	maps.user.image = mlx_xpm_file_to_image(maps.mlx, "imgs/p.xpm", &maps.user.he, &maps.user.he);
	maps.wall.image = mlx_xpm_file_to_image(maps.mlx, "imgs/1.xpm", &maps.wall.he, &maps.wall.he);
	maps.land.image = mlx_xpm_file_to_image(maps.mlx, "imgs/0.xpm", &maps.land.he, &maps.land.he);
	maps.chase.image = mlx_xpm_file_to_image(maps.mlx, "imgs/c.xpm", &maps.chase.he, &maps.chase.he);
	maps.potal.image = mlx_xpm_file_to_image(maps.mlx, "imgs/e.xpm", &maps.potal.he, &maps.potal.he);
	maps.user.x = 0;
	maps.user.y = 0;
	mlx_key_hook(maps.win, &key_press, &maps);
    //키보드 입력을 받아줌
	mlx_loop_hook(maps.mlx, &draw, &maps);
    //이미지를 지우고 다시 그려주는 draw함수를 이벤트마다 실행해줌
	mlx_loop(maps.mlx);
	return (0);
}
