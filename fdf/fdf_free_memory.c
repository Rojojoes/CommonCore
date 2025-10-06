/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_free_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogde-so <rogde-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 18:14:27 by rogde-so          #+#    #+#             */
/*   Updated: 2025/09/02 09:10:07 by rogde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx-linux/mlx.h"
#include "minilibx-linux/mlx_int.h"
#include "fdf.h"
#include "libft/libft.h"

void	clear_image(t_image *img, int len)
{
	if (!img || !img->addr)
		return ;
	ft_bzero(img->addr, WIN_H * len);
}

void	free_char_map(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i] != NULL)
		free(matrix[i++]);
	free(matrix);
}

void	free_int_map(int **matrix, int count)
{
	int	i;

	i = 0;
	while (i < count)
		free(matrix[i++]);
	free(matrix);
}

void	free_and_destroy(t_pointers *data, t_image *img)
{
	int	i;

	i = 0;
	if (img && img->image)
		mlx_destroy_image(data->mlx_ptr, data->img_ptr->image);
	if (data->window_ptr)
		mlx_destroy_window(data->mlx_ptr, data->window_ptr);
	if (data->mlx_ptr)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
	}
	if (data->map)
		free_char_map(data->map);
	if (data->dots)
		free(data->dots);
	free_int_map(data->matrix, data->map_rows);
	close(data->map_fd);
	exit (1);
}
