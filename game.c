/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjamil <mjamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 22:07:41 by mjamil            #+#    #+#             */
/*   Updated: 2024/08/18 11:41:34 by mjamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_position(t_var *var)
{
	int		row;
	int		col;

	row = 0;
	while (row < var->map.size.height)
	{
		col = 0;
		while (col <= var->map.size.width)
		{
			if (var->map.data[row][col] == 'P')
			{
				var->img.pos.width = col;
				var->img.pos.height = row;
			}
			col++;
		}
		row++;
	}
	return (0);
}

int	count_collec(t_var *var)
{
	int		row;
	int		col;

	row = 0;
	var->game.count_collec = 0;
	while (row < var->map.size.height)
	{
		col = 0;
		while (col <= var->map.size.width)
		{
			if (var->map.data[row][col] == 'C')
				var->game.count_collec++;
			col++;
		}
		row++;
	}
	return (var->game.count_collec);
}

int	check_collect(t_var *var)
{
	if (count_collec(var) == 0)
	{
		free_exit(var, "CONGRATULATIONS 🎉🎉🎉\n");
	}
	else
		printf("Please, collect all Items!!! :))\n");
	return (0);
}

int	print_steps(t_var *var)
{
	char	*str;

	str = ft_itoa(var->game.count_steps);
	mlx_string_put(var->mlx, var->win, (var->img.pos.width * SPRITE_W) + 5,
		(var->img.pos.height * SPRITE_H) + 10, 0x833000, str);
	free(str);
	return (0);
}
