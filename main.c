/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlay <tlay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 14:30:23 by tlay              #+#    #+#             */
/*   Updated: 2024/04/10 13:55:39 by tlay             ###   ########.fr       */
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

void	print_map_copy(t_map map)
{
	int	i;

	i = 0;
	while (map.copy_map[i])
	{
		printf("COPY row [%d] : %s\n", i, map.copy_map[i]);
		i++;
	}
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
		mlx_loop_hook(vars.mlx.mlx, animations, &vars);
		mlx_key_hook(vars.mlx.wind.wind, key_handler, &vars);
		mlx_hook(vars.mlx.wind.wind, DestroyNotify, KeyPressMask, close_window,
			&vars);
		vars.fd = close(vars.fd);
		mlx_loop(vars.mlx.mlx);
	}
	return (0);
}

// Animation murs qui marche pas trop
// int	animations(t_vars *vars)
//{
//	int	x;
//	int	y;
//	int	img_x;
//	int	img_y;

//	print_mov(vars);
//	x = 0;
//	while (x < vars->map.height)
//	{
//		y = 0;
//		while (y < vars->map.width)
//		{
//			if (vars->map.array[x][y] == '1')
//			{
//				img_x = y * vars->img.width;
//				img_y = x * vars->img.height;
//				mlx_put_image_to_window(vars->mlx.mlx, vars->mlx.wind.wind,
//					vars->img.wall, img_x, img_y);
//				mlx_do_sync(vars->mlx.mlx);
//				usleep(5000);
//				mlx_put_image_to_window(vars->mlx.mlx, vars->mlx.wind.wind,
//					vars->img.wall2, img_x, img_y);
//				mlx_do_sync(vars->mlx.mlx);
//				usleep(5000);
//				mlx_put_image_to_window(vars->mlx.mlx, vars->mlx.wind.wind,
//					vars->img.wall, img_x, img_y);
//				mlx_do_sync(vars->mlx.mlx);
//				usleep(5000);
//				mlx_put_image_to_window(vars->mlx.mlx, vars->mlx.wind.wind,
//					vars->img.wall3, img_x, img_y);
//				mlx_do_sync(vars->mlx.mlx);
//				usleep(5000);
//				mlx_put_image_to_window(vars->mlx.mlx, vars->mlx.wind.wind,
//					vars->img.wall, img_x, img_y);
//				mlx_do_sync(vars->mlx.mlx);
//			}
//			y++;
//		}
//		x++;
//	}
//	return (0);
//}