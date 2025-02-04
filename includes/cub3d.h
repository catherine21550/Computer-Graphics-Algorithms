/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuk <khuk@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 09:43:26 by teesmaa           #+#    #+#             */
/*   Updated: 2025/02/04 22:18:53 by khuk             ###   ########.fr       */
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
bool	ft_isspace(char c);
void	exit_error(char *str);
void	parser(t_data *data);
void	cleanup(t_data *data);
void	clean_gnl(int fd);
void	check_map(t_data *data);
char	*get_texture_path(char *str);
int		get_color(char *str);

#endif
