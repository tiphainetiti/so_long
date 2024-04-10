/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlay <tlay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 14:31:06 by tlay              #+#    #+#             */
/*   Updated: 2024/04/10 17:45:15 by tlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "ft_printf/ft_printf.h"
# include "libft/get_next_line.h"
# include "libft/libft.h"
# include "mlx/mlx.h"
# include "structures.h"
# include <stdbool.h>
# include <stdio.h>
# include <time.h>
# include <unistd.h>

void	print_map(t_vars *vars);
void	print_map_copy(t_map map);

// ft_error.c
void	ft_print_error(char *str);
void	ft_error_map(t_vars *vars);
void	ft_error_img(t_vars *vars);
void	ft_security_img(t_vars *vars, int img);

// map_init.c
char	*ft_free_strjoin(char *all_av, char *new_av);
void	ft_empty_map(t_vars *vars);
void	ft_empty_line(t_vars *vars);
char	**ft_get_map(t_vars *vars);
void	ft_map(t_vars *vars);

// map_parsing.c
bool	ft_is_rectangular(t_map *map);
bool	ft_is_playable(t_map *map);
void	ft_flood_fill(t_map map, t_counter *counter, int x, int y);
bool	ft_valid_way(t_map *map, t_counter *counter);
bool	ft_map_parsing(t_map *map, t_counter *counter);

// map_utils1.c
int		ft_get_x(t_map *map);
int		ft_get_y(t_map *map);
int		ft_find_x(t_map *map, char element);
int		ft_find_y(t_map *map, char element);
void	ft_free_tab(char **tab);

// map_utils2.c
bool	ft_only_element(t_map *map);
bool	ft_count_elements(t_map *map);
bool	ft_is_closed(t_map *map);
bool	ft_is_big_enough(t_map *map);
void	ft_copy_map(t_map *map);

// img.c
void	*player_texture(t_vars vars);
void	*exit_texture(t_vars vars);
void	*ft_find_texture(char element, t_vars vars);
void	ft_fill_window(t_vars *vars);

// img_load.c
void	ft_img_enemy(t_vars *vars);
void	ft_img_player(t_vars *vars);
void	ft_img_exit_fire(t_vars *vars);
void	ft_img(t_vars *vars);

// game.c
void	ft_start_game(t_vars *vars);
void	run_game(t_vars *vars, int new_pos_x, int new_pos_y);
int		key_handler(int keycode, t_vars *vars);

// game_utils.c
void	destroy_img_enemy(t_vars *vars);
void	destroy_img_player(t_vars *vars);
void	destroy_img(t_vars *vars);
int		close_window(t_vars *vars);
void	update_player_position(t_vars *vars, int new_pos_x, int new_pos_y);

// struct_init.c
void	ft_vars_init(t_vars *vars);
void	ft_img_init(t_vars *vars);

// BONUS :
// bous_mov_count.c
int		print_mov(t_vars *vars);

// bonus_ennemy.c
void	init_enemy_position(t_vars *vars);
void	update_enemy_position(t_vars *vars, int new_pos_x, int new_pos_y);
void	enemy_run_game(t_vars *vars, int new_pos_x, int new_pos_y);
int		enemy_mov(int keycode, t_vars *vars);

// animations.c
void	animation_player_1(t_vars *vars, int x, int y);
void	animation_player_2(t_vars *vars, int x, int y);
void	animation_exit_locked(t_vars *vars, int x, int y);
void	animation_exit_unlocked(t_vars *vars, int x, int y);
int		animations(t_vars *vars);

#endif