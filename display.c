/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 17:37:50 by gclausse          #+#    #+#             */
/*   Updated: 2022/02/21 12:09:05 by gclausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	find_player(t_combo *combo)
{
	int	i;
	int	j;

	i = 0;
	while (combo->map[i])
	{
		j = 0;
		while (combo->map[i][j] != '\n')
		{
			if (combo->map[i][j] == 'P')
			{
				combo->mapinfo->x = j;
				combo->mapinfo->y = i;
				return ;
			}
			else
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
			(mlx.txt.floor.h * mapinfo.line_count), "Drunk Baby!");
	put_txt(tab_map, mlx, mapinfo);
	combo.mlx = &mlx;
	mlx_hook(mlx.win, 17, 0L, &ft_cross, &combo);
	mlx_hook(mlx.win, 2, 1L << 0, direction, &combo);
	mlx_loop(mlx.mlx);
}
