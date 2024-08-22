/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjamil <mjamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 11:43:12 by ral-faya          #+#    #+#             */
/*   Updated: 2024/08/15 12:01:51 by mjamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_position	find_startposition(char **data, t_position size)
{
	t_position	start;
	int			i;
	int			j;

	i = 0;
	start.width = -1;
	start.height = -1;
	while (i < size.height)
	{
		j = 0;
		while (j < size.width)
		{
			if (data[i][j] == 'P')
			{
				start.height = i;
				start.width = j;
				return (start);
			}
			j++;
		}
		i++;
	}
	return (start);
}

void	handle_error(t_var *var, char type, int **visited)
{
	if (type == 'E')
		errorss(var, "invalid map: there is no valid path",
			visited, var->map.size);
	else if (type == 'C')
		errorss(var, "invalid map: not all C are reachable",
			visited, var->map.size);
}

void	check_pathandcollectibles(t_var var, int **visited)
{
	int	i;
	int	j;
	int	result;

	i = 0;
	result = 1;
	while (i < var.map.size.height && result)
	{
		j = 0;
		while (j < var.map.size.width)
		{
			if ((var.map.data[i][j] == 'E' || var.map.data[i][j] == 'C')
				&& !visited[i][j])
			{
				result = 0;
				handle_error(&var, var.map.data[i][j], visited);
				break ;
			}
			j++;
		}
		i++;
	}
}

int	has_valid_paths(t_var var)
{
	int			**visited;
	int			i;
	t_position	start;
	t_position	size;

	size.width = var.map.size.width;
	size.height = var.map.size.height;
	visited = (int **)malloc(var.map.size.height * sizeof(int *));
	if (!visited)
		free_map(&var);
	i = 0;
	while (i < var.map.size.height)
	{
		visited[i] = (int *)ft_calloc(var.map.size.width, sizeof(int));
		i++;
	}
	i = 0;
	start = find_startposition(var.map.data, size);
	depth_search(var.map.data, start, size, visited);
	check_pathandcollectibles(var, visited);
	i = 0;
	free_visited(visited, size);
	return (0);
}

int	check_map(t_var var)
{
	check_evironment(var);
	has_valid_paths(var);
	return (0);
}
