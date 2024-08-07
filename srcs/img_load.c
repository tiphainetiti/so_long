/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_load.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlay <tlay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 17:34:19 by tlay              #+#    #+#             */
/*   Updated: 2024/04/18 16:34:07 by tlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	img_enemy(t_vars *vars)
{
	vars->img.enemy_front_grass = mlx_xpm_file_to_image(vars->mlx.mlx,
			IMG_PATH "enemy_front_grass.xpm", &vars->img.width,
			&vars->img.height);
	vars->img.enemy_back_grass = mlx_xpm_file_to_image(vars->mlx.mlx,
			IMG_PATH "enemy_back_grass.xpm", &vars->img.width,
			&vars->img.height);
	vars->img.enemy_right_grass = mlx_xpm_file_to_image(vars->mlx.mlx,
			IMG_PATH "enemy_right_grass.xpm", &vars->img.width,
			&vars->img.height);
	vars->img.enemy_left_grass = mlx_xpm_file_to_image(vars->mlx.mlx,
			IMG_PATH "enemy_left_grass.xpm", &vars->img.width,
			&vars->img.height);
}

void	img_player(t_vars *vars)
{
	vars->img.player_front_grass = mlx_xpm_file_to_image(vars->mlx.mlx,
			IMG_PATH "player_front_grass.xpm", &vars->img.width,
			&vars->img.height);
	vars->img.player_back_grass = mlx_xpm_file_to_image(vars->mlx.mlx,
			IMG_PATH "player_back_grass.xpm", &vars->img.width,
			&vars->img.height);
	vars->img.player_left_grass = mlx_xpm_file_to_image(vars->mlx.mlx,
			IMG_PATH "player_left_grass.xpm", &vars->img.width,
			&vars->img.height);
	vars->img.player_right_grass = mlx_xpm_file_to_image(vars->mlx.mlx,
			IMG_PATH "player_right_grass.xpm", &vars->img.width,
			&vars->img.height);
}

void	img_exit_fire(t_vars *vars)
{
	vars->img.player_front_exit_fire1 = mlx_xpm_file_to_image(vars->mlx.mlx,
			IMG_PATH "player_front_exit_fire1.xpm", &vars->img.width,
			&vars->img.height);
	vars->img.player_front_exit_fire2 = mlx_xpm_file_to_image(vars->mlx.mlx,
			IMG_PATH "player_front_exit_fire2.xpm", &vars->img.width,
			&vars->img.height);
	vars->img.player_back_exit_fire1 = mlx_xpm_file_to_image(vars->mlx.mlx,
			IMG_PATH "player_back_exit_fire1.xpm", &vars->img.width,
			&vars->img.height);
	vars->img.player_back_exit_fire2 = mlx_xpm_file_to_image(vars->mlx.mlx,
			IMG_PATH "player_back_exit_fire2.xpm", &vars->img.width,
			&vars->img.height);
	vars->img.player_right_exit_fire1 = mlx_xpm_file_to_image(vars->mlx.mlx,
			IMG_PATH "player_right_exit_fire1.xpm", &vars->img.width,
			&vars->img.height);
	vars->img.player_right_exit_fire2 = mlx_xpm_file_to_image(vars->mlx.mlx,
			IMG_PATH "player_right_exit_fire2.xpm", &vars->img.width,
			&vars->img.height);
	vars->img.player_left_exit_fire1 = mlx_xpm_file_to_image(vars->mlx.mlx,
			IMG_PATH "player_left_exit_fire1.xpm", &vars->img.width,
			&vars->img.height);
	vars->img.player_left_exit_fire2 = mlx_xpm_file_to_image(vars->mlx.mlx,
			IMG_PATH "player_left_exit_fire2.xpm", &vars->img.width,
			&vars->img.height);
}

void	ft_img(t_vars *vars)
{
	ft_img_init(vars);
	vars->img.wall = mlx_xpm_file_to_image(vars->mlx.mlx, IMG_PATH "wall.xpm",
			&vars->img.width, &vars->img.height);
	vars->img.grass = mlx_xpm_file_to_image(vars->mlx.mlx, IMG_PATH "grass.xpm",
			&vars->img.width, &vars->img.height);
	vars->img.collect = mlx_xpm_file_to_image(vars->mlx.mlx,
			IMG_PATH "collect_water2.xpm", &vars->img.width, &vars->img.height);
	vars->img.exit_locked_fire1 = mlx_xpm_file_to_image(vars->mlx.mlx,
			IMG_PATH "exit_locked_fire1.xpm", &vars->img.width,
			&vars->img.height);
	vars->img.exit_locked_fire2 = mlx_xpm_file_to_image(vars->mlx.mlx,
			IMG_PATH "exit_locked_fire2.xpm", &vars->img.width,
			&vars->img.height);
	vars->img.exit_unlocked_fire1 = mlx_xpm_file_to_image(vars->mlx.mlx,
			IMG_PATH "exit_unlocked_fire1.xpm", &vars->img.width,
			&vars->img.height);
	vars->img.exit_unlocked_fire2 = mlx_xpm_file_to_image(vars->mlx.mlx,
			IMG_PATH "exit_unlocked_fire2.xpm", &vars->img.width,
			&vars->img.height);
	img_player(vars);
	img_enemy(vars);
	img_exit_fire(vars);
	error_img(vars);
}
