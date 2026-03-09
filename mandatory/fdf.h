/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuk <khuk@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 13:55:17 by khuk              #+#    #+#             */
/*   Updated: 2024/08/25 13:21:28 by khuk             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <math.h>
# include <stdlib.h>
# include <errno.h>
# include <stddef.h>
# include <string.h>
# include "../GNL/get_next_line_bonus.h"
# include <X11/keysym.h>

typedef struct s_map
{
	int		**map;
	long	strlen;
	long	arrlen;
}			t_map;

typedef struct s_img
{
	void	*img_ptr;
	int		size_line;
	int		width;
	int		height;
	int		endian;
	int		bits_per_pixel;
	char	*ptr_imgbit;
}			t_img;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		win_w;
	int		win_h;
	int		color;
	int		color_pic;
	int		ang;
	int		scale;
	int		ac;
	char	**av;
	t_img	img;
	t_map	map;
	t_map	x;
	t_map	y;
}			t_data;

//Count of lines and q-ty of the numbers in line
int		ft_isspace(char c);
int		ft_isendornewl(char c);
long	str_width(char *str);
long	count_lines(int fd, long *nums);
long	lines_number(int ac, char *av[], long *nums, t_data *data);
//Saving the map
int		create_struct(int ac, char *av[], t_map *my_map, t_data *data);
int		get_map(int ac, char *av[], t_map *map, t_data *data);
int		memalloc_coord(t_data *data, int ac, char *av[]);
//Clean memory
void	free_split(char **arr);
void	free_map(t_map *map);
void	cl_gnl(int fd);
void	destroy_evrth(t_data *data);
void	free_data(t_data *data);
//Drawing functions
void	my_put_pixel(t_data *d, int x, int y, int color);
void	solid_color(t_data *d, int x, int y);
void	draw_img(t_data *data, int ac, char *av[]);
void	fdf_center(t_data *data, int *shift_x, int *shift_y);
void	fdf_redraw_img(t_data *data, int ac, char *av[]);
void	shift_img(t_data *data);
//Helper functions
int		ft_abs(int i);
int		str_isnum(char	*str);
void	input_check(int ac, char *av[]);
void	init_func(t_data *data, int ac, char *av[]);
//Mouse or key handling
int		mouse_handling(int button, int x, int y, t_data *data);
int		key_function(int key, t_data *data);
int		exit_function(t_data *data);
#endif
