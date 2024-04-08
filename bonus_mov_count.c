/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_mov_count.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlay <tlay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 16:30:36 by tlay              #+#    #+#             */
/*   Updated: 2024/04/08 18:15:20 by tlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	print_mov(t_vars *vars)
{
	char	*counter_str;

	counter_str = ft_itoa(vars->movements);
	mlx_string_put(vars->mlx.mlx, vars->mlx.wind.wind, 20, 27, 0xC82B8A,
		"MOVEMENTS : ");
	mlx_string_put(vars->mlx.mlx, vars->mlx.wind.wind, 21, 27, 0x9D226D,
		"MOVEMENTS :");
	mlx_string_put(vars->mlx.mlx, vars->mlx.wind.wind, 90, 27, 0xC82B8A,
		counter_str);
	mlx_string_put(vars->mlx.mlx, vars->mlx.wind.wind, 91, 27, 0x9D226D,
		counter_str);
	free(counter_str);
	return (0);
}
