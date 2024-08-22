/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjamil <mjamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 11:41:13 by ral-faya          #+#    #+#             */
/*   Updated: 2024/08/15 12:30:22 by mjamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_lines(char *filename)
{
	int		fd;
	int		num_lines;
	char	*line;

	num_lines = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		error2("map not found");
	line = get_next_line(fd);
	while (line != NULL)
	{
		num_lines++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (num_lines);
}

void	read_map(t_var *var, char *filename)
{
	int		fd;
	char	*line;
	int		line_length;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		error2("map not found");
	line = get_next_line(fd);
	while (line != NULL)
	{
		var->map.data[var->map.size.height] = line;
		line_length = ft_strlen(line);
		if (line[line_length - 1] == '\n')
		{
			line[line_length - 1] = '\0';
			line_length--;
		}
		if (var->map.size.height == 0)
			var->map.size.width = line_length;
		var->map.size.height++;
		line = get_next_line(fd);
	}
	if (line)
		free(line);
	close(fd);
}

int	get_map(t_var *var, char **argv)
{
	int	num_lines;

	num_lines = count_lines(argv[1]);
	var->map.data = (char **)malloc(num_lines * sizeof(char *));
	if (!var->map.data)
		error2("memory allocation failed");
	read_map(var, argv[1]);
	return (0);
}

int	load_map(t_var var, int row, int col)
{
	if (var.map.data[row][col] == '1')
		var.img.img_ptr = mlx_xpm_file_to_image(var.mlx, "./img/wall.xpm",
				&var.img.size.width, &var.img.size.height);
	else if (var.map.data[row][col] == '0')
		var.img.img_ptr = mlx_xpm_file_to_image(var.mlx, "./img/floor.xpm",
				&var.img.size.width, &var.img.size.height);
	else if (var.map.data[row][col] == 'E')
		var.img.img_ptr = mlx_xpm_file_to_image(var.mlx, "./img/exit.xpm",
				&var.img.size.width, &var.img.size.height);
	else if (var.map.data[row][col] == 'C')
		var.img.img_ptr = mlx_xpm_file_to_image(var.mlx, "./img/coins.xpm",
				&var.img.size.width, &var.img.size.height);
	else if (var.map.data[row][col] == 'P')
		var.img.img_ptr = mlx_xpm_file_to_image(var.mlx, var.img.spt_path,
				&var.img.size.width, &var.img.size.height);
	mlx_put_image_to_window(var.mlx, var.win, var.img.img_ptr, SPRITE_W * col,
		SPRITE_H * row);
	mlx_destroy_image(var.mlx, var.img.img_ptr);
	return (0);
}

int	print_map(t_var var)
{
	int		row;
	int		col;

	row = 0;
	while (row < var.map.size.height)
	{
		col = 0;
		while (col < var.map.size.width)
		{
			load_map(var, row, col);
			col++;
		}
		row++;
	}
	return (0);
}
