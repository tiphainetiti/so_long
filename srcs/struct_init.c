/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlay <tlay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 17:31:31 by tlay              #+#    #+#             */
/*   Updated: 2024/04/18 15:46:22 by tlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// Initialize my variabes
void	ft_vars_init(t_vars *vars)
{
	vars->game.keycode = 0;
	vars->game.exit_unlocked = false;
	vars->game.front = false;
	vars->game.back = false;
	vars->game.left = false;
	vars->game.right = false;
	vars->game.win = false;
	vars->movements = 0;
	vars->map.array = NULL;
	vars->map.exit = 0;
	vars->map.player.i = 0;
	vars->map.player.position_x = 0;
	vars->map.player.position_y = 0;
	vars->map.enemy.position_x = 0;
	vars->map.enemy.position_y = 0;
	vars->map.enemy.diff_x = 0;
	vars->map.enemy.diff_y = 0;
	vars->map.enemy.down = 0;
	vars->map.enemy.up = 0;
	vars->map.enemy.left = 0;
	vars->map.enemy.right = 0;
	vars->map.wall = 0;
	vars->map.collect = 0;
	vars->counter.collect = 0;
	vars->counter.exit = 0;
}

// Initialize images
void	ft_img_init(t_vars *vars)
{
	vars->img.collect = NULL;
	vars->img.grass = NULL;
	vars->img.wall = NULL;
	vars->img.player_front_grass = NULL;
	vars->img.player_back_grass = NULL;
	vars->img.player_left_grass = NULL;
	vars->img.player_right_grass = NULL;
	vars->img.exit_locked_fire1 = NULL;
	vars->img.exit_locked_fire2 = NULL;
	vars->img.exit_unlocked_fire1 = NULL;
	vars->img.exit_unlocked_fire2 = NULL;
	vars->img.player_front_exit_fire1 = NULL;
	vars->img.player_back_exit_fire1 = NULL;
	vars->img.player_left_exit_fire1 = NULL;
	vars->img.player_right_exit_fire1 = NULL;
	vars->img.player_front_exit_fire2 = NULL;
	vars->img.player_back_exit_fire2 = NULL;
	vars->img.player_left_exit_fire2 = NULL;
	vars->img.player_right_exit_fire2 = NULL;
	vars->img.enemy_front_grass = NULL;
	vars->img.enemy_back_grass = NULL;
	vars->img.enemy_right_grass = NULL;
	vars->img.enemy_left_grass = NULL;
	vars->img.height = 0;
	vars->img.width = 0;
}

// Reset counter to 0
void	reset_counter(t_counter *counter)
{
	counter->collect = 0;
	counter->exit = 0;
}
