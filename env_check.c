/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjamil <mjamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 22:08:08 by mjamil            #+#    #+#             */
/*   Updated: 2024/08/20 14:42:18 by mjamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_surrounded_by_walls(t_var var)
{
	int	i;

	i = 0;
	while (i < var.map.size.width)
	{
		if (var.map.data[0][i] != '1' ||
		var.map.data[var.map.size.height - 1][i] != '1')
			error1(&var, "Invalid map: top or down wall not configured");
		i++;
	}
	i = 0;
	while (i < var.map.size.height)
	{
		if (var.map.data[i][0] != '1' ||
		var.map.data[i][var.map.size.width - 1] != '1')
			error1(&var, "Invalid map: lateral wall not configured");
		i++;
	}
	return (0);
}

int	is_rectangular(t_var var)
{
	int	i;

	i = 0;
	while (i < var.map.size.height)
	{
		if (ft_strlen1(var.map.data[i]) != var.map.size.width)
			error1(&var, "Invalid map: not a rectangle");
		i++;
	}
	return (0);
}

int	check_evironment(t_var var)
{
	is_surrounded_by_walls(var);
	is_rectangular(var);
	contains_1exit(var);
	contains_collectible(var);
	contains_onestarting(var);
	contains_valid_items(var);
	return (0);
}

int	init(t_var *var)
{
	var->mlx = NULL;
	var->win = NULL;
	var->game.count_collec = 0;
	var->game.count_steps = 0;
	var->map.data = NULL;
	var->map.size.height = 0;
	var->map.size.width = 0;
	var->img.img_ptr = NULL;
	var->img.spt_path = "./img/spiderman.xpm";
	var->img.size.width = 0;
	var->img.size.height = 0;
	var->img.pos.width = 0;
	var->img.pos.height = 0;
	var->img.data = NULL;
	var->img.size_line = 0;
	return (0);
}

int	check_args(int argc, char **argv)
{
	if (argc < 2)
		error2("Provide map name and extension as argument\n\
Ex: ./so_long maps/map.ber");
	if (argc > 2)
		error2("Too many arguments. Provide only map name and extension\n\
Ex: ./so_long maps/map.ber");
	if (ft_strstr(argv[1], ".ber") == NULL)
		error2("Invalid map extension. Use .ber");
	return (0);
}
