/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 14:26:52 by gclausse          #+#    #+#             */
/*   Updated: 2022/02/21 13:20:11 by gclausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	int			fd;
	t_mapinfo	mapinfo;
	char		**tab_map;

	init_mapinfo(&mapinfo);
	if (argc != 2)
		error("two arguments needed");
	if (verify_filename(argv[1]) != 0)
		return (error("file type should be *.ber"));
	if (check_textures() != 0)
		return (error("Texture needed"));
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (error("couldn't open the file"));
	tab_map = create_map(fd, &mapinfo);
	close(fd);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (error("couldn't open the file"));
	tab_map = get_map(fd, tab_map, &mapinfo);
	display_map(tab_map, mapinfo);
	free_all(tab_map);
}
