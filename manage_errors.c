/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 12:05:21 by gclausse          #+#    #+#             */
/*   Updated: 2022/02/17 13:53:11 by gclausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_all(char **tab_map)
{
	int	i;

	i = 0;
	if (tab_map)
	{
		while (tab_map[i])
		{
			free (tab_map[i]);
			i++;
		}
		free(tab_map);
	}
}

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


int	error(int n, char *str)
{
	write(2, str, ft_strlen(str));
	write(2, "\n", 1);
	errno = n;
	exit(EXIT_FAILURE);
}

void	void_error(char **tab_map)
{
	perror("Error");
	free_all(tab_map);
	exit(EXIT_FAILURE);
}
