/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 12:05:21 by gclausse          #+#    #+#             */
/*   Updated: 2022/02/10 17:25:04 by gclausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_all(char **tab_map)
{
	int	i;

	i = 0;
	if (tab_map)
	{
		while (tab_map[i])
		{
			free (tab_map[i]);
			i++;
		}
		free(tab_map);
	}
}

int	error(int n, char *str)
{
	write(2, str, ft_strlen(str));
	write(2, "\n", 1);
	errno = n;
	exit(EXIT_FAILURE);
}

void	void_error(char **tab_map)
{
	perror("Error");
	free_all(tab_map);
	exit(EXIT_FAILURE);
}
