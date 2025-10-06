/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogde-so <rogde-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 15:27:41 by rogde-so          #+#    #+#             */
/*   Updated: 2025/09/05 20:10:08 by rogde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <math.h>
# include <stdint.h>
# include <limits.h>
# include <stdlib.h>

# define ESC_KEY 65307
# define ZOOM_IN 65451
# define ZOOM_OUT 65453
# define LEFT 65361
# define RIGHT 65363
# define UP 65362
# define DOWN 65364
# define Q 113
# define W 119
# define E 101
# define R 114
# define T 116
# define Y 121

# define WIN_W 960
# define WIN_H 540
# define ZOOM_MAX 30.0
# define ZOOM_MIN 1.0
# define POS_SPEED 3.0
# define NEG_SPEED -3.0

/// Q ///
# define LIGHTTEAL 0x81C5C5
# define DEEPTEAL 0x006F6F
# define SKYBLUE 0x60A5FA
/// W ///
# define ROSEPINK 0xE2647A
# define FUCHSIA 0xE30B5D
# define CRIMSON 0xD20A2E
/// E ///
# define GOLD 0xFCC200
# define BRONZE 0xCBA034
# define AMBER 0xFDB414
/// R ///
# define GREEN 0x64AD6B
# define PURPLE 0x300232
# define GRAY 0x3F4A51
/// T ///
# define RED 0xB80000
# define MAROON 0x540707
# define BLOODRED 0x7A0000
/// Y ///
# define IVORY 0xF9F3E8
# define BEIGE 0xD6CCA8
# define TAUPE 0xE1DBC9
/// EXTRAS ///
# define WHITE 0xFFFFFF
# define BLACK 0x000000

typedef struct s_palletes
{
	int	high_color;
	int	low_color;
	int	base_color;
}	t_pallet;

typedef struct s_isoprojection
{
	int		i;
	int		col;
	int		row;
	int		total;
	int		x_off;
	int		y_off;
	double	angle;
	double	zoom;
	double	z_scale;
	double	zx;
	double	zy;
}	t_iso;

typedef struct s_image
{
	void	*image;
	char	*addr;
	int		img_w;
	int		img_h;
	int		bits;
	int		len;
	int		endian;
}	t_image;

typedef struct s_coordinates
{
	int		x;
	int		y;
	int		z;
	int		clr;
	t_image	*image;
}	t_dot;

typedef struct s_edges
{
	int	dx;
	int	dy;
	int	stepx;
	int	stepy;
	int	err;
	int	compare;
}	t_edge;

typedef struct s_pointers
{
	int			**matrix;
	int			map_fd;
	int			map_rows;
	int			map_cols;
	int			z_max;
	int			z_min;
	int			pallet_set;
	double		mx;
	double		my;
	void		*mlx_ptr;
	void		*window_ptr;
	char		**map;
	char		*line;
	t_pallet	pallet[6];	
	t_image		*img_ptr;
	t_dot		*dots;
	t_iso		iso;
}	t_pointers;

/// Parsing & Setup ///
void	set_pallets(t_pointers *data);
void	window_setup(t_pointers *data);
void	error_check(int ac, char **av, int *fd);
void	image_setup(t_image *i, t_pointers *data);
void	create_matrix(char **map, t_pointers *data);
void	map_matrix_setup(char *map, t_pointers *data, t_image *img);
void	find_z_values(t_pointers *data);
int		get_map_cols(char **map, t_pointers *data);
char	**get_map_rows(char *map, t_pointers *data);
t_dot	*matrix_to_coordinates(t_pointers *data);
/// Draw ///
int		set_pallet(t_pointers *data, t_dot *pixel);
void	ft_put_pixels(t_image *img, int x, int y, int color);
void	draw_lines(t_pointers *data);
void	center_iso_project(t_pointers *data);
/// Free & Cleanup ///
void	clear_image(t_image *img, int len);
void	free_and_destroy(t_pointers *data, t_image *img);
void	free_int_map(int **matrix, int count);
void	free_char_map(char **matrix);
/// Hooks ///
int		close_window(t_pointers *data);
int		keypress(int keycode, t_pointers *data);
void	ft_zoom(t_iso *iso, int flag);
void	move_hook(t_pointers *data, int keycode);

#endif