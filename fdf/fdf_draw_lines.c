/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw_lines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogde-so <rogde-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 15:55:16 by rogde-so          #+#    #+#             */
/*   Updated: 2025/09/05 17:58:20 by rogde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	project_iso_dot(t_dot *dot, t_iso *iso)
{
	double	xd;
	double	yd;

	xd = (double)iso->col;
	yd = (double)iso->row;
	if (!dot)
		return ;
	dot->x = (int)round((xd - yd) * cos(iso->angle) * iso->zoom + iso->x_off);
	dot->y = (int)round((xd + yd) * sin(iso->angle) * iso->zoom
			- (double)dot->z * iso->z_scale + iso->y_off);
}

void	center_iso_project(t_pointers *data)
{
	t_iso	*iso;

	if (!data || !data->dots || data->map_rows <= 0 || data->map_cols <= 0)
		return ;
	iso = &data->iso;
	iso->total = data->map_cols * data->map_rows;
	iso->angle = M_PI / 6.0;
	iso->zx = (double)(WIN_W) / (double)(data->map_cols + data->map_rows);
	iso->zy = (double)(WIN_H) / (double)(data->map_cols + data->map_rows);
	if (iso->zoom <= 0.0)
		iso->zoom = fmin(iso->zx, iso->zy);
	iso->z_scale = iso->zoom * 0.3;
	iso->x_off = WIN_W / 2;
	iso->y_off = WIN_H / 4;
	iso->i = 0;
	while (iso->i < iso->total)
	{
		iso->row = iso->i / data->map_cols;
		iso->col = iso->i % data->map_cols;
		project_iso_dot(&data->dots[iso->i], iso);
		iso->i++;
	}
}

int	set_pallet(t_pointers *data, t_dot *pixel)
{
	int			color;
	t_pallet	color_type;

	color_type = data->pallet[data->pallet_set];
	if (pixel->z == data->z_min)
		color = color_type.low_color;
	else if (pixel->z == data->z_max)
		color = color_type.high_color;
	else
		color = color_type.base_color;
	return (color);
}

static void	bresenham_math(t_pointers *data, t_dot p1, t_dot p2)
{
	t_edge	vars;

	vars.dx = abs(p2.x - p1.x);
	vars.dy = abs(p2.y - p1.y);
	vars.stepx = (p1.x < p2.x) * 2 - 1;
	vars.stepy = (p1.y < p2.y) * 2 - 1;
	vars.err = vars.dx - vars.dy;
	while (1)
	{
		p1.clr = set_pallet(data, &p1);
		ft_put_pixels(data->img_ptr, p1.x + data->mx, p1.y + data->my, p1.clr);
		if (p1.x == p2.x && p1.y == p2.y)
			break ;
		vars.compare = 2 * vars.err;
		if (vars.compare > -vars.dy)
		{
			vars.err -= vars.dy;
			p1.x += vars.stepx;
		}
		if (vars.compare < vars.dx)
		{
			vars.err += vars.dx;
			p1.y += vars.stepy;
		}
	}
}

void	draw_lines(t_pointers *data)
{
	int	i;
	int	y;
	int	x;

	if (!data || !data->dots || !data->img_ptr)
		return ;
	y = 0;
	while (y < data->map_rows)
	{
		x = 0;
		while (x < data->map_cols)
		{
			i = y * data->map_cols + x;
			if (x + 1 < data->map_cols)
				bresenham_math(data, data->dots[i], data->dots[i + 1]);
			if (y + 1 < data->map_rows)
				bresenham_math(data, data->dots[i],
					data->dots[i + data->map_cols]);
			x++;
		}
		y++;
	}
}
