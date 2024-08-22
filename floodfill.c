/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfilling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjamil <mjamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 22:07:51 by mjamil            #+#    #+#             */
/*   Updated: 2024/08/15 12:30:22 by mjamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	error1(t_var *var, char *msg)
{
	if (var != NULL)
	{
		cleanup(var);
	}
	printf("Error\n%s\n", msg);
	exit (EXIT_FAILURE);
}

void	cleanup(t_var *var)
{
	free_maps(var);
}

int	error2(char *msg)
{
	printf("Error\n%s\n", msg);
	exit (EXIT_FAILURE);
}

void	errorss(t_var *var, char *msg, int **visited, t_position size)
{
	if (visited)
		free_visited(visited, size);
	if (var != NULL)
	{
		cleanup(var);
	}
	printf("Error\n%s\n", msg);
	exit(EXIT_FAILURE);
}

void	depth_search(char **data, t_position current,
t_position size, int **visited)
{
	int			i;
	t_position	next_positions[4];

	next_positions[0].width = current.width;
	next_positions[0].height = current.height + 1;
	next_positions[1].width = current.width;
	next_positions[1].height = current.height - 1;
	next_positions[2].width = current.width + 1;
	next_positions[2].height = current.height;
	next_positions[3].width = current.width - 1;
	next_positions[3].height = current.height;
	if (current.height < 0 || current.height >= size.height
		|| current.width < 0 || current.width >= size.width
		|| data[current.height][current.width] == '1'
		|| visited[current.height][current.width])
		return ;
	visited[current.height][current.width] = 1;
	i = 0;
	while (i < 4)
	{
		depth_search(data, next_positions[i], size, visited);
		i++;
	}
}
