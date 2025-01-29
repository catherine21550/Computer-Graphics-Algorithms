/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teesmaa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 09:43:26 by teesmaa           #+#    #+#             */
/*   Updated: 2025/01/29 09:49:07 by teesmaa          ###   ########.fr       */
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

typedef struct  s_data
{
    char    **content;
    char    **map;
    int     rows;
    int     cols;
    int     player_pos[2];
    char    *no;
    char    *so;
    char    *we;
    char    *ea;
    char    **floor;
    char    **ceiling;

}               t_data;
/* 
typedef struct  s_game
{
    t_data  *data;
    void	*mlx_ptr;
	void	*win_ptr;
}               t_data;
 */
//libft
void	ft_putendl_fd(char *s, int fd);
void    ft_putstr_fd(char *s, int fd);
char	*ft_strchr(const char *str, int c);
char    *ft_strnstr(const char *big, const char *little, size_t len);
size_t	ft_strlen(const char *str);

#endif
