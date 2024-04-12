/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlay <tlay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 16:13:01 by tlay              #+#    #+#             */
/*   Updated: 2024/04/12 18:15:48 by tlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	*ft_free_strjoin(char *all_av, char *new_av)
{
	char	*tmp;

	tmp = ft_strjoin(all_av, new_av);
	free(all_av);
	return (tmp);
}

void	ft_empty_map(t_vars *vars)
{
	int	i;

	i = 0;
	if (!vars->map.map_line)
	{
		ft_print_error("Empty map.");
		ft_error_map(vars);
	}
	while (vars->map.map_line[i])
	{
		if (ft_isalnum(ft_atoi(&vars->map.map_line[i])) == 1)
			return ;
		i++;
	}
}

void	ft_empty_line(t_vars *vars)
{
	int	i;

	i = 0;
	while (vars->map.map_line[i] && vars->map.map_line[i] != '\n')
		i++;
	while (vars->map.map_line[i])
	{
		if ((vars->map.map_line[i] == '\n' && (vars->map.map_line[i + 1] == '\n'
					|| vars->map.map_line[i + 1] == '\0'))
			|| vars->map.map_line[0] == '\n')
		{
			ft_print_error("Empty line in map.");
			ft_error_map(vars);
		}
		i++;
	}
	return ;
}

// Read and store the map.ber file in a string
char	**ft_get_map(t_vars *vars)
{
	char	*next;
	char	**array;

	vars->map.map_line = get_next_line(vars->fd);
	while (1)
	{
		next = get_next_line(vars->fd);
		if (!next)
			break ;
		vars->map.map_line = ft_free_strjoin(vars->map.map_line, next);
		free(next);
	}
	ft_empty_map(vars);
	ft_empty_line(vars);
	array = ft_split(vars->map.map_line, '\n');
	free(vars->map.map_line);
	return (array);
}

void	ft_map(t_vars *vars)
{
	ft_vars_init(vars);
	vars->map.array = ft_get_map(vars);
	vars->map.height = ft_get_y(&vars->map);
	vars->map.width = ft_get_x(&vars->map);
	if (ft_map_parsing(&vars->map, &vars->counter) == true)
	{
		init_enemy_position(vars);
		write(1, "Let's play !!\n", 14);
	}
	else
	{
		ft_free_tab(vars->map.array);
		vars->fd = close(vars->fd);
		exit(EXIT_FAILURE);
	}
}
