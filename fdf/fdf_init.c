/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogde-so <rogde-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 13:56:36 by rogde-so          #+#    #+#             */
/*   Updated: 2025/09/05 17:59:05 by rogde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx-linux/mlx.h"
#include "minilibx-linux/mlx_int.h"
#include "fdf.h"

void	set_pallets(t_pointers *data)
{
	data->pallet[0] = (t_pallet){LIGHTTEAL, DEEPTEAL, SKYBLUE};
	data->pallet[1] = (t_pallet){ROSEPINK, FUCHSIA, CRIMSON};
	data->pallet[2] = (t_pallet){GOLD, BRONZE, AMBER};
	data->pallet[3] = (t_pallet){GREEN, PURPLE, GRAY};
	data->pallet[4] = (t_pallet){RED, MAROON, BLOODRED};
	data->pallet[5] = (t_pallet){IVORY, BEIGE, TAUPE};
}

void	window_setup(t_pointers *data)
{
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
	{
		perror("Can't acess mlx");
		exit(1);
	}
	data->window_ptr = mlx_new_window(data->mlx_ptr, WIN_W, WIN_H, "FDF");
	if (data->window_ptr == NULL)
	{
		free_and_destroy(data, data->img_ptr);
		perror("Can't open window");
		exit(1);
	}
}

void	image_setup(t_image *i, t_pointers *data)
{
	i->image = mlx_new_image(data->mlx_ptr, WIN_W, WIN_H);
	if (i->image == NULL)
	{
		free_and_destroy(data, i);
		perror("Can't get image :|");
		exit(1);
	}
	i->addr = mlx_get_data_addr(i->image, &i->bits, &i->len, &i->endian);
	if (i->addr == NULL)
	{
		free_and_destroy(data, i);
		perror("Can't get image address :|");
		exit(1);
	}
}
