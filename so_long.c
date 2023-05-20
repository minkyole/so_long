
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

typedef struct s_map_check
{
	int x;
	int y;
	int	player;
	int dfs_c;
	int	dfs_e;
	int	c;
	int p;
	int e;
	int *dfs_map;
}	t_map_check;

int	so_long(char *map);

void	dfs(char *map, t_map_check *map_check, int player)
{
	map_check->dfs_map[player] = 1;
	if (map[player] == 'C')
		map_check->dfs_c += 1;
	else if (map[player] == 'E')
		map_check->dfs_e += 1;
	if (map[player - map_check->x - 1] != '1' && map_check->dfs_map[player - map_check->x - 1] != 1) // up
		dfs(map, map_check, player - map_check->x - 1);
	if (map[player + 1] != '1' && map_check->dfs_map[player + 1] != 1) // right
		dfs(map, map_check, player + 1);
	if (map[player - 1] != '1' && map_check->dfs_map[player - 1] != 1) // left
		dfs(map, map_check, player - 1);
	if (map[player + map_check->x + 1] != '1' && map_check->dfs_map[player + map_check->x + 1] != 1) // down
		dfs(map, map_check, player + map_check->x + 1);
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
		else if (i >= (map_check->x + 1) * (map_check->y - 1) && i < ((map_check->x + 1) * map_check->y) - 1)
		{
			if (map[i] != '1')
				return (1);
		}
		i++;
	}
	return (0);
}

int check_map_item(char *map, t_map_check *map_check, int i)
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
			return(1);
		i++;
	}
	if (map_check->p != 1 || map_check->e != 1 || map_check->c <= 0)
		return (1);
	return (0);
}

void init_map(t_map_check *map_check)
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

int	check_map(char *map)
{
	t_map_check map_check;

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
	if (map_check.dfs_c == map_check.c && map_check.dfs_e == map_check.e)
	{
		free(map_check.dfs_map);
		return (0);
	}
	free(map_check.dfs_map);
	return (1);
}

int	check_map_name(char *arr)
{
	unsigned long long len = ft_strlen(arr);
	if (len <= 4)
		return (1);
	if (arr[len - 1] == 'r' && arr[len - 2] == 'e' && arr[len - 3] == 'b' && arr[len - 4] == '.')
		return (0);
	return (1);
}

//void   check_leak(void)
//{
//		system("leaks a.out");
//}

void main2(int fd, unsigned long long len)
{
	char *parr;
	char	*map;

	parr = get_next_line(fd);
	map = parr;
	len = ft_strlen(map);
	while (parr)
	{
		if (len != ft_strlen(parr))
		{
			if (!(len -1 == ft_strlen(map) && get_next_line(fd) == NULL))
			{
				ft_printf("Error\nMap Input Error");
				exit(0);
			}
		}
		parr = get_next_line(fd);
		map = ft_strjoin(map, parr);
	}
	if (check_map(map))
	{
		ft_printf("Error\nMap Input Error");
		exit(0);
	}
	so_long(map);
	free (map);
}

int main(int argc, char **argv)
{
	int	fd;

//	atexit(check_leak);
	if (argc == 2)
	{
		if (check_map_name(argv[1]))
			ft_printf("Error\nMap Extension Error");
		else
		{
			fd = open(argv[1], O_RDONLY);
			if (fd == -1)
				ft_printf("Error\nMap Open Error");
			else
			{
				main2(fd, 0);
			}
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

int red_botton_delete(void)
{
	exit(0);
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
	mlx_hook(maps.win, 17, 0, &red_botton_delete, &maps); 
	//red버튼이 눌러졋을때 프로그램을 종료해 준다
	mlx_loop(maps.mlx);
	return (0);
}
