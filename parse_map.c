/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 14:26:52 by gclausse          #+#    #+#             */
/*   Updated: 2022/02/04 16:49:51 by gclausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	error(int n, char *str)
{
	printf("%s\n", str);
	return (n);
}

int	close(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}

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

int	valid_map(char *mapfile)
{
	int	fd;
	int	i;
	int	exit;
	char	*line;
	int	j;
	int 	len;


	fd = open(mapfile, O_RDONLY);
	exit = 0;
	if (fd == -1)
		return (error(1, "Couldn't open the file"));
	line = get_next_line(fd);
	len = ft_strlen(line);
	if (check_first_last_line(line) != 0)
		return (1);
	j = 5;
	while (j-- > 1)
	{
		i = 0;
		line = get_next_line(fd);
		while (line[i++] != '\n')
		{
			if(line[i] != '1' && line[i] != '0' &&line[i] != 'E' && line[i] != 'P' && line[i] != 'C' && line[i] != '\n')
				return (1);
			if (line[i] == 'E')
				exit++;
		}
		if (line[0] != '1' || line[ft_strlen(line) - 2] != '1')
			return (1);
		if (i != len)
			return (1);
	}
	if (check_first_last_line(line) != 0 || exit != 1)
		return (1);
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
			t_vars	vars;
	
			vars.mlx = mlx_init();
			vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
			mlx_hook(vars.win, 2, 1L<<0, close, &vars);
			mlx_loop(vars.mlx);
			printf("map o");
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

