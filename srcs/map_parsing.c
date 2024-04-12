/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlay <tlay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 19:16:50 by tlay              #+#    #+#             */
/*   Updated: 2024/04/12 18:08:16 by tlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

bool	ft_is_rectangular(t_map *map)
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
			return (ft_print_error("Map is not rectangular."), false);
		i++;
	}
	return (true);
}

bool	ft_is_playable(t_map *map)
{
	if (ft_only_element(map) == false || ft_count_elements(map) == false
		|| ft_is_closed(map) == false || ft_is_big_enough(map) == false)
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

bool	ft_valid_way(t_map *map, t_counter *counter)
{
	map->player.position_x = ft_find_x(map, 'P');
	map->player.position_y = ft_find_y(map, 'P');
	if (map->player.position_x < 0 || map->player.position_y < 0)
		ft_print_error("Player not found...");
	ft_copy_map(map);
	ft_flood_fill(*map, counter, map->player.position_x,
		map->player.position_y);
	ft_free_tab(map->copy_map);
	if ((map->collect != counter->collect) || (map->exit != counter->exit))
		return (ft_print_error("There is no valid way to the exit."), false);
	return (true);
}

bool	ft_map_parsing(t_map *map, t_counter *counter)
{
	if ((ft_is_rectangular(map) == false) || (ft_is_playable(map) == false)
		|| (ft_valid_way(map, counter) == false))
		return (false);
	return (true);
}
