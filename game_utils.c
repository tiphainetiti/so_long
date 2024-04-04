/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlay <tlay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 16:18:49 by tlay              #+#    #+#             */
/*   Updated: 2024/04/04 12:17:42 by tlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	destroy_img_enemy(t_vars *vars)
{
	if (vars->img.enemy_front_grass)
		mlx_destroy_image(vars->mlx.mlx, vars->img.enemy_front_grass);
}

void	destroy_img_player(t_vars *vars)
{
	if (vars->img.player_back_exit)
		mlx_destroy_image(vars->mlx.mlx, vars->img.player_back_exit);
	if (vars->img.player_back_grass)
		mlx_destroy_image(vars->mlx.mlx, vars->img.player_back_grass);
	if (vars->img.player_front_exit)
		mlx_destroy_image(vars->mlx.mlx, vars->img.player_front_exit);
	if (vars->img.player_front_grass)
		mlx_destroy_image(vars->mlx.mlx, vars->img.player_front_grass);
	if (vars->img.player_left_exit)
		mlx_destroy_image(vars->mlx.mlx, vars->img.player_left_exit);
	if (vars->img.player_left_grass)
		mlx_destroy_image(vars->mlx.mlx, vars->img.player_left_grass);
	if (vars->img.player_right_exit)
		mlx_destroy_image(vars->mlx.mlx, vars->img.player_right_exit);
	if (vars->img.player_right_grass)
		mlx_destroy_image(vars->mlx.mlx, vars->img.player_right_grass);
}

void	destroy_img(t_vars *vars)
{
	if (vars->img.collect)
		mlx_destroy_image(vars->mlx.mlx, vars->img.collect);
	if (vars->img.wall)
		mlx_destroy_image(vars->mlx.mlx, vars->img.wall);
	if (vars->img.grass)
		mlx_destroy_image(vars->mlx.mlx, vars->img.grass);
	if (vars->img.exit_end_game)
		mlx_destroy_image(vars->mlx.mlx, vars->img.exit_end_game);
	if (vars->img.exit_locked)
		mlx_destroy_image(vars->mlx.mlx, vars->img.exit_locked);
	if (vars->img.exit_unlocked)
		mlx_destroy_image(vars->mlx.mlx, vars->img.exit_unlocked);
	destroy_img_player(vars);
	destroy_img_enemy(vars);
}

int	close_window(t_vars *vars)
{
	ft_free_tab(vars->map.array);
	destroy_img(vars);
	mlx_destroy_window(vars->mlx.mlx, vars->mlx.wind.wind);
	mlx_destroy_display(vars->mlx.mlx);
	free(vars->mlx.mlx);
	vars->fd = close(vars->fd);
	exit(EXIT_SUCCESS);
}

void	update_player_position(t_vars *vars, int new_pos_x, int new_pos_y)
{
	int	x;
	int	y;

	x = vars->map.player.position_x;
	y = vars->map.player.position_y;
	if (x == ft_find_x(&vars->map, 'E') && y == ft_find_y(&vars->map, 'E'))
		vars->map.array[x][y] = 'E';
	else
		vars->map.array[x][y] = '0';
	if (new_pos_x == x - 1)
		vars->map.player.position_x--;
	if (new_pos_y == y - 1)
		vars->map.player.position_y--;
	if (new_pos_x == x + 1)
		vars->map.player.position_x++;
	if (new_pos_y == y + 1)
		vars->map.player.position_y++;
	vars->movements++;
}
