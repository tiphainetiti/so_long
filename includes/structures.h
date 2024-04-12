/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlay <tlay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 13:12:34 by tlay              #+#    #+#             */
/*   Updated: 2024/04/10 17:01:04 by tlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H
# define IMG_PATH "img/"
# include <stdbool.h>

typedef struct s_player
{
	int			i;
	int			position_x;
	int			position_y;
}				t_player;

typedef struct s_enemy
{
	int			position_x;
	int			position_y;
	int			diff_x;
	int			diff_y;
	int			up;
	int			down;
	int			left;
	int			right;
}				t_enemy;

typedef struct s_map
{
	char		*map_line;
	char		**array;
	char		**copy_map;
	int			exit;
	t_player	player;
	t_enemy		enemy;
	int			wall;
	int			collect;
	int			width;
	int			height;
}				t_map;

typedef struct s_counter
{
	int			exit;
	int			collect;
}				t_counter;

typedef struct s_wind
{
	void		*wind;
	int			width;
	int			height;
}				t_wind;

typedef struct s_mlx
{
	void		*mlx;
	t_wind		wind;
}				t_mlx;

typedef struct s_img
{
	void		*grass;
	void		*wall;
	void		*collect;
	void		*exit_locked_fire1;
	void		*exit_locked_fire2;
	void		*exit_unlocked_fire1;
	void		*exit_unlocked_fire2;
	void		*player_front_grass;
	void		*player_back_grass;
	void		*player_left_grass;
	void		*player_right_grass;
	void		*player_front_exit_fire1;
	void		*player_back_exit_fire1;
	void		*player_left_exit_fire1;
	void		*player_right_exit_fire1;
	void		*player_front_exit_fire2;
	void		*player_back_exit_fire2;
	void		*player_left_exit_fire2;
	void		*player_right_exit_fire2;
	void		*enemy_front_grass;
	int			width;
	int			height;
}				t_img;

typedef struct s_game
{
	bool		exit_unlocked;
	bool		front;
	bool		back;
	bool		left;
	bool		right;
	bool		win;
	int			keycode;
}				t_game;

typedef struct s_vars
{
	int			fd;
	int			movements;
	t_game		game;
	t_map		map;
	t_counter	counter;
	t_mlx		mlx;
	t_img		img;
}				t_vars;

enum
{
	W = 119,
	A = 97,
	S = 115,
	D = 100,
	UP = 65362,
	LEFT = 65361,
	DOWN = 65364,
	RIGHT = 65363,
	ESC = 65307
};

enum
{
	DestroyNotify = 17,
	KeyPressMask = (1L << 0),
};

#endif