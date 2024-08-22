/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouve_p2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjamil <mjamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 11:59:54 by mjamil            #+#    #+#             */
/*   Updated: 2024/08/20 12:23:34 by mjamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	mouvs_if_d(int key, t_var *var)
{
	if ((key == D_KEY || key == RIGHT_KEY)
		&& (var->map.data[var->img.pos.height][var->img.pos.width + 1] == 'E'))
	{
		var->last_move_time = time(NULL);
		check_collect(var);
	}
	else if ((key == D_KEY || key == RIGHT_KEY)
		&& (var->map.data[var->img.pos.height][var->img.pos.width + 1] != '1'))
	{
		var->last_move_time = time(NULL);
		mright(var);
	}
	return (0);
}

int	mouvs_if_s(int key, t_var *var)
{
	if ((key == S_KEY || key == DOWN_KEY)
		&& (var->map.data[var->img.pos.height + 1][var->img.pos.width] == 'E'))
	{
		var->last_move_time = time(NULL);
		check_collect(var);
	}
	else if ((key == S_KEY || key == DOWN_KEY)
		&& (var->map.data[var->img.pos.height + 1][var->img.pos.width] != '1'))
	{
		var->last_move_time = time(NULL);
		mdown(var);
	}
	return (0);
}

int	mouvs_if_w(int key, t_var *var)
{
	if ((key == W_KEY || key == UP_KEY)
		&& (var->map.data[var->img.pos.height - 1][var->img.pos.width] == 'E'))
	{
		var->last_move_time = time(NULL);
		check_collect(var);
	}
	else if ((key == W_KEY || key == UP_KEY)
		&& (var->map.data[var->img.pos.height - 1][var->img.pos.width] != '1'))
	{
		var->last_move_time = time(NULL);
		mup(var);
	}
	return (0);
}

int	mouvs(int key, t_var *var)
{
	if ((key == A_KEY || key == LEFT_KEY)
		&& (var->map.data[var->img.pos.height][var->img.pos.width - 1] == 'E'))
	{
		var->last_move_time = time(NULL);
		check_collect(var);
	}
	else if ((key == A_KEY || key == LEFT_KEY)
		&& (var->map.data[var->img.pos.height][var->img.pos.width - 1] != '1'))
	{
		var->last_move_time = time(NULL);
		mleft(var);
	}
	mouvs_if_d(key, var);
	mouvs_if_s(key, var);
	mouvs_if_w(key, var);
	return (0);
}
