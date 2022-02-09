/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 14:26:52 by gclausse          #+#    #+#             */
/*   Updated: 2022/02/09 17:36:28 by gclausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	error(int n, char *str)
{
	printf("%s\n", str);
	return (n);
}
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

int	verify_filename(char *mapfile)
{
	int	len;

	len = ft_strlen(mapfile);
	if (len < 5)
		return (1);
	if (mapfile[len - 4] == '.' && mapfile[len - 3] == 'b'
		&& mapfile[len - 2] == 'e' && mapfile[len - 1] == 'r')
		return (0);
	return (1);
}

int	check_first_last_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\n')
	{
		if (line[i] != '1')
			return (1);
		i++;
	}
	return (0);
}

int	map_size(char *mapfile)
{	
	int	fd;
	int	cpt;
	char	*line;

	cpt = 0;
	fd = open(mapfile, O_RDONLY);
	if (fd == -1)
		return (0);
	line = get_next_line(fd);
	if (line != NULL)
		cpt++;
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
		if (line != NULL)
			cpt++;
	}
	line = get_next_line(fd);
	free(line);
	close(fd);
	return (cpt);

}

char	**get_map(char *mapfile)
{
	int	fd;
	int	i;
	char	**tab_map;

	i = 0;
	tab_map = malloc(sizeof(char *) * (map_size(mapfile) + 1));
	fd = open(mapfile, O_RDONLY);
	if (fd == -1)
		return (NULL);
	while (i < 5)
	{
		tab_map[i] = get_next_line(fd);
		i++;

	}
	tab_map[i] = NULL;
	return (tab_map);
}

void	free_all(char **tab_map)
{
	int	i;

	i = 0;
	while (tab_map[i])
	{
		free (tab_map[i]);
		i++;
	}
	free(tab_map);	
}

int	valid_map(char *mapfile)
{
	char	**tab_map;
	int	exit;
	int	i;
	int	j;
	int	len;

	tab_map = get_map(mapfile);
	len = ft_strlen(tab_map[0]);
	i = 0;
	exit = 0;
	while(tab_map[i])
		i++;
	if (check_first_last_line(tab_map[0]) != 0 || check_first_last_line(tab_map[4]) != 0)
	{
		free_all(tab_map);
		return (1);
	}
	i = 1;
	while (tab_map[i] != NULL)
	{
		j = 0;
		while (tab_map[i][j] != '\n')
		{
			if ((tab_map[i][j] != '1' && tab_map[i][j] != '0' && tab_map[i][j] != 'E' && tab_map[i][j] != 'P' && tab_map[i][j] != 'C' &&  tab_map[i][j] != '\n') || tab_map[i][0] != '1' || tab_map[i][len - 2] != '1')
			{
				free_all(tab_map);
				return (1);
			}
			if (tab_map[i][j] == 'E')
				exit++;
			j++;
		}
		if (j != len)
		{
			free_all(tab_map);
			return (1);
		}
		i++;
	}
	free_all(tab_map);
	return (0);
}

int	verify_map(char *mapfile)
{
	if (verify_filename(mapfile) != 0)
		return (error(2, "file type should be *.ber"));
	if (valid_map(mapfile) != 0)
		return (error(3, "Map isn't valid"));
	return (0);
}

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

