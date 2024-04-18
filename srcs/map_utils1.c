/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlay <tlay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 13:43:47 by tlay              #+#    #+#             */
/*   Updated: 2024/04/18 16:25:47 by tlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	get_x(t_map *map)
{
	int	i;

	i = 0;
	while (map->array[0][i] == '1')
		i++;
	return (i);
}

int	get_y(t_map *map)
{
	int	i;

	i = 0;
	while (map->array[i])
		i++;
	return (i);
}

int	find_x(t_map *map, char element)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map->array[i])
	{
		while (map->array[i][j])
		{
			if (map->array[i][j] == element)
				return (i);
			j++;
		}
		j = 0;
		i++;
	}
	return (-1);
}

int	find_y(t_map *map, char element)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map->array[i])
	{
		while (map->array[i][j])
		{
			if (map->array[i][j] == element)
				return (j);
			j++;
		}
		j = 0;
		i++;
	}
	return (-1);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
