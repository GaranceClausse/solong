/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_valid_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 12:02:50 by gclausse          #+#    #+#             */
/*   Updated: 2022/02/10 17:01:47 by gclausse         ###   ########.fr       */
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

char	**create_map(int fd,  t_mapinfo *mapinfo)
{
	char	**tab_map;
	char	*line;

	tab_map = NULL;
	line = get_next_line(fd);
	if (!line || line[0] == '\0')
	{
		free(line);
		void_error();
	}
	mapinfo->line_len = ft_strlen(line);
	while (line)
	{
		free(line);
		(mapinfo->line_count)++;
		line = get_next_line(fd);
	}
	tab_map = malloc(sizeof(char *) * ((mapinfo->line_count + 1)));
	if (!tab_map)
		void_error();
	return (tab_map);
}



char	**get_map(int fd, char **tab_map, t_mapinfo *mapinfo)
{
	int		i;

	tab_map[0] = get_next_line(fd);
	if (!tab_map[0])
	{
		free_all(tab_map);
		void_error();
	}
	i = 1;
	while (i < mapinfo->line_count)
	{
		tab_map[i] = get_next_line(fd);
		i++;
	}
	tab_map[i] = NULL;
	return (tab_map);
}

int	valid_map(char **tab_map, t_mapinfo *mapinfo)
{
	if (check_first_last_line(tab_map[0]) != 0
		|| check_first_last_line(tab_map[mapinfo->line_count - 1]) != 0
		|| check_player(tab_map) != 0
		|| check_collect_exit(tab_map) != 0
		|| check_letters(tab_map) != 0)
	{
		free_all(tab_map);
		return (error(3, "Map isn't valid"));
	}
	free_all(tab_map);
	return (0);
}
