/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlay <tlay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 16:13:01 by tlay              #+#    #+#             */
/*   Updated: 2024/04/04 10:46:45 by tlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Initialiser mes variabes
void	ft_vars_init(t_vars *vars)
{
	vars->game.keycode = 0;
	vars->game.exit_unlocked = false;
	vars->game.front = false;
	vars->game.back = false;
	vars->game.left = false;
	vars->game.right = false;
	vars->game.win = false;
	vars->movements = 0;
	vars->map.array = NULL;
	vars->map.exit = 0;
	vars->map.player.i = 0;
	vars->map.player.position_x = 0;
	vars->map.player.position_y = 0;
	vars->map.enemy.i = 0;
	vars->map.enemy.position_x = 0;
	vars->map.enemy.position_y = 0;
	vars->map.wall = 0;
	vars->map.collect = 0;
	vars->counter.collect = 0;
	vars->counter.exit = 0;
}

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

// Lis et stock dans une str le fichier map.ber
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
		write(1, "Let's play !!\n", 14);
	else
	{
		ft_free_tab(vars->map.array);
		vars->fd = close(vars->fd);
		exit(EXIT_FAILURE);
	}
}
