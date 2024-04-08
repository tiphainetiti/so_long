/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_enemy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlay <tlay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 11:22:48 by tlay              #+#    #+#             */
/*   Updated: 2024/04/08 19:00:42 by tlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_enemy_position(t_vars *vars)
{
	const int	min_x = 1;
	const int	max_x = vars->map.height - 2;
	const int	min_y = 1;
	const int	max_y = vars->map.width - 2;

	srand(time(NULL));
	vars->map.enemy.position_x = min_x + rand() % (max_x - min_x + 1);
	vars->map.enemy.position_y = min_y + rand() % (max_y - min_y + 1);
	while (vars->map.array[vars->map.enemy.position_x][vars->map.enemy.position_y] != '0')
	{
		vars->map.enemy.position_x = min_x + rand() % (max_x - min_x + 1);
		vars->map.enemy.position_y = min_y + rand() % (max_y - min_y + 1);
	}
	vars->map.array[vars->map.enemy.position_x][vars->map.enemy.position_y] = 'e';
}

void	update_enemy_position(t_vars *vars, int new_pos_x, int new_pos_y)
{
	int	x;
	int	y;

	x = vars->map.enemy.position_x;
	y = vars->map.enemy.position_y;
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
	{
		update_enemy_position(vars, new_pos_x, new_pos_y);
		vars->map.array[new_pos_x][new_pos_y] = 'e';
	}
	else if (vars->map.array[new_pos_x][new_pos_y] == 'P')
		close_window(vars);
	ft_fill_window(vars);
}

// ENEMY_MOV QUI MARCHE
int	enemy_mov(int keycode, t_vars *vars)
{
	int	x;
	int	y;
	int	i;

	printf("enemy x : %d\n", vars->map.enemy.position_x);
	printf("enemy y : %d\n", vars->map.enemy.position_y);
	x = vars->map.enemy.position_x;
	y = vars->map.enemy.position_y;
	i = rand() % 4;
	if (keycode == W || keycode == A || keycode == S || keycode == D
		|| keycode == UP || keycode == DOWN || keycode == LEFT
		|| keycode == RIGHT)
	{
		if (i == 0)
			enemy_run_game(vars, x - 1, y);
		else if (i == 1)
			enemy_run_game(vars, x, y - 1);
		else if (i == 2)
			enemy_run_game(vars, x + 1, y);
		else if (i == 3)
			enemy_run_game(vars, x, y + 1);
	}
	return (0);
}

// int	way_to_player(t_vars *vars, int enemy_x, int enemy_y)
//{
//	int	player_x;
//	int	player_y;

//	player_x = vars->map.player.position_x;
//	player_y = vars->map.player.position_y;
//	vars->map.enemy.diff_x = player_x - enemy_x;
//	vars->map.enemy.diff_y = player_y - enemy_y;
//	if (vars->map.enemy.diff_x < 0)
//		vars->map.enemy.diff_x = -vars->map.enemy.diff_x;
//	if (vars->map.enemy.diff_y < 0)
//		vars->map.enemy.diff_y = -vars->map.enemy.diff_y;
//	if (vars->map.enemy.diff_x >= vars->map.enemy.diff_y)
//	{
//		if (vars->map.enemy.diff_y >= 0)
//			return (vars->map.enemy.diff_x);
//		else
//			return (-vars->map.enemy.diff_x);
//	}
//	else
//	{
//		if (vars->map.enemy.diff_x >= 0)
//			return (vars->map.enemy.diff_y);
//		else
//			return (-vars->map.enemy.diff_y);
//	}
//}

// int	enemy_mov(int keycode, t_vars *vars)
//{
//	int	x;
//	int	y;
//	int	go;

//	printf("enemy x : %d\n", vars->map.enemy.position_x);
//	printf("enemy y : %d\n", vars->map.enemy.position_y);
//	x = vars->map.enemy.position_x;
//	y = vars->map.enemy.position_y;
//	if (keycode == W || keycode == A || keycode == S || keycode == D
//		|| keycode == UP || keycode == DOWN || keycode == LEFT
//		|| keycode == RIGHT)
//	{
//		go = way_to_player(vars, x, y);
//		printf("go = %d\n", go);
//		if (go == -vars->map.enemy.diff_x)
//			enemy_run_game(vars, x - 1, y);
//		else if (go == -vars->map.enemy.diff_y)
//			enemy_run_game(vars, x, y - 1);
//		else if (go == vars->map.enemy.diff_x)
//			enemy_run_game(vars, x + 1, y);
//		else
//			enemy_run_game(vars, x, y + 1);
//	}
//	else
//		ft_print_error("error : enemy mov\n");
//	return (0);
//}
