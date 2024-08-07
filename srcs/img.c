/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlay <tlay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 17:35:45 by tlay              #+#    #+#             */
/*   Updated: 2024/04/18 16:35:25 by tlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// Find player image according to key
void	*player_texture(t_vars vars)
{
	if (vars.game.keycode == W || vars.game.keycode == UP)
		return (vars.img.player_back_grass);
	else if (vars.game.keycode == A || vars.game.keycode == LEFT)
		return (vars.img.player_left_grass);
	else if (vars.game.keycode == S || vars.game.keycode == DOWN)
		return (vars.img.player_front_grass);
	else if (vars.game.keycode == D || vars.game.keycode == RIGHT)
		return (vars.img.player_right_grass);
	else
		return (vars.img.player_front_grass);
}

// Find exit image according to key
void	*exit_texture(t_vars vars)
{
	int	x;
	int	y;

	x = vars.map.player.position_x;
	y = vars.map.player.position_y;
	if (x == find_x(&vars.map, 'E') && y == find_y(&vars.map, 'E'))
	{
		if (vars.game.keycode == W || vars.game.keycode == UP)
			return (vars.img.player_back_exit_fire1);
		else if (vars.game.keycode == A || vars.game.keycode == LEFT)
			return (vars.img.player_left_exit_fire1);
		else if (vars.game.keycode == S || vars.game.keycode == DOWN)
			return (vars.img.player_front_exit_fire1);
		else if (vars.game.keycode == D || vars.game.keycode == RIGHT)
			return (vars.img.player_right_exit_fire1);
		else
			return (vars.img.exit_locked_fire1);
	}
	else
		return (vars.img.exit_locked_fire1);
}

void	*find_texture(char element, t_vars vars)
{
	if (element == '1')
		return (vars.img.wall);
	else if (element == '0')
		return (vars.img.grass);
	else if (element == 'P')
		return (player_texture(vars));
	else if (element == 'C')
		return (vars.img.collect);
	else if (element == 'E' && vars.game.exit_unlocked == false)
		return (exit_texture(vars));
	else if (element == 'E' && vars.game.exit_unlocked == true)
		return (vars.img.exit_unlocked_fire1);
	else if (element == 'e')
		return (vars.img.enemy_front_grass);
	else if (element == 'w')
		return (vars.img.enemy_back_grass);
	else if (element == 'd')
		return (vars.img.enemy_right_grass);
	else if (element == 'a')
		return (vars.img.enemy_left_grass);
	else
		return (vars.img.grass);
}

// Fill the window with the corresponding images according to the map
void	fill_window(t_vars *vars)
{
	int	x;
	int	y;
	int	img_x;
	int	img_y;
	int	img;

	x = 0;
	img = 0;
	while (x < vars->map.height)
	{
		y = 0;
		while (y < vars->map.width)
		{
			img_x = y * vars->img.width;
			img_y = x * vars->img.height;
			img = mlx_put_image_to_window(vars->mlx.mlx, vars->mlx.wind.wind,
					find_texture(vars->map.array[x][y], *vars), img_x, img_y);
			security_img(vars, img);
			y++;
		}
		x++;
	}
}
