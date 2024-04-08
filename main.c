/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlay <tlay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 14:30:23 by tlay              #+#    #+#             */
/*   Updated: 2024/04/08 18:48:30 by tlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_map(t_vars *vars)
{
	int	i;

	i = 0;
	if (!vars->map.array[0][0])
	{
		printf("OK FREE\n");
		return ;
	}
	while (vars->map.array[i])
	{
		printf("row [%d] : %s\n", i, vars->map.array[i]);
		i++;
	}
}

int	animations(void)
{
	return (0);
}

int	main(int ac, char **av)
{
	t_vars	vars;

	if (ac == 2)
	{
		vars.fd = open(av[1], O_RDONLY);
		if (vars.fd < 0)
			return (ft_print_error("Missing map."), 0);
		ft_map(&vars);
		vars.mlx.mlx = mlx_init();
		ft_img(&vars);
		ft_start_game(&vars);
		mlx_key_hook(vars.mlx.wind.wind, key_handler, &vars);
		mlx_hook(vars.mlx.wind.wind, DestroyNotify, KeyPressMask, close_window,
			&vars);
		mlx_loop_hook(vars.mlx.mlx, print_mov, &vars);
		mlx_loop_hook(vars.mlx.mlx, animations, &vars);
		vars.fd = close(vars.fd);
		mlx_loop(vars.mlx.mlx);
	}
	return (0);
}
