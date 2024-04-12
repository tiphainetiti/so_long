/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlay <tlay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 13:49:57 by tlay              #+#    #+#             */
/*   Updated: 2024/04/12 18:07:30 by tlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	animation_player_2(t_vars *vars, int x, int y)
{
	if (vars->game.keycode == S || vars->game.keycode == DOWN)
	{
		mlx_put_image_to_window(vars->mlx.mlx, vars->mlx.wind.wind,
			vars->img.player_front_exit_fire1, x, y);
		mlx_do_sync(vars->mlx.mlx);
		usleep(100000);
		mlx_put_image_to_window(vars->mlx.mlx, vars->mlx.wind.wind,
			vars->img.player_front_exit_fire2, x, y);
		mlx_do_sync(vars->mlx.mlx);
		usleep(100000);
	}
	else if (vars->game.keycode == D || vars->game.keycode == RIGHT)
	{
		mlx_put_image_to_window(vars->mlx.mlx, vars->mlx.wind.wind,
			vars->img.player_right_exit_fire1, x, y);
		mlx_do_sync(vars->mlx.mlx);
		usleep(100000);
		mlx_put_image_to_window(vars->mlx.mlx, vars->mlx.wind.wind,
			vars->img.player_right_exit_fire2, x, y);
		mlx_do_sync(vars->mlx.mlx);
		usleep(100000);
	}
}

void	animation_player_1(t_vars *vars, int x, int y)
{
	if (vars->game.keycode == W || vars->game.keycode == UP)
	{
		mlx_put_image_to_window(vars->mlx.mlx, vars->mlx.wind.wind,
			vars->img.player_back_exit_fire1, x, y);
		mlx_do_sync(vars->mlx.mlx);
		usleep(100000);
		mlx_put_image_to_window(vars->mlx.mlx, vars->mlx.wind.wind,
			vars->img.player_back_exit_fire2, x, y);
		mlx_do_sync(vars->mlx.mlx);
		usleep(100000);
	}
	else if (vars->game.keycode == A || vars->game.keycode == LEFT)
	{
		mlx_put_image_to_window(vars->mlx.mlx, vars->mlx.wind.wind,
			vars->img.player_left_exit_fire1, x, y);
		mlx_do_sync(vars->mlx.mlx);
		usleep(100000);
		mlx_put_image_to_window(vars->mlx.mlx, vars->mlx.wind.wind,
			vars->img.player_left_exit_fire2, x, y);
		mlx_do_sync(vars->mlx.mlx);
		usleep(100000);
	}
}

void	animation_exit_locked(t_vars *vars, int x, int y)
{
	mlx_put_image_to_window(vars->mlx.mlx, vars->mlx.wind.wind,
		vars->img.exit_locked_fire1, x, y);
	mlx_do_sync(vars->mlx.mlx);
	usleep(100000);
	mlx_put_image_to_window(vars->mlx.mlx, vars->mlx.wind.wind,
		vars->img.exit_locked_fire2, x, y);
	mlx_do_sync(vars->mlx.mlx);
	usleep(100000);
}

void	animation_exit_unlocked(t_vars *vars, int x, int y)
{
	mlx_put_image_to_window(vars->mlx.mlx, vars->mlx.wind.wind,
		vars->img.exit_unlocked_fire1, x, y);
	mlx_do_sync(vars->mlx.mlx);
	usleep(100000);
	mlx_put_image_to_window(vars->mlx.mlx, vars->mlx.wind.wind,
		vars->img.exit_unlocked_fire2, x, y);
	mlx_do_sync(vars->mlx.mlx);
	usleep(100000);
}

int	animations(t_vars *vars)
{
	int	x;
	int	y;

	y = ft_find_x(&vars->map, 'E') * vars->img.width;
	x = ft_find_y(&vars->map, 'E') * vars->img.height;
	print_mov(vars);
	if (vars->map.player.position_x == ft_find_x(&vars->map, 'E')
		&& vars->map.player.position_y == ft_find_y(&vars->map, 'E'))
	{
		animation_player_1(vars, x, y);
		animation_player_2(vars, x, y);
	}
	else if (vars->counter.collect == 0 && vars->game.exit_unlocked == true)
		animation_exit_unlocked(vars, x, y);
	else
		animation_exit_locked(vars, x, y);
	return (0);
}
