/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 11:51:35 by gclausse          #+#    #+#             */
/*   Updated: 2022/02/10 12:07:47 by gclausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "mlx_linux/mlx.h"
#include "libft/libft.h"
#include <stdio.h>
#include <unistd.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

//int	close(t_vars *vars);
int	create_trgb(int t, int r, int g, int b);
int	get_t(int trgb);
int	get_r(int trgb);
int	get_g(int trgb);
int	get_b(int trgb);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

//check map utils
int	check_exit_player(char **tab_map);
int	check_letters(char **tab_map);
int	check_first_last_line(char *line);
int	verify_filename(char *mapfile);

//get valid map
int	map_size(char *mapfile);
char	**get_map(char *mapfile);
int	valid_map(char *mapfile);
int	verify_map(char *mapfile);

//errors
void	free_all(char **tab_map);
int	error(int n, char *str);

#endif
