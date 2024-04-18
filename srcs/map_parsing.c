/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlay <tlay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 19:16:50 by tlay              #+#    #+#             */
/*   Updated: 2024/04/18 18:15:10 by tlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

bool	is_rectangular(t_map *map)
{
	int		i;
	size_t	len;

	i = 0;
	if (!map)
		return (false);
	len = ft_strlen(map->array[0]);
	while (map->array[i])
	{
		if (len != ft_strlen(map->array[i]))
			return (print_error("Map is not rectangular."), false);
		i++;
	}
	return (true);
}

bool	is_playable(t_map *map)
{
	if (only_element(map) == false || count_elements(map) == false
		|| is_closed(map) == false)
		return (false);
	return (true);
}

void	ft_flood_fill(t_map map, t_counter *counter, int x, int y)
{
	if (map.copy_map[x][y] == 'E')
		counter->exit++;
	if (map.copy_map[x][y] == 'C')
		counter->collect++;
	if (map.copy_map[x][y] != '1')
	{
		map.copy_map[x][y] = '1';
		ft_flood_fill(map, counter, x - 1, y);
		ft_flood_fill(map, counter, x + 1, y);
		ft_flood_fill(map, counter, x, y - 1);
		ft_flood_fill(map, counter, x, y + 1);
	}
}

bool	valid_way(t_map *map, t_counter *counter)
{
	map->player.position_x = find_x(map, 'P');
	map->player.position_y = find_y(map, 'P');
	if (map->player.position_x < 0 || map->player.position_y < 0)
		print_error("Player not found...");
	copy_map(map);
	ft_flood_fill(*map, counter, map->player.position_x,
		map->player.position_y);
	free_tab(map->copy_map);
	if ((map->collect != counter->collect) || (map->exit != counter->exit))
		return (print_error("There is no valid way to the exit."), false);
	reset_counter(counter);
	return (true);
}

bool	map_parsing(t_map *map, t_counter *counter)
{
	if (is_big_enough(map) == false || is_rectangular(map) == false
		|| is_playable(map) == false || valid_way(map, counter) == false
		|| place_for_enemy(map) == false)
		return (false);
	return (true);
}
