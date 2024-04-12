/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlay <tlay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 14:13:23 by tlay              #+#    #+#             */
/*   Updated: 2024/04/12 18:12:30 by tlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

//  Display the window when the game is launched
void	ft_start_game(t_vars *vars)
{
	vars->mlx.wind.height = vars->img.height * vars->map.height;
	vars->mlx.wind.width = vars->img.width * vars->map.width;
	vars->mlx.wind.wind = mlx_new_window(vars->mlx.mlx, vars->mlx.wind.width,
			vars->mlx.wind.height, "so_long");
	ft_fill_window(vars);
}

// Process command according to map direction
void	run_game(t_vars *vars, int new_x, int new_y)
{
	if (vars->map.array[new_x][new_y] == 'C'
		|| vars->map.array[new_x][new_y] == '0')
	{
		if (vars->map.array[new_x][new_y] == 'C')
		{
			vars->counter.collect--;
			write(1, "---> +1 water!\n", 15);
			if (vars->counter.collect == 0)
			{
				vars->game.exit_unlocked = true;
				write(1, "===>> Puts out the fire!!!!\n", 28);
			}
		}
		vars->map.array[new_x][new_y] = 'P';
	}
	else if (vars->map.array[new_x][new_y] == 'e'
		|| (vars->map.array[new_x][new_y] == 'E'
			&& vars->game.exit_unlocked == true))
		close_window(vars);
	else if (vars->map.array[new_x][new_y] == '1')
		return ;
	update_player_position(vars, new_x, new_y);
	ft_fill_window(vars);
}

// Process when keys are pressed
int	key_handler(int keycode, t_vars *vars)
{
	int	x;
	int	y;

	x = vars->map.player.position_x;
	y = vars->map.player.position_y;
	vars->game.keycode = keycode;
	if (keycode == W || keycode == UP)
		run_game(vars, x - 1, y);
	else if (keycode == A || keycode == LEFT)
		run_game(vars, x, y - 1);
	else if (keycode == S || keycode == DOWN)
		run_game(vars, x + 1, y);
	else if (keycode == D || keycode == RIGHT)
		run_game(vars, x, y + 1);
	else if (keycode == ESC)
		close_window(vars);
	enemy_mov(keycode, vars);
	return (0);
}
