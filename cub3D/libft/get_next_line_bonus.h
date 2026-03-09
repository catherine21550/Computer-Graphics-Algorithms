/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuk <khuk@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 19:24:49 by khuk              #+#    #+#             */
/*   Updated: 2025/02/28 11:36:42 by teesmaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <limits.h>
# include <stdint.h>
# include "printf/ft_printf.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

typedef struct s_data	t_data;

char	*ft_strchr_gnl(const char *str, int c);
size_t	ft_strlen_gnl(const char *str);
char	*ft_strndup(const char *str, size_t size);
void	*ft_calloc_gnl(size_t nmemb, size_t size);
char	*ft_strjoin_new(char *s1, char *s2);
char	*get_next_line_custom(int fd, t_data *data);
void	clean_gnl(int fd, t_data *data);

#endif
