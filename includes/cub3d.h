/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuk <khuk@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 09:43:26 by teesmaa           #+#    #+#             */
/*   Updated: 2025/02/17 00:23:52 by khuk             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <errno.h>
# include <string.h>
# include <sys/time.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <mlx.h>
# include <math.h>
# include <stdbool.h>
# include <X11/keysym.h>
# include "../libft/libft.h"

# define DIRECTIONS "NSWE"
# define INSIDE_MAP "0NSWE"

typedef struct  s_data
{
	char	**content;
	char	**map;
	int		rows;
	int		cols;
	int		player_pos[2];
	char	player_dir;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		floor;
	int		ceiling;

}	t_data;

typedef	struct s_square
{
	double	x;
	double	y;
	int		type;
	int		color;
}	t_square;


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

typedef struct	s_scene
{
	t_square	**coord;
	size_t		x_size;
	size_t		y_size;
	t_square	*player;
	double		x_dir;
	double		y_dir;
	double		x_plane;
	double		y_plane;
	double		angle;
	double		time;
	double		old_time;
	//double      move_speed;
}	t_scene;

typedef struct  s_game
{
	t_data	*data;
	void	*mlx_ptr;
	void	*win_ptr;
	t_scene *scene;
	int		win_width;
	int		win_height;
	t_img	img;
}	t_game;

enum	e_elements
{
	NONE = -1,
	FLOOR,
	WALL,
	PLAY,
	SPRITE
};

// ################# //
//      Parcing      //
// ################# //
void	save_data(char *arg, t_data *data);
bool	ft_isspace(char c);
void	exit_error(char *str);
void	parser(t_data *data);
void	cleanup(t_data *data);
void	check_map(t_data *data);
char	*get_texture_path(char *str);
int		get_color(char *str);

// ################# //
//      Graphic      //
// ################# //
void	handle_graphics(t_game *main);

#endif
