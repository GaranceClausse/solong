/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 14:26:52 by gclausse          #+#    #+#             */
/*   Updated: 2022/02/10 12:11:26 by gclausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
/*
int	close(t_vars *vars)
{
	mlx_loop_end(vars->mlx);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	//mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}*/

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		if (verify_map(argv[1]) == 0)
		{
			/*start_game(module);
			hook(module);
			mlx_loop(module->vars->mlx);*/
		//	t_vars	vars;
	//
	//		vars.mlx = mlx_init();
	//		vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
	//		mlx_hook(vars.win, 2, 1L<<0, close, &vars);
	//		mlx_loop(vars.mlx);
			printf("map ok");
		}
		else
		{
			printf("map not ok");
			/*clear_map(module->map);
			free_ptr((void **)&module);
			exit(-1);*/
		}
	}
	else
		return (error(22, "Please run with a map path in the terminal!"));
}

