/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjamil <mjamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 11:43:39 by ral-faya          #+#    #+#             */
/*   Updated: 2024/08/20 14:42:07 by mjamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update_image(t_var *var, int img_index)
{
	char	*images[2];

	images[0] = "./img/danc1.xpm";
	images[1] = "./img/danc2.xpm";
	if (var->img.img_ptr)
	{
		mlx_destroy_image(var->mlx, var->img.img_ptr);
	}
	var->img.img_ptr = mlx_xpm_file_to_image(var->mlx, images[img_index],
			&var->img.size.width, &var->img.size.height);
	if (!var->img.img_ptr)
	{
		error2("Failed to load image");
	}
}

int	check_player_movement(t_var *var)
{
	time_t			current_time;
	static int		img_index = 0;
	static time_t	last_img_switch_time = 0;
	double			switch_interval;
	t_position		pos;

	current_time = time(NULL);
	switch_interval = 0.01;
	if (difftime(current_time, var->last_move_time) >= 3.0)
	{
		if (difftime(current_time, last_img_switch_time) >= switch_interval)
		{
			update_image(var, img_index);
			pos.height = var->img.pos.width * SPRITE_W;
			pos.width = var->img.pos.height * SPRITE_H;
			mlx_put_image_to_window(var->mlx, var->win, var->img.img_ptr,
				pos.height, pos.width);
			img_index = (img_index + 1) % 2;
			last_img_switch_time = current_time;
		}
	}
	return (0);
}

int	ft_expose(t_var *var)
{
	print_map(*var);
	print_steps(var);
	return (0);
}

void	part_of_main(t_var var)
{
	get_position(&var);
	count_collec(&var);
	print_map(var);
	mlx_hook(var.win, X_EVENT_KEY_PRESS, 1L << 0, key_press, &var);
	mlx_hook(var.win, X_EVENT_KEY_EXIT, 1L << 0, mlx_close, &var);
	mlx_loop_hook(var.mlx, check_player_movement, &var);
	mlx_loop(var.mlx);
}

int	main(int argc, char **argv)
{
	t_var	var;

	init(&var);
	var.last_move_time = time(NULL);
	check_args(argc, argv);
	get_map(&var, argv);
	check_map(var);
	var.mlx = mlx_init();
	if (var.mlx == NULL)
		error2("Failed to initialize MiniLibX");
	var.win = mlx_new_window(var.mlx, var.map.size.width
			* SPRITE_W, var.map.size.height * SPRITE_H, "So long");
	if (var.win == NULL)
	{
		free_map(&var);
		error2("Failed to create window");
	}
	part_of_main(var);
	free_map(&var);
	return (0);
}
