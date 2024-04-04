/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlay <tlay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 13:55:28 by tlay              #+#    #+#             */
/*   Updated: 2024/03/26 16:15:01 by tlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Check si la map ne contient que des elements valides
bool	ft_only_element(t_map *map)
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
				return (ft_print_error("Elements not valid (1, 0, C, E, P)."),
					false);
			j++;
		}
		i++;
		j = 0;
	}
	return (true);
}

// Compte combien il y a de C, E et P dans la map
// et check s'il y a le bon nombre
bool	ft_count_elements(t_map *map)
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
		return (ft_print_error("Exit, player and/or items not valid."), false);
	return (true);
}

// Check si la map est fermee par des murs
bool	ft_is_closed(t_map *map)
{
	int	i;
	int	j;
	int	eol;
	int	ground;

	i = 0;
	j = 0;
	eol = ft_strlen(map->array[i]);
	ground = ft_get_y(map);
	while (map->array[i])
	{
		if (map->array[0][j] != '1' || map->array[ground - 1][j] != '1')
			return (ft_print_error("Map not closed by walls."), false);
		j++;
		if (map->array[i][0] != '1' || map->array[i][eol - 1] != '1')
			return (ft_print_error("Map not closed by walls."), false);
		i++;
	}
	return (true);
}

// Check si la map est assez grande : minimum 3x5
bool	ft_is_big_enough(t_map *map)
{
	int	x;
	int	y;

	x = ft_get_x(map);
	y = ft_get_y(map);
	if ((x < 3 && y < 5) || (x < 5 && y < 3))
		return (ft_print_error("Map too small."), false);
	return (true);
}

// Creer une copie de la map
void	ft_copy_map(t_map *map)
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
