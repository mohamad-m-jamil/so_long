/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjamil <mjamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 22:07:06 by mjamil            #+#    #+#             */
/*   Updated: 2024/08/20 14:41:48 by mjamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"
# include <fcntl.h>
# include <stddef.h>
# include <stdlib.h>
# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include <time.h>

# define A_KEY					97
# define W_KEY					119
# define S_KEY					115
# define D_KEY					100
# define UP_KEY					65362
# define DOWN_KEY				65364
# define LEFT_KEY				65361
# define RIGHT_KEY				65363
# define ESC					65307
# define SPRITE_H				64
# define SPRITE_W				64
# define X_EVENT_KEY_PRESS		2
# define X_EVENT_KEY_EXIT		17

typedef struct l_position
{
	int	width;
	int	height;
}	t_position;

typedef struct l_map
{
	t_position	size;
	char		**data;
}	t_map;

typedef struct l_img
{
	void		*img_ptr;
	char		*spt_path;
	t_position	size;
	t_position	pos;
	int			size_line;
	void		*data;
}	t_imgg;

typedef struct k_game
{
	int			count_collec;
	int			count_steps;
}	t_game;

typedef struct s_var
{
	void		*mlx;
	void		*win;
	t_game		game;
	t_map		map;
	t_imgg		img;
	time_t		last_move_time;
}	t_var;

int			init(t_var *var);
int			check_args(int argc, char **argv);
int			ft_expose(t_var *var);
int			is_surrounded_by_walls(t_var var);
int			is_rectangular(t_var var);
int			contains_1exit(t_var var);
int			contains_collectible(t_var var);
int			contains_onestarting(t_var var);
int			contains_valid_items(t_var var);
t_position	find_startposition(char **data, t_position size);
void		handle_error(t_var *var, char type, int **visited);
void		check_pathandcollectibles(t_var var, int **visited);

int			has_valid_paths(t_var var);
int			check_evironment(t_var var);
int			check_map(t_var var);
int			count_lines(char *filename);
void		read_map(t_var *var, char *filename);
int			get_map(t_var *var, char **argv);
int			load_map(t_var var, int row, int col);
int			print_map(t_var var);
int			error1(t_var *var, char *msg);
int			error2(char *msg);
void		depth_search(char **data, t_position current,
				t_position size, int **visited);
void		errorss(t_var *var, char *msg, int **visited, t_position size);
int			get_position(t_var *var);
int			count_collec(t_var *var);
int			check_collect(t_var *var);
int			print_steps(t_var *var);
int			mleft(t_var *var);
int			mright(t_var *var);
int			mdown(t_var *var);
int			mup(t_var *var);
int			mouvs(int key, t_var *var);
int			mlx_close(t_var *var);
int			key_press(int key, t_var *var);
int			free_map(t_var *var);
int			free_maps(t_var *var);
int			free_exit(t_var *var, char *msg);
int			check_player_movement(t_var *var);
int			mouvs_if_s(int key, t_var *var);
int			mouvs_if_w(int key, t_var *var);
int			mouvs_if_d(int key, t_var *var);
int			key_press(int keycode, t_var *var);
void		free_visited(int **visited, t_position size);
void		cleanup(t_var *var);
void		part_of_main(t_var var);
void		update_image(t_var *var, int img_index);

#endif
