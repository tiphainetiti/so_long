/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlay <tlay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 13:47:19 by tlay              #+#    #+#             */
/*   Updated: 2024/04/12 18:10:49 by tlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_print_error(char *str)
{
	write(2, str, ft_strlen(str));
	write(2, "\n", 1);
}

void	ft_error_map(t_vars *vars)
{
	free(vars->map.map_line);
	vars->fd = close(vars->fd);
	exit(EXIT_FAILURE);
}

void	ft_error_img(t_vars *vars)
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
		|| !vars->img.exit_unlocked_fire2 || !vars->img.enemy_front_grass)
	{
		ft_print_error("Image missing.");
		ft_free_tab(vars->map.array);
		destroy_img(vars);
		mlx_destroy_display(vars->mlx.mlx);
		free(vars->mlx.mlx);
		vars->fd = close(vars->fd);
		exit(EXIT_FAILURE);
	}
}

void	ft_security_img(t_vars *vars, int img)
{
	if (img == -1)
	{
		ft_print_error("Image not valid.");
		close_window(vars);
	}
}
