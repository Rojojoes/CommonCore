/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogde-so <rogde-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 13:55:17 by rogde-so          #+#    #+#             */
/*   Updated: 2025/09/02 18:10:39 by rogde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx-linux/mlx.h"
#include "minilibx-linux/mlx_int.h"
#include "fdf.h"

void	find_z_values(t_pointers *data)
{
	int	row;
	int	col;
	int	value;

	row = 0;
	data->z_max = INT_MIN;
	data->z_min = INT_MAX;
	while (row < data->map_rows)
	{
		col = 0;
		while (col < data->map_cols)
		{
			value = data->matrix[row][col];
			if (value < data->z_min)
				data->z_min = value;
			if (value > data->z_max)
				data->z_max = value;
			col++;
		}
		row++;
	}
}

static void	set_color(unsigned char *dst, int edn, u_int32_t c)
{
	if (edn == 0)
	{
		dst[0] = c & 0xFFu;
		dst[1] = (c >> 8) & 0xFFu;
		dst[2] = (c >> 16) & 0xFFu;
	}
	else
	{
		dst[0] = (c >> 16) & 0xFFu;
		dst[1] = (c >> 8) & 0xFFu;
		dst[2] = c & 0xFFu;
	}
}

void	ft_put_pixels(t_image *img, int x, int y, int color)
{
	unsigned char	*dst;
	size_t			offset;
	int				bpp;

	if (img == NULL || img->addr == NULL)
		return (perror("No image/image address.."));
	if (x < 0 || y < 0 || x >= WIN_W || y >= WIN_H)
		return ;
	bpp = img->bits / 8;
	if (bpp < 3)
		return (perror("Bytes per pixel less than 3, whattafuck?"));
	offset = (size_t)y * (size_t)img->len + (size_t)x * (size_t)bpp;
	dst = (unsigned char *)img->addr + offset;
	set_color(dst, img->endian, (u_int32_t)color);
}
