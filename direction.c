#include "so_long.h"

int	direction(int keycode, t_combo *combo)
{
	find_player(combo);
	if (keycode == 65307)
		close_map(combo->mlx, combo->map);
	else if (keycode == 100
		&& combo->map[combo->mapinfo->y][combo->mapinfo->x + 1] != '1')
		move_right(combo);
	else if (keycode == 119
		&& combo->map[combo->mapinfo->y - 1][combo->mapinfo->x] != '1')
		move_up(combo);
	else if (keycode == 97
		&& combo->map[combo->mapinfo->y][combo->mapinfo->x - 1] != '1')
		move_left(combo);
	else if (keycode == 115
		&& combo->map[combo->mapinfo->y + 1][combo->mapinfo->x] != '1' )
		move_down(combo);
	return (0);
}

void	move_right(t_combo *combo)
{
	if (combo->map[combo->mapinfo->y][combo->mapinfo->x + 1] == 'C')
		combo->mapinfo->collectible--;
	if (combo->mapinfo->exit == 0)
		combo->map[combo->mapinfo->y][combo->mapinfo->x] = '0';
	else
	{
		combo->map[combo->mapinfo->y][combo->mapinfo->x] = 'E';
		combo->mapinfo->exit = 0;
	}
	if (combo->map[combo->mapinfo->y][combo->mapinfo->x + 1] == 'E' &&
		combo->mapinfo->collectible == 0)
		close_map(combo->mlx, combo->map);
	if (combo->map[combo->mapinfo->y][combo->mapinfo->x + 1] == 'E')
	       combo->mapinfo->exit = 1;	
	combo->map[combo->mapinfo->y][combo->mapinfo->x + 1] = 'P';
	combo->mapinfo->x++;
	printf("you moved %d times\n", ++combo->count);
	put_txt(combo->map, *combo->mlx, *combo->mapinfo);
}

void	move_up(t_combo *combo)
{
	if (combo->map[combo->mapinfo->y - 1][combo->mapinfo->x] == 'C')
		combo->mapinfo->collectible--;
	if (combo->mapinfo->exit == 0)
		combo->map[combo->mapinfo->y][combo->mapinfo->x] = '0';
	else
	{
		combo->map[combo->mapinfo->y][combo->mapinfo->x] = 'E';
		combo->mapinfo->exit = 0;
	}
	if (combo->map[combo->mapinfo->y - 1][combo->mapinfo->x] == 'E' &&
		combo->mapinfo->collectible == 0)
		close_map(combo->mlx, combo->map);
	if (combo->map[combo->mapinfo->y - 1][combo->mapinfo->x] == 'E')
	       combo->mapinfo->exit = 1;	
	combo->map[combo->mapinfo->y - 1][combo->mapinfo->x] = 'P';
	combo->mapinfo->y--;
	printf("you moved %d times\n", ++combo->count);
	put_txt(combo->map, *combo->mlx, *combo->mapinfo);
}

void	move_left(t_combo *combo)
{
	if (combo->map[combo->mapinfo->y][combo->mapinfo->x - 1] == 'C')
		combo->mapinfo->collectible--;
	if (combo->mapinfo->exit == 0)
		combo->map[combo->mapinfo->y][combo->mapinfo->x] = '0';
	else
	{
		combo->map[combo->mapinfo->y][combo->mapinfo->x] = 'E';
		combo->mapinfo->exit = 0;	
	}
	if (combo->map[combo->mapinfo->y][combo->mapinfo->x - 1] == 'E' &&
		combo->mapinfo->collectible == 0)
		close_map(combo->mlx, combo->map);
	if (combo->map[combo->mapinfo->y][combo->mapinfo->x - 1] == 'E')
	       combo->mapinfo->exit = 1;	
	combo->map[combo->mapinfo->y][combo->mapinfo->x - 1] = 'P';
	combo->mapinfo->x--;
	printf("you moved %d times\n", ++combo->count);
	put_txt(combo->map, *combo->mlx, *combo->mapinfo);
}

void	move_down(t_combo *combo)
{
	if (combo->map[combo->mapinfo->y + 1][combo->mapinfo->x] == 'C')
		combo->mapinfo->collectible--;
	if (combo->mapinfo->exit == 0)
		combo->map[combo->mapinfo->y][combo->mapinfo->x] = '0';
	else
		combo->map[combo->mapinfo->y][combo->mapinfo->x] = 'E';
	combo->mapinfo->exit = 0;	
	if (combo->map[combo->mapinfo->y + 1][combo->mapinfo->x] == 'E' &&
		combo->mapinfo->collectible == 0)
		close_map(combo->mlx, combo->map);
	if (combo->map[combo->mapinfo->y + 1][combo->mapinfo->x] == 'E')
	       combo->mapinfo->exit = 1;	
	combo->map[combo->mapinfo->y + 1][combo->mapinfo->x] = 'P';
	combo->mapinfo->y++;
	printf("you moved %d times\n", ++combo->count);
	put_txt(combo->map, *combo->mlx, *combo->mapinfo);
}

