/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlay <tlay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 14:30:23 by tlay              #+#    #+#             */
/*   Updated: 2024/04/18 16:33:33 by tlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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

void	print_map_copy(t_vars *vars)
{
	int	i;

	i = 0;
	if (!vars->map.copy_map[0][0])
	{
		printf("OK FREE\n");
		return ;
	}
	while (vars->map.copy_map[i])
	{
		printf("copy [%d] : %s\n", i, vars->map.copy_map[i]);
		i++;
	}
}

bool	av_ber_extension(char *av)
{
	size_t	len;
	int		result;

	len = ft_strlen(av);
	result = ft_strncmp(av + len - 4, ".ber", 4);
	if (len < 4 || result != 0)
		return (write(2, "Map file is not good extension.\n", 32), false);
	return (true);
}

int	main(int ac, char **av)
{
	t_vars	vars;

	if (ac == 2 && av_ber_extension(av[1]) == true)
	{
		vars.fd = open(av[1], O_RDONLY);
		if (vars.fd < 0)
			return (print_error("Missing map."), 0);
		ft_map(&vars);
		vars.mlx.mlx = mlx_init();
		ft_img(&vars);
		start_game(&vars);
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