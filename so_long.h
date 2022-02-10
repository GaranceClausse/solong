/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 11:51:35 by gclausse          #+#    #+#             */
/*   Updated: 2022/02/10 16:06:35 by gclausse         ###   ########.fr       */
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
	int		h;
	int		w;
}				t_data;
/*
typedef struct s_txt {
	t_img	floor;
	t_img	wall;
	t_img	collect;
	t_img	exit;
	t_img	player;
}				t_txt;*/

typedef struct	s_vars {
	void	*mlx;
	void	*win;
//	t_txt	txt;
	int		x;
	int		y;
}				t_vars;

typedef struct	s_mapinfo {
	int	line_count;
	int	line_len;
	int	player;
	int	collectible;
	int	exit;
	int	x;
	int	y;
}				t_mapinfo;

int	close_map(t_vars *vars);
int	create_trgb(int t, int r, int g, int b);
int	get_t(int trgb);
int	get_r(int trgb);
int	get_g(int trgb);
int	get_b(int trgb);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

//check map utils
int	check_collect_exit(char **tab_map);
int	check_player(char **tab_map);
int	check_letters(char **tab_map);
int	check_first_last_line(char *line);
int	verify_filename(char *mapfile);

//get valid map
int	map_size(char *mapfile);
char	**create_map(int fd, t_mapinfo *mapinfo);
char	**get_map(int fd, char **tab_map, t_mapinfo *mapinfo);
int	valid_map(char **tab_map, t_mapinfo *mapinfo);

//errors
void	free_all(char **tab_map);
int	error(int n, char *str);
void	void_error(void);

#endif
