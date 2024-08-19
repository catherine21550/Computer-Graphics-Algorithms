/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuk <khuk@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 13:55:17 by khuk              #+#    #+#             */
/*   Updated: 2024/08/18 17:27:43 by khuk             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <math.h>
# include <stdlib.h>
# include <stddef.h>
# include "GNL/get_next_line_bonus.h"
# include <X11/keysym.h>

typedef struct s_map
{
	int		**map;
	long	strlen;
	long	arrlen;
}	t_map;

typedef struct	s_img
{
	void	*img_ptr;
	int		size_line;
	int		width;
	int		height;
	int		endian;
	int		bits_per_pixel;
	char	*ptr_imgbit;
}	t_img;

//Count of lines and q-ty of the numbers in line
int		ft_isnum(char c);
int		ft_isendornewl(char c);
long	str_width(char *str);
long	count_lines(int fd, long *nums);
long	lines_number(int ac, char *av[], long *nums);
//Saving the map
int		create_struct(int ac, char *av[], t_map *my_map);
int		get_map(int ac, char *av[], t_map *map);
//Clean memory
void	free_split(char **arr);
void	free_map(t_map *map);
void	cl_gnl(int fd);

#endif
