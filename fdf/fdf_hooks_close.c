/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_hooks_close.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogde-so <rogde-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 13:57:35 by rogde-so          #+#    #+#             */
/*   Updated: 2025/09/05 20:09:37 by rogde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx-linux/mlx.h"
#include "minilibx-linux/mlx_int.h"
#include "fdf.h"

int	close_window(t_pointers *data)
{
	free_and_destroy(data, data->img_ptr);
	exit (0);
	return (0);
}

void	ft_zoom(t_iso *iso, int flag)
{
	double	zoom;

	zoom = 1.05;
	if (flag > 0)
	{
		iso->zoom *= zoom;
		if (iso->zoom >= ZOOM_MAX)
			iso->zoom = ZOOM_MAX;
	}
	else if (flag == 0)
	{
		if (!(iso->zoom <= ZOOM_MIN))
			iso->zoom /= zoom;
	}
}

void	move_hook(t_pointers *data, int keycode)
{
	if (keycode == LEFT)
		data->mx += NEG_SPEED;
	if (keycode == RIGHT)
		data->mx += POS_SPEED;
	if (keycode == UP)
		data->my += NEG_SPEED;
	if (keycode == DOWN)
		data->my += POS_SPEED;
}

static void	switch_pallet(int keycode, t_pointers *data)
{
	if (!data)
		return ;
	if (keycode == Q)
		data->pallet_set = 0;
	else if (keycode == W)
		data->pallet_set = 1;
	else if (keycode == E)
		data->pallet_set = 2;
	else if (keycode == R)
		data->pallet_set = 3;
	else if (keycode == T)
		data->pallet_set = 4;
	else if (keycode == Y)
		data->pallet_set = 5;
}

int	keypress(int keycode, t_pointers *data)
{
	t_iso	*iso;

	iso = &data->iso;
	if (keycode == ESC_KEY)
		free_and_destroy(data, data->img_ptr);
	else if (keycode == ZOOM_IN)
		ft_zoom(iso, 1);
	else if (keycode == ZOOM_OUT)
		ft_zoom(iso, 0);
	else if (keycode == LEFT || keycode == RIGHT
		|| keycode == UP || keycode == DOWN)
		move_hook(data, keycode);
	else if (keycode == Q || keycode == W || keycode == E || keycode == R
		|| keycode == T || keycode == Y)
		switch_pallet(keycode, data);
	else
		return (0);
	clear_image(data->img_ptr, data->img_ptr->len);
	center_iso_project(data);
	draw_lines(data);
	mlx_put_image_to_window(data->mlx_ptr, data->window_ptr,
		data->img_ptr->image, 0, 0);
	return (0);
}
