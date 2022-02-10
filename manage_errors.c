/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 12:05:21 by gclausse          #+#    #+#             */
/*   Updated: 2022/02/10 12:12:58 by gclausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

int	error(int n, char *str)
{
	printf("%s\n", str);
	return (n);
}
