/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_matrix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogde-so <rogde-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 18:13:09 by rogde-so          #+#    #+#             */
/*   Updated: 2025/09/03 13:49:52 by rogde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx-linux/mlx.h"
#include "minilibx-linux/mlx_int.h"
#include "fdf.h"
#include "libft/libft.h"

char	**get_map_rows(char *map, t_pointers *data)
{
	char			**fdf_map;
	static int		i;

	while (1)
	{
		data->line = get_next_line(data->map_fd);
		if (data->line == NULL)
			break ;
		data->map_rows++;
		free(data->line);
	}
	fdf_map = malloc(sizeof(char *) * (data->map_rows + 1));
	if (!fdf_map)
		return (perror("Map malloc failed"), NULL);
	close(data->map_fd);
	data->map_fd = open(map, O_RDONLY);
	while (1)
	{
		data->line = get_next_line(data->map_fd);
		if (data->line == NULL)
			break ;
		fdf_map[i++] = data->line;
	}
	fdf_map[i] = NULL;
	return (fdf_map);
}

int	get_map_cols(char **map, t_pointers *data)
{
	char	**cols;
	int		i;

	i = 0;
	cols = ft_split(map[0], ' ');
	if (!cols)
		return (perror("ft_split failed to get cols"), -1);
	while (cols[data->map_cols])
		data->map_cols++;
	while (cols[i])
		free(cols[i++]);
	free(cols);
	cols = NULL;
	if (data->map_cols == 0)
		return (perror("Empty first row/map?"), -1);
	return (0);
}

void	create_matrix(char **map, t_pointers *data)
{
	static int		rows;
	int				cols;
	char			**tokens;

	data->matrix = malloc(sizeof(int *) * data->map_rows);
	if (data->matrix == NULL)
		return ;
	while (rows < data->map_rows)
	{
		tokens = ft_split(map[rows], ' ');
		if (tokens == NULL)
			return (free_int_map(data->matrix, rows));
		data->matrix[rows] = malloc(sizeof(int) * data->map_cols);
		if (data->matrix[rows] == NULL)
			return (free_char_map(tokens), free_int_map(data->matrix, rows));
		cols = 0;
		while (cols < data->map_cols)
		{
			data->matrix[rows][cols] = ft_atoi(tokens[cols]);
			free(tokens[cols]);
			cols++;
		}
		free(tokens);
		rows++;
	}
}

t_dot	*matrix_to_coordinates(t_pointers *data)
{
	int		row;
	int		column;
	int		index;
	t_dot	*points;

	row = 0;
	if ((data->map_rows * data->map_cols) > INT_MAX)
		return (perror("Map too big"), NULL);
	points = malloc(sizeof(t_dot) * (data->map_rows * data->map_cols));
	if (!points)
		return (perror("Malloc fail"), NULL);
	while (row < data->map_rows)
	{
		column = 0;
		while (column < data->map_cols)
		{
			index = row * data->map_cols + column;
			points[index].x = column;
			points[index].y = row;
			points[index].z = data->matrix[row][column];
			column++;
		}
		row++;
	}
	return (points);
}

void	map_matrix_setup(char *map, t_pointers *data, t_image *img)
{
	data->map = get_map_rows(map, data);
	if (data->map == NULL)
		free_and_destroy(data, img);
	if (get_map_cols(data->map, data) != 0)
		free_and_destroy(data, img);
	create_matrix(data->map, data);
	if (data->matrix == NULL)
		free_and_destroy(data, img);
	find_z_values(data);
}
