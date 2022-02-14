#include "so_long.h"


int	direction(int keycode, t_combo *combo)
{
	if (keycode == 65307)
		close_map(combo->mlx, combo->map);
	else if (keycode == 100
		&& combo->map[combo->mapinfo->y][combo->mapinfo->x + 1] != '1' /*&&
			win_cond_right(combo)*/)
		move_right(combo);
	else if (keycode == 119
		&& combo->map[combo->mapinfo->y - 1][combo->mapinfo->x] != '1' /*&&
		win_cond_up(combo)*/)
		move_up(combo);
	else if (keycode == 97
		&& combo->map[combo->mapinfo->y][combo->mapinfo->x - 1] != '1' /*&&
		win_cond_left(combo)*/)
		move_left(combo);
	else if (keycode == 115
		&& combo->map[combo->mapinfo->y + 1][combo->mapinfo->x] != '1' /*&&
		win_cond_dowm(combo)*/)
		move_down(combo);
	return (0);
}

void	move_right(t_combo *combo)
{
	/*if (combo->map[combo->mapinfo->y][combo->mapinfo->x + 1] == 'C')
		combo->mapinfo->collectible--;
	combo->map[combo->mapinfo->y][combo->mapinfo->x] = '0';
	if (combo->map[combo->mapinfo->y][combo->mapinfo->x + 1] == 'E' &&
		combo->mapinfo->collectible == 0)
		close_map(combo->mlx, combo->map);*/
	collect_and_erase(combo, combo->mapinfo->y, combo->mapinfo->x + 1);
	combo->map[combo->mapinfo->y][combo->mapinfo->x + 1] = 'P';
	combo->mapinfo->x++;
	printf("%d\n", combo->count++);
	put_txt(combo->map, *combo->mlx, *combo->mapinfo);
}

void	move_up(t_combo *combo)
{
	/*if (combo->map[combo->mapinfo->y - 1][combo->mapinfo->x] == 'C')
		combo->mapinfo->collectible--;
	combo->map[combo->mapinfo->y][combo->mapinfo->x] = '0';
	if (combo->map[combo->mapinfo->y - 1][combo->mapinfo->x] == 'E' &&
		combo->mapinfo->collectible == 0)
		close_map(combo->mlx, combo->map);*/
	collect_and_erase(combo, combo->mapinfo->y - 1, combo->mapinfo->x);
	combo->map[combo->mapinfo->y - 1][combo->mapinfo->x] = 'P';
	combo->mapinfo->y--;
	printf("%d\n", combo->count++);
	put_txt(combo->map, *combo->mlx, *combo->mapinfo);
}

void	move_left(t_combo *combo)
{
	/*if (combo->map[combo->mapinfo->y][combo->mapinfo->x - 1] == 'C')
		combo->mapinfo->collectible--;
	combo->map[combo->mapinfo->y][combo->mapinfo->x] = '0';
	if (combo->map[combo->mapinfo->y][combo->mapinfo->x - 1] == 'E'
		&& combo->mapinfo->collectible == 0)
		close_map(combo->mlx, combo->map);*/
	collect_and_erase(combo, combo->mapinfo->y, combo->mapinfo->x - 1);
	combo->map[combo->mapinfo->y][combo->mapinfo->x - 1] = 'P';
	combo->mapinfo->x--;
	printf("%d\n", combo->count++);
	put_txt(combo->map, *combo->mlx, *combo->mapinfo);
}

void	move_down(t_combo *combo)
{
	/*if (combo->map[combo->mapinfo->y + 1][combo->mapinfo->x] == 'C')
		combo->mapinfo->collectible--;
	combo->map[combo->mapinfo->y][combo->mapinfo->x] = '0';
	if (combo->map[combo->mapinfo->y + 1][combo->mapinfo->x] == 'E'
		&& combo->mapinfo->collectible == 0)
		close_map(combo->mlx, combo->map);*/
	collect_and_erase(combo, combo->mapinfo->y + 1, combo->mapinfo->x);
	combo->map[combo->mapinfo->y + 1][combo->mapinfo->x] = 'P';
	combo->mapinfo->y++;
	printf("%d\n", combo->count++);
	put_txt(combo->map, *combo->mlx, *combo->mapinfo);
}

void collect_and_erase(t_combo *combo, int x, int y)
{
	if (combo->map[y][x] == 'C')
		combo->mapinfo->collectible--;
	combo->map[y][x] = '0';
	if (combo->map[y + 1][x] == 'E'
		&& combo->mapinfo->collectible == 0)
		close_map(combo->mlx, combo->map);

}