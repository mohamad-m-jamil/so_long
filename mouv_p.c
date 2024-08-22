/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouv_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjamil <mjamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 22:06:56 by mjamil            #+#    #+#             */
/*   Updated: 2024/08/20 12:05:31 by mjamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	mleft(t_var *var)
{
	var->map.data[var->img.pos.height][var->img.pos.width] = '0';
	var->img.pos.width -= 1;
	var->map.data[var->img.pos.height][var->img.pos.width] = 'P';
	var->game.count_steps++;
	var->img.spt_path = "./img/spiderL.xpm";
	return (0);
}

int	mright(t_var *var)
{
	var->map.data[var->img.pos.height][var->img.pos.width] = '0';
	var->img.pos.width += 1;
	var->map.data[var->img.pos.height][var->img.pos.width] = 'P';
	var->game.count_steps++;
	var->img.spt_path = "./img/spiderR.xpm";
	return (0);
}

int	mdown(t_var *var)
{
	var->map.data[var->img.pos.height][var->img.pos.width] = '0';
	var->img.pos.height += 1;
	var->map.data[var->img.pos.height][var->img.pos.width] = 'P';
	var->game.count_steps++;
	var->img.spt_path = "./img/spiderdown.xpm";
	return (0);
}

int	mup(t_var *var)
{
	var->map.data[var->img.pos.height][var->img.pos.width] = '0';
	var->img.pos.height -= 1;
	var->map.data[var->img.pos.height][var->img.pos.width] = 'P';
	var->game.count_steps++;
	var->img.spt_path = "./img/spiderup.xpm";
	return (0);
}
