/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 14:26:52 by gclausse          #+#    #+#             */
/*   Updated: 2022/01/31 15:03:27 by gclausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	verify_filename(char *mapfile)
{
	int	len;

	len = ft_strlen(mapfile);
	if (mapfile[len - 4] == '.' && mapfile[len - 3] == 'b'
		&& mapfile[len - 2] == 'e' && mapfile[len - 1] == 'r')
		return (0);
	return (1);
}

int	check_fisrt_last_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
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


	fd = open("mapfile", O_RDONLY);
	exit = 0;
	if (fd == -1)
		exit(error(1, "Couldn't open the file"));
	line = get_next_line(fd);
	if (check_first_last_line(line) != 0)
		return (1);
	while (line)
	{
		i = 0;
		line = get_next_line(fd);
		while (line[i++])
		{
			if (line[i] == 'E')
				exit++;
		}
		if (line[0] != 1 || line[ft_strlen(line) - 1] != 1)
			return (1);
	}
	if (check_first_last_line(line) != 0 || exit != 1)
		return (1);
	return (0);

}

int	verify_map(char *mapfile)
{
	if (verify_filename(mapfile) != 0)
		return (error(2, "file type should be .ber"));
	if (valid_map(mapfile) != 0)
		return (error(3, "Map isn't valid"));
}

int	main(int argc, char **argv)
{
	t_module	*module;

	if (argc == 2)
	{
		module = malloc(1 * sizeof(t_module));
		if (module == NULL)
			exit(error(14, "Memory error"));
		if (verify_map(argv[1], module) == 0)
		{
			start_game(module);
			hook(module);
			mlx_loop(module->vars->mlx);
		}
		else
		{
			clear_map(module->map);
			free_ptr((void **)&module);
			exit(-1);
		}
	}
	else
		exit (error(22, "Please run with a map path in the terminal!"));
}

