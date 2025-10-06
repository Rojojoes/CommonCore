/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogde-so <rogde-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 15:27:14 by rogde-so          #+#    #+#             */
/*   Updated: 2025/09/05 17:18:01 by rogde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "minilibx-linux/mlx.h"
#include "minilibx-linux/mlx_int.h"
#include "libft/libft.h"

void	error_check(int ac, char **av, int *fd)
{
	if (ac != 2)
	{
		perror("Too many/few arguments");
		exit (1);
	}
	if (av[1] == NULL)
	{
		perror("Map not valid bruh");
		exit (1);
	}
	if (ft_strnstr(av[1], ".fdf", 100) == NULL)
	{
		perror("Map is not an .fdf bruh");
		exit (1);
	}
	*fd = open(av[1], O_RDONLY);
	if (*fd == -1)
	{
		perror("Map cannot be read/Doesn't exist");
		exit (1);
	}
}

int	main(int ac, char *av[])
{
	static t_pointers	ptrs;
	static t_image		img;

	ptrs.img_ptr = &img;
	set_pallets(&ptrs);
	error_check(ac, av, &ptrs.map_fd);
	window_setup(&ptrs);
	image_setup(&img, &ptrs);
	map_matrix_setup(av[1], &ptrs, &img);
	ptrs.dots = matrix_to_coordinates(&ptrs);
	if (ptrs.dots == NULL)
		return (free_and_destroy(&ptrs, &img), 1);
	center_iso_project(&ptrs);
	draw_lines(&ptrs);
	mlx_put_image_to_window(ptrs.mlx_ptr, ptrs.window_ptr, img.image, 0, 0);
	mlx_hook(ptrs.window_ptr, 2, 1L << 0, keypress, &ptrs);
	mlx_hook(ptrs.window_ptr, 17, 0L, close_window, &ptrs);
	mlx_loop(ptrs.mlx_ptr);
	return (0);
}
