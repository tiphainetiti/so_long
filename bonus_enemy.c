/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_enemy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlay <tlay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 11:22:48 by tlay              #+#    #+#             */
/*   Updated: 2024/04/04 19:55:19 by tlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_enemy_position(t_vars *vars)
{
	const int	min_x = 1;
	const int	max_x = vars->map.height - 2;
	const int	min_y = 1;
	const int	max_y = vars->map.width - 2;

	srand(time(NULL));
	vars->map.enemy.position_x = min_x + rand() % (max_x - min_x + 1);
	vars->map.enemy.position_y = min_y + rand() % (max_y - min_y + 1);
	while (1)
	{
		if (vars->map.array[vars->map.enemy.position_x][vars->map.enemy.position_y] == '0')
			break ;
		vars->map.enemy.position_x = min_x + rand() % (max_x - min_x + 1);
		vars->map.enemy.position_y = min_y + rand() % (max_y - min_y + 1);
	}
	vars->map.array[vars->map.enemy.position_x][vars->map.enemy.position_y] = 'e';
	printf("enemy x : %d\n", vars->map.enemy.position_x);
	printf("enemy y : %d\n", vars->map.enemy.position_y);
	print_map(vars);
}

void	update_enemy_position(t_vars *vars, int new_pos_x, int new_pos_y)
{
	int	x;
	int	y;

	x = vars->map.enemy.position_x;
	y = vars->map.enemy.position_y;
	// if (x == ft_find_x(&vars->map, 'E') && y == ft_find_y(&vars->map, 'E'))
	//	vars->map.array[x][y] = 'E';
	// else
	vars->map.array[x][y] = '0';
	if (new_pos_x == x - 1)
		vars->map.enemy.position_x--;
	if (new_pos_y == y - 1)
		vars->map.enemy.position_y--;
	if (new_pos_x == x + 1)
		vars->map.enemy.position_x++;
	if (new_pos_y == y + 1)
		vars->map.enemy.position_y++;
}

void	enemy_run_game(t_vars *vars, int new_pos_x, int new_pos_y)
{
	int	x;
	int	y;

	x = vars->map.enemy.position_x;
	y = vars->map.enemy.position_y;
	if (vars->map.array[new_pos_x][new_pos_y] == '1'
		|| vars->map.array[new_pos_x][new_pos_y] == 'C'
		|| vars->map.array[new_pos_x][new_pos_y] == 'E')
		return ;
	else if (vars->map.array[new_pos_x][new_pos_y] == '0')
		update_enemy_position(vars, new_pos_x, new_pos_y);
	else if (vars->map.array[new_pos_x][new_pos_y] == 'P')
		close_window(vars);
	ft_fill_window(vars);
}

int	enemy_mov(t_vars *vars)
{
	int	x;
	int	y;
	int	i;

	x = vars->map.enemy.position_x;
	y = vars->map.enemy.position_y;
	i = rand() % 4;
	if (i == 0)
		enemy_run_game(vars, x - 1, y);
	if (i == 1)
		enemy_run_game(vars, x, y - 1);
	if (i == 2)
		enemy_run_game(vars, x + 1, y);
	if (i == 3)
		enemy_run_game(vars, x, y + 1);
	return (0);
}
