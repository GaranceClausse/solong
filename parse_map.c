/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 14:26:52 by gclausse          #+#    #+#             */
/*   Updated: 2022/02/10 17:33:53 by gclausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_map(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->win);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	free(vars->win);
	mlx_loop_end(vars->mlx);

	//mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}

void	init_mapinfo(t_mapinfo *mapinfo)
{
	mapinfo->line_count = 0;
	mapinfo->line_len = 0;
	mapinfo->player = 0;
	mapinfo->collectible = 0;
	mapinfo->exit = 0;
	return ;
}

int	main(int argc, char **argv)
{
	int	fd;
	t_mapinfo	mapinfo;
	char		**tab_map;

	init_mapinfo(&mapinfo);
	if (argc != 2)
		error(1, "two arguments needed");
	if (verify_filename(argv[1]) != 0)
		return (error(2, "file type should be *.ber"));
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (error(3, "couldn't open the file"));
	tab_map = create_map(fd, &mapinfo);
	close(fd);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (error(3, "couldn't open the file"));
	tab_map = get_map(fd, tab_map, &mapinfo);
		printf("map ok");
	free_all(tab_map);

//	{
		/*start_game(module);
		hook(module);
		mlx_loop(module->vars->mlx);
		t_vars	vars;
		t_data	img;
	
		vars.mlx = mlx_init();
		vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
		img.img = mlx_new_image(vars.mlx, 1920, 1080);
		img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
		my_mlx_pixel_put(&img, 100, 100, 0x00FF0000);
		mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
		mlx_hook(vars.win, 2, 1L<<0, close_map, &vars);
		mlx_loop(vars.mlx);
		printf("map ok");
	}
		else
		{
			printf("map not ok");
			clear_map(module->map);
			free_ptr((void **)&module);
			exit(-1);
		}*/

//	else
//		return (error(22, "Please run with a map path in the terminal!"));
}
