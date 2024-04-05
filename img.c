/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlay <tlay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 17:35:45 by tlay              #+#    #+#             */
/*   Updated: 2024/04/05 17:42:49 by tlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Initialiser les images
void	ft_img_init(t_vars *vars)
{
	vars->img.collect = NULL;
	vars->img.exit_end_game = NULL;
	vars->img.exit_locked = NULL;
	vars->img.exit_unlocked = NULL;
	vars->img.grass = NULL;
	vars->img.player_back_exit = NULL;
	vars->img.player_back_grass = NULL;
	vars->img.player_front_exit = NULL;
	vars->img.player_front_grass = NULL;
	vars->img.player_left_exit = NULL;
	vars->img.player_left_grass = NULL;
	vars->img.player_right_exit = NULL;
	vars->img.player_right_grass = NULL;
	vars->img.wall = NULL;
	vars->img.height = 0;
	vars->img.width = 0;
}

// Charger les images de enemy
void	ft_img_enemy(t_vars *vars)
{
	vars->img.enemy_front_grass = mlx_xpm_file_to_image(vars->mlx.mlx,
			IMG_PATH "enemy_front_grass2.xpm", &vars->img.width,
			&vars->img.height);
}

// Charger les images de player
void	ft_img_player(t_vars *vars)
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
	vars->img.player_front_exit = mlx_xpm_file_to_image(vars->mlx.mlx,
			IMG_PATH "player_front_exit.xpm", &vars->img.width,
			&vars->img.height);
	vars->img.player_back_exit = mlx_xpm_file_to_image(vars->mlx.mlx,
			IMG_PATH "player_back_exit.xpm", &vars->img.width,
			&vars->img.height);
	vars->img.player_left_exit = mlx_xpm_file_to_image(vars->mlx.mlx,
			IMG_PATH "player_left_exit.xpm", &vars->img.width,
			&vars->img.height);
	vars->img.player_right_exit = mlx_xpm_file_to_image(vars->mlx.mlx,
			IMG_PATH "player_right_exit.xpm", &vars->img.width,
			&vars->img.height);
}

// Charger les images
void	ft_img(t_vars *vars)
{
	ft_img_init(vars);
	vars->img.wall = mlx_xpm_file_to_image(vars->mlx.mlx, IMG_PATH "wall.xpm",
			&vars->img.width, &vars->img.height);
	vars->img.grass = mlx_xpm_file_to_image(vars->mlx.mlx, IMG_PATH "grass.xpm",
			&vars->img.width, &vars->img.height);
	vars->img.collect = mlx_xpm_file_to_image(vars->mlx.mlx,
			IMG_PATH "collect.xpm", &vars->img.width, &vars->img.height);
	vars->img.exit_locked = mlx_xpm_file_to_image(vars->mlx.mlx,
			IMG_PATH "exit_locked.xpm", &vars->img.width, &vars->img.height);
	vars->img.exit_unlocked = mlx_xpm_file_to_image(vars->mlx.mlx,
			IMG_PATH "exit_unlocked.xpm", &vars->img.width, &vars->img.height);
	vars->img.exit_end_game = mlx_xpm_file_to_image(vars->mlx.mlx,
			IMG_PATH "exit_end_game.xpm", &vars->img.width, &vars->img.height);
	ft_img_player(vars);
	ft_img_enemy(vars);
	ft_error_img(vars);
}

// Trouver l'image de player adpatee
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

// Trouver l'image d'exit adaptee
void	*exit_texture(t_vars vars)
{
	int	x;
	int	y;

	x = vars.map.player.position_x;
	y = vars.map.player.position_y;
	if (x == ft_find_x(&vars.map, 'E') && y == ft_find_y(&vars.map, 'E'))
	{
		if (vars.game.keycode == W || vars.game.keycode == UP)
			return (vars.img.player_back_exit);
		else if (vars.game.keycode == A || vars.game.keycode == LEFT)
			return (vars.img.player_left_exit);
		else if (vars.game.keycode == S || vars.game.keycode == DOWN)
			return (vars.img.player_front_exit);
		else if (vars.game.keycode == D || vars.game.keycode == RIGHT)
			return (vars.img.player_right_exit);
		else
			return (vars.img.exit_locked);
	}
	else
		return (vars.img.exit_locked);
}

// Trouver la bonne texture selon la map
void	*ft_find_texture(char element, t_vars vars)
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
		return (vars.img.exit_unlocked);
	else if (element == 'e')
		return (vars.img.enemy_front_grass);
	else
		return (vars.img.grass);
}

// Remplir la fenetre des images correspondantes selon la map
void	ft_fill_window(t_vars *vars)
{
	int	x;
	int	y;
	int	img_x;
	int	img_y;
	int	img;

	x = 0;
	img = 0;
	print_map(vars);
	while (x < vars->map.height)
	{
		y = 0;
		while (y < vars->map.width)
		{
			img_x = y * vars->img.width;
			img_y = x * vars->img.height;
			img = mlx_put_image_to_window(vars->mlx.mlx, vars->mlx.wind.wind,
					ft_find_texture(vars->map.array[x][y], *vars), img_x,
					img_y);
			ft_security_img(vars, img);
			y++;
		}
		x++;
	}
}
