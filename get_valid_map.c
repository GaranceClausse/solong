/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_valid_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 12:02:50 by gclausse          #+#    #+#             */
/*   Updated: 2022/02/10 12:12:36 by gclausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_size(char *mapfile)
{	
	int		fd;
	int		cpt;
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
	int		fd;
	int		i;
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

int	valid_map(char *mapfile)
{
	char	**tab_map;

	tab_map = get_map(mapfile);
	if (check_first_last_line(tab_map[0]) != 0
		|| check_first_last_line(tab_map[4]) != 0
		|| check_exit_player(tab_map) != 0
		|| check_letters(tab_map) != 0)
	{
		free_all(tab_map);
		return (1);
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
