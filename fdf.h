/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuk <khuk@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 13:55:17 by khuk              #+#    #+#             */
/*   Updated: 2024/08/13 17:23:42 by khuk             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

typedef struct s_map
{
    int **map;
    int strlen;
}   t_map;

//Count of lines and q-ty of the numbers in line
int	ft_isnum(char c);
int	ft_isendornewl(char c);
size_t	str_width(char *str);
int	count_lines(int fd, int *nums);
int	lines_number(int ac, char *av[], int *nums);
//Saving the map

# include <mlx.h>
# include <math.h>
# include <stdlib.h>
# include <stddef.h>
# include "GNL/get_next_line_bonus.h"
# include <X11/keysym.h>

#endif
