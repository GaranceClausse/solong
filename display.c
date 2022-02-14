/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 17:37:50 by gclausse          #+#    #+#             */
/*   Updated: 2022/02/10 17:56:13 by gclausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	close_map(t_data *mlx, char **tab_map)
{
	if (mlx->mlx)
	{
		mlx_destroy_image(mlx->mlx, mlx->txt.floor.img);
		mlx_destroy_image(mlx->mlx, mlx->txt.wall.img);
		mlx_destroy_image(mlx->mlx, mlx->txt.player.img);
		mlx_destroy_image(mlx->mlx, mlx->txt.collect.img);
		mlx_destroy_image(mlx->mlx, mlx->txt.exit.img);
		mlx_destroy_window(mlx->mlx, mlx->win);
		mlx_destroy_display(mlx->mlx);
		free(mlx->mlx);
	}
	free_all(tab_map);
	exit(0);
}

int	ft_cross(t_combo *combo)
{
	close_map(combo->mlx, combo->map);
	return (0);
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

void	display_map(char **tab_map, t_mapinfo mapinfo)
{
	t_data	mlx;
	t_combo	combo;

	combo.map = tab_map;
	combo.mapinfo = &mapinfo;
	combo.count = 0;
	mlx.mlx = mlx_init();
	if (mlx.mlx == NULL)
	{
		free_all(tab_map);
		exit(1);
	}
	get_txt(&mlx);
	mlx.win = mlx_new_window(mlx.mlx, (mlx.txt.floor.w * mapinfo.line_len),
			(mlx.txt.floor.h * mapinfo.line_count), "So Long !");
	put_txt(tab_map, mlx, mapinfo);
	combo.mlx = &mlx;
	mlx_hook(mlx.win, 17, 0L, &ft_cross, &combo);
	mlx_hook(mlx.win, 2, 1L << 0, direction, &combo);
	mlx_loop(mlx.mlx);
}
