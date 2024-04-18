/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_mov_count.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlay <tlay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 16:30:36 by tlay              #+#    #+#             */
/*   Updated: 2024/04/12 18:07:34 by tlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	print_mov(t_vars *vars)
{
	char	*counter_str;

	counter_str = ft_itoa(vars->movements);
	mlx_string_put(vars->mlx.mlx, vars->mlx.wind.wind, 36, 27, 0xC82B8A,
		"MOVEMENTS : ");
	mlx_string_put(vars->mlx.mlx, vars->mlx.wind.wind, 37, 27, 0x9D226D,
		"MOVEMENTS :");
	mlx_string_put(vars->mlx.mlx, vars->mlx.wind.wind, 106, 27, 0xC82B8A,
		counter_str);
	mlx_string_put(vars->mlx.mlx, vars->mlx.wind.wind, 107, 27, 0x9D226D,
		counter_str);
	free(counter_str);
	return (0);
}
