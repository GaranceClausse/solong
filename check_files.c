/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 13:51:21 by gclausse          #+#    #+#             */
/*   Updated: 2022/02/17 13:53:46 by gclausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_textures(void)
{
	int	fd;

	fd = open(FLOOR, O_RDONLY);
	if (fd == -1)
		return (1);
	close(fd);
	fd = open(WALL, O_RDONLY);
	if (fd == -1)
		return (1);
	close(fd);
	fd = open(PLAYER, O_RDONLY);
	if (fd == -1)
		return (1);
	close(fd);
	fd = open(COLLECT, O_RDONLY);
	if (fd == -1)
		return (1);
	close(fd);
	fd = open(EXIT, O_RDONLY);
	if (fd == -1)
		return (1);
	close(fd);
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
