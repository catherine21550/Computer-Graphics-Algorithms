/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triinueesmaa <triinueesmaa@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 09:43:26 by teesmaa           #+#    #+#             */
/*   Updated: 2025/02/05 15:04:48 by triinueesma      ###   ########.fr       */
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
# include <stdbool.h>

# include "../libft/libft.h"

# define DIRECTIONS "NSWE"
# define INSIDE_MAP "0NSWE"

typedef enum s_info
{
	NORTH,
	SOUTH,
	WEST,
	EAST,
	FLOOR,
    CEILING,
    MAP
}			t_info;

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

typedef struct  s_game
{
	t_data	*data;
	void	*mlx_ptr;
	void	*win_ptr;
}	t_game;


// ################# //
//      Parcing      //
// ################# //
void	save_data(char *arg, t_data *data);
bool    ft_isspace(char c);
void    exit_error(char *str);
void	parser(t_data *data);
void	cleanup(t_data *data);
void    check_map(t_data *data);
char	*get_texture_path(char *str, char *type, t_data *data, char *path);
int     get_color(char *str, t_data *data, char *type, int oldcolor);
void	free_array(char **str);
int     count_digits(char *str);

#endif
