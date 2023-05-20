
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
	size_t	fd;
	int		win_width;
	int		win_height;
	char	*map;
}	t_param;

int	so_long(char *map);

int main(int argc, char **argv)
{
	int	fd;
	char	*parr;
	char	*temp;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd != -1)
		{
			parr = get_next_line(fd);
			temp = parr;
			while (parr)
			{
				parr = get_next_line(fd);
				temp = ft_strjoin(temp, parr);
			}
			printf("%s", temp);
			so_long(temp);
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

int	key_press(int keycode, t_param *maps)
// 입력에따라 좌표로 사용할 값을 증감시킴
{
	if (keycode == KEY_UP && (maps->map)[maps->user.x - maps->win_width - 1] == '0')
	{
		(maps->map)[maps->user.x] = '0';
		(maps->map)[maps->user.x - maps->win_width - 1] = 'P';
	}
	else if (keycode == KEY_DOWN && (maps->map)[maps->user.x + maps->win_width + 1] == '0')
	{
		(maps->map)[maps->user.x] = '0';
		(maps->map)[maps->user.x + maps->win_width + 1] = 'P';
	}
	else if (keycode == KEY_LEFT && (maps->map)[maps->user.x - 1] == '0')
	{
		(maps->map)[maps->user.x] = '0';
		(maps->map)[maps->user.x - 1] = 'P';
	}
	else if (keycode == KEY_RIGHT && (maps->map)[maps->user.x + 1] == '0')
	{
		(maps->map)[maps->user.x] = '0';
		(maps->map)[maps->user.x + 1] = 'P';
	}
	else if (keycode == KEY_ESC)
		exit(0);
	printf("y: %d x: %d\n", (maps->user).y, (maps->user).x);
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

	i = 0;
	y = 0;
	while (temp[i])
	{
		if (temp[i] == '\n')
			y++;
		i++;
	}
	x = (i - y) / y;
	maps->win_width = x;
	maps->win_height = y;
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
