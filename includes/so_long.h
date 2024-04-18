/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlay <tlay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 14:31:06 by tlay              #+#    #+#             */
/*   Updated: 2024/04/18 18:38:32 by tlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/get_next_line.h"
# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include "structures.h"
# include <stdbool.h>
# include <stdio.h>
# include <time.h>
# include <unistd.h>

void	print_map(t_vars *vars);
void	print_map_copy(t_vars *vars);

// ft_error.c
void	print_error(char *str);
void	error_map_line(t_vars *vars);
void	error_map(t_vars *vars);
void	error_img(t_vars *vars);
void	security_img(t_vars *vars, int img);

// map_init.c
char	*ft_free_strjoin(char *all_av, char *new_av);
void	empty_map(t_vars *vars);
void	empty_line(t_vars *vars);
char	**get_map(t_vars *vars);
void	ft_map(t_vars *vars);

// map_parsing.c
bool	is_rectangular(t_map *map);
bool	is_playable(t_map *map);
void	ft_flood_fill(t_map map, t_counter *counter, int x, int y);
bool	valid_way(t_map *map, t_counter *counter);
bool	map_parsing(t_map *map, t_counter *counter);

// map_utils1.c
int		get_x(t_map *map);
int		get_y(t_map *map);
int		find_x(t_map *map, char element);
int		find_y(t_map *map, char element);
void	free_tab(char **tab);

// map_utils2.c
bool	only_element(t_map *map);
bool	count_elements(t_map *map);
bool	is_closed(t_map *map);
bool	is_big_enough(t_map *map);
void	copy_map(t_map *map);

// img.c
void	*player_texture(t_vars vars);
void	*exit_texture(t_vars vars);
void	*find_texture(char element, t_vars vars);
void	fill_window(t_vars *vars);

// img_load.c
void	img_enemy(t_vars *vars);
void	img_player(t_vars *vars);
void	img_exit_fire(t_vars *vars);
void	ft_img(t_vars *vars);

// game.c
void	start_game(t_vars *vars);
bool	end_game(t_vars *vars, int new_x, int new_y);
void	run_game(t_vars *vars, int new_pos_x, int new_pos_y);
int		key_handler(int keycode, t_vars *vars);

// game_utils.c
void	destroy_img_enemy(t_vars *vars);
void	destroy_img_player(t_vars *vars);
void	destroy_img(t_vars *vars);
void	close_window(t_vars *vars);
void	update_player_position(t_vars *vars, int new_pos_x, int new_pos_y);

// struct_init.c
void	ft_vars_init(t_vars *vars);
void	ft_img_init(t_vars *vars);
void	reset_counter(t_counter *counter);

// BONUS :

// map_parsing_enemy.c
void	enemy_to_wall(t_vars *vars);
bool	place_for_enemy(t_map *map);
bool	parsing_enemy(t_vars *vars);

// bous_mov_count.c
int		print_mov(t_vars *vars);

// bonus_ennemy.c
void	init_enemy_position(t_vars *vars);
void	update_enemy_position(t_vars *vars, int new_pos_x, int new_pos_y);
void	enemy_run_game(t_vars *vars, int new_pos_x, int new_pos_y, int i);
int		enemy_mov(int keycode, t_vars *vars);

// animations.c
void	animation_player_1(t_vars *vars, int x, int y);
void	animation_player_2(t_vars *vars, int x, int y);
void	animation_exit_locked(t_vars *vars, int x, int y);
void	animation_exit_unlocked(t_vars *vars, int x, int y);
int		animations(t_vars *vars);

#endif