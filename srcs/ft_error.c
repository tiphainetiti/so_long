/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlay <tlay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 13:47:19 by tlay              #+#    #+#             */
/*   Updated: 2024/04/18 18:17:48 by tlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	print_error(char *str)
{
	write(2, str, ft_strlen(str));
	write(2, "\n", 1);
}

void	error_map_line(t_vars *vars)
{
	free(vars->map.map_line);
	vars->fd = close(vars->fd);
	exit(EXIT_FAILURE);
}

void	error_map(t_vars *vars)
{
	free_tab(vars->map.array);
	vars->fd = close(vars->fd);
	exit(EXIT_FAILURE);
}

void	error_img(t_vars *vars)
{
	if (!vars->img.collect || !vars->img.wall || !vars->img.grass
		|| !vars->img.player_front_grass || !vars->img.player_back_grass
		|| !vars->img.player_left_grass || !vars->img.player_right_grass
		|| !vars->img.player_front_exit_fire1
		|| !vars->img.player_back_exit_fire1
		|| !vars->img.player_left_exit_fire1
		|| !vars->img.player_right_exit_fire1
		|| !vars->img.player_front_exit_fire2
		|| !vars->img.player_back_exit_fire2
		|| !vars->img.player_left_exit_fire2
		|| !vars->img.player_right_exit_fire2 || !vars->img.exit_locked_fire1
		|| !vars->img.exit_locked_fire2 || !vars->img.exit_unlocked_fire1
		|| !vars->img.exit_unlocked_fire2 || !vars->img.enemy_front_grass
		|| !vars->img.enemy_back_grass || !vars->img.enemy_right_grass
		|| !vars->img.enemy_left_grass)
	{
		print_error("Image missing.");
		destroy_img(vars);
		mlx_destroy_display(vars->mlx.mlx);
		free(vars->mlx.mlx);
		error_map(vars);
	}
}

void	security_img(t_vars *vars, int img)
{
	if (img == -1)
	{
		print_error("Image not valid.");
		close_window(vars);
	}
}
