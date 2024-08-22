/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eventlistener.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjamil <mjamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 22:07:59 by mjamil            #+#    #+#             */
/*   Updated: 2024/08/15 12:00:23 by mjamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	mlx_close(t_var *var)
{
	free_exit(var, "Game closed! (X)\n");
	return (0);
}

int	key_press(int key, t_var *var)
{
	int	init_steps;

	init_steps = var->game.count_steps;
	if (key == ESC)
		free_exit(var, "Game closed! (ESC)\n");
	else
		mouvs(key, var);
	if (init_steps != var->game.count_steps)
		printf("you’ve stepped %d so far!! "
			"\n", var->game.count_steps);
	print_map(*var);
	print_steps(var);
	return (0);
}
