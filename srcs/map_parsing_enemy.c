/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing_enemy.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlay <tlay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 16:19:02 by tlay              #+#    #+#             */
/*   Updated: 2024/04/18 19:19:22 by tlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	enemy_to_wall(t_vars *vars)
{
	int	x;
	int	y;

	x = find_x(&vars->map, 'e');
	y = find_y(&vars->map, 'e');
	vars->map.copy_map[x][y] = '1';
}

bool	place_for_enemy(t_map *map)
{
	if (find_x(map, '0') == -1 || find_y(map, '0') == -1)
		return (print_error("No place for enemy."), false);
	return (true);
}

bool	valid_way_enemy(t_vars *vars)
{
	copy_map(&vars->map);
	enemy_to_wall(vars);
	ft_flood_fill(vars->map, &vars->counter, vars->map.player.position_x,
		vars->map.player.position_y);
	free_tab(vars->map.copy_map);
	if ((vars->map.collect != vars->counter.collect)
		|| (vars->map.exit != vars->counter.exit))
	{
		print_error("Enemy blocks you : please relauch game or change map.");
		return (false);
	}
	return (true);
}

bool	parsing_enemy(t_vars *vars)
{
	if (valid_way_enemy(vars) == false)
		return (false);
	return (true);
}
