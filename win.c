/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 16:21:34 by gclausse          #+#    #+#             */
/*   Updated: 2022/02/16 16:27:01 by gclausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	win_up(t_combo *combo)
{
	if (combo->mapinfo->collectible == 0 && combo->map[combo->mapinfo->y - 1][combo->mapinfo->x] == 'E')
		return (0);
	else
		return (1);
}
