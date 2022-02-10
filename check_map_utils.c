/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 11:57:23 by gclausse          #+#    #+#             */
/*   Updated: 2022/02/10 12:12:23 by gclausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

int	check_letters(char **tab_map)
{
	int	i;
	int	j;
	int	len;

	i = 1;
	len = ft_strlen(tab_map[0]);
	while (tab_map[i] != NULL)
	{
		j = 0;
		while (tab_map[i][j] != '\n')
		{
			if ((tab_map[i][j] != '1' && tab_map[i][j] != '0'
				&& tab_map[i][j] != 'E' && tab_map[i][j] != 'P'
				&& tab_map[i][j] != 'C' && tab_map[i][j] != '\n')
				|| tab_map[i][0] != '1' || tab_map[i][len - 2] != '1')
				return (1);
			j++;
		}
		if (j != len - 1)
			return (1);
		i++;
	}
	return (0);
}

int	check_exit_player(char **tab_map)
{
	int	i;
	int	j;
	int	exit;
	int	player;

	i = 1;
	exit = 0;
	player = 0;
	while (tab_map[i] != NULL)
	{
		j = 0;
		while (tab_map[i][j] != '\n')
		{
			if (tab_map[i][j] == 'E')
				exit++;
			if (tab_map[i][j] == 'P')
				player++;
			j++;
		}
		i++;
	}
	if (exit != 1 || player != 1)
		return (1);
	return (0);
}