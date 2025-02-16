/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuk <khuk@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 19:34:42 by khuk              #+#    #+#             */
/*   Updated: 2025/02/17 00:36:29 by khuk             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHIC_H
#define GRAPHIC_H

# include "cub3d.h"

# ifndef W_WIDTH
#  define W_WIDTH 800
# endif

# ifndef W_HEIGHT
#  define W_HEIGHT 600
# endif

typedef	struct s_dda
{
	int			x_map;
	int			y_map;
	double		x_dist_wall;
	double		y_dist_wall;
	double		x_step;
	double		y_step;
	int			side;
}	t_dda;


enum	e_key
{
	ESC = 65307,
	W = 119,
	A = 97,
	S = 115,
	D = 100,
	UP = 65362,
	DOWN = 65364,
	RIGHT = 65363,
	LEFT = 65361
};

enum	e_dir
{
	X_UP = 0,
	Y_UP = 1,
	X_DOWN = 0,
	Y_DOWN = -1,
	X_RIGHT = 1,
	Y_RIGHT = 0,
	X_LEFT = -1,
	Y_LEFT = 0
};

# ifndef E_DIRX
#  define E_DIRX X_UP
# endif

# ifndef E_DIRY
#  define E_DIRY Y_UP
# endif

size_t	size_of_map_x(t_data *data);
void	fill_coordinates(t_game *main);
int		key_function(int key, t_game *data);
int 	mouse_move_function(int x, int y, void *param);
int		exit_function(t_game *data);
void	destroy_graphics(t_game *data);
void	ft_free_coord(t_scene **scene, int size);
void	scene_init(t_game *main);
double	ft_abs(double i);
int		ft_sign_dda(double i);
void	solid_color(t_game *d, int x, int y);
void	my_put_pixel(t_game *main, int x, int y, int color);
void	draw_line(t_game *main, double	x, double *line_param, int color);
void	draw_img(t_game *main);
void	ft_dda(t_game *main, t_dda *d, double *delta, double *k);

#endif