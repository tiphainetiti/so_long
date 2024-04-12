/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlay <tlay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 13:43:47 by tlay              #+#    #+#             */
/*   Updated: 2024/04/12 18:08:20 by tlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_get_x(t_map *map)
{
	int	i;

	i = 0;
	while (map->array[0][i] == '1')
		i++;
	return (i);
}

int	ft_get_y(t_map *map)
{
	int	i;

	i = 0;
	while (map->array[i])
		i++;
	return (i);
}

int	ft_find_x(t_map *map, char element)
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

int	ft_find_y(t_map *map, char element)
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

void	ft_free_tab(char **tab)
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
