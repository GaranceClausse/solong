#include "so_long.h"


void	init_txt(t_data *mlx, t_img *txt, char *path)
{
	txt->img = mlx_xpm_file_to_image(mlx->mlx, path, &txt->w, &txt->h);
}

void	get_txt(t_data *mlx)
{
	init_txt(mlx, &mlx->txt.floor, FLOOR);
	init_txt(mlx, &mlx->txt.wall, WALL);
	init_txt(mlx, &mlx->txt.player, PLAYER);
	init_txt(mlx, &mlx->txt.collect, COLLECT);
	init_txt(mlx, &mlx->txt.exit, EXIT);
}

void	which_txt(char c, t_data mlx, int i, int j)
{
	if (c == '1')
		mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.txt.wall.img,
			(mlx.txt.wall.w * j), (mlx.txt.wall.h * i));
	else if (c == '0')
		mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.txt.floor.img,
			(mlx.txt.floor.w * j), (mlx.txt.floor.h * i));
	else if (c == 'P')
		mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.txt.player.img,
			(mlx.txt.player.w * j), (mlx.txt.player.h * i));
	else if (c == 'E')
		mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.txt.exit.img,
			(mlx.txt.exit.w * j), (mlx.txt.exit.h * i));
	else if (c == 'C')
		mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.txt.collect.img,
			(mlx.txt.collect.w * j), (mlx.txt.collect.h * i));
}

void	put_txt(char **tab_map, t_data mlx, t_mapinfo mapinfo)
{
	int	i;
	int	j;

	i = 0;
	while (i < mapinfo.line_count)
	{
		j = 0;
		while (j < mapinfo.line_len)
		{
			which_txt(tab_map[i][j], mlx, i, j);
			j++;
		}
		i++;
	}
}


