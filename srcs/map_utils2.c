/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlay <tlay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 13:55:28 by tlay              #+#    #+#             */
/*   Updated: 2024/04/18 18:43:03 by tlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// Check if the map contains only valid elements
bool	only_element(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map->array[i])
	{
		while (map->array[i][j])
		{
			if (map->array[i][j] != '1' && map->array[i][j] != '0'
				&& map->array[i][j] != 'C' && map->array[i][j] != 'E'
				&& map->array[i][j] != 'P')
				return (print_error("Elements not valid (1, 0, C, E, P)."),
					false);
			j++;
		}
		i++;
		j = 0;
	}
	return (true);
}

// Count how many C's, E's and P's are in the map
// and check if the number is right
bool	count_elements(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map->array[i])
	{
		while (map->array[i][j])
		{
			if (map->array[i][j] == 'C')
				map->collect++;
			if (map->array[i][j] == 'E')
				map->exit++;
			if (map->array[i][j] == 'P')
				map->player.i++;
			j++;
		}
		i++;
		j = 0;
	}
	if (map->exit != 1 || map->player.i != 1 || map->collect < 1)
		return (print_error("Exit, player and/or items not valid."), false);
	return (true);
}

// Check if the map is enclosed by walls
bool	is_closed(t_map *map)
{
	int	i;
	int	j;
	int	eol;
	int	ground;

	i = 0;
	j = 0;
	eol = ft_strlen(map->array[i]);
	ground = get_y(map);
	while (map->array[i][j])
	{
		if (map->array[0][j] != '1' || map->array[ground - 1][j] != '1')
			return (print_error("Map not closed by walls."), false);
		j++;
	}
	while (map->array[i])
	{
		if (map->array[i][0] != '1' || map->array[i][eol - 1] != '1')
			return (print_error("Map not closed by walls."), false);
		i++;
	}
	return (true);
}

// Check if the map is large enough: minimum 3x5
bool	is_big_enough(t_map *map)
{
	int	x;
	int	y;

	x = get_x(map);
	y = get_y(map);
	if ((x < 3 && y < 5) || (x < 5 && y < 3))
		return (print_error("Map too small."), false);
	return (true);
}

// Creating a copy of the map
void	copy_map(t_map *map)
{
	int	i;

	i = 0;
	map->copy_map = malloc(sizeof(char *) * (map->height + 1));
	while (map->array[i])
	{
		map->copy_map[i] = ft_strdup(map->array[i]);
		i++;
	}
	map->copy_map[i] = NULL;
}
