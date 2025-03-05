/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuk <khuk@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 18:14:30 by khuk              #+#    #+#             */
/*   Updated: 2025/03/05 14:16:18 by khuk             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	clean_gnl(int fd, t_data *data)
{
	char	*tmp;

	tmp = get_next_line_custom(fd, data);
	while (tmp != NULL)
	{
		free(tmp);
		tmp = get_next_line_custom(fd, data);
	}
	free(tmp);
}

static char	*ft_createnewbuff(int fd, char **buff, ssize_t *readchr,
			t_data *data)
{
	char	*tmp;
	char	*readtmp;

	readtmp = ft_calloc_gnl(BUFFER_SIZE + 1, sizeof(char));
	if (!readtmp)
	{
		data->gnl_error = 1;
		return (free(readtmp), free(*buff), tmp = NULL,
			readtmp = NULL, *buff = NULL, NULL);
	}
	*readchr = read(fd, readtmp, BUFFER_SIZE);
	if (*readchr == -1)
	{
		data->gnl_error = 1;
		return (free(readtmp), readtmp = NULL,
			free(*buff), *buff = NULL, NULL);
	}
	else if (*readchr == 0)
		return (free(readtmp), readtmp = NULL, *buff);
	tmp = ft_strjoin_new(*buff, readtmp);
	if (!tmp)
		data->gnl_error = 1;
	return (free(readtmp), free(*buff), *buff = NULL, readtmp = NULL, tmp);
}

static char	*ft_getline(char *buff, t_data *data)
{
	size_t	i;
	char	*line;

	i = 0;
	if (!buff)
		return (NULL);
	while (buff[i] != '\n' && buff[i] != '\0')
		i++;
	if (buff[i] == '\n')
		i++;
	line = ft_strndup(buff, i);
	if (!line)
	{
		data->gnl_error = 1;
		return (line = NULL, buff = NULL, NULL);
	}
	return (line);
}

static char	*ft_clean_buffer(char *buffer, t_data *data)
{
	char	*newline;
	char	*tmp;	

	if (!buffer)
		return (buffer = NULL, NULL);
	newline = ft_strchr_gnl(buffer, '\n');
	if (newline)
	{
		newline++;
		tmp = ft_strndup(newline, ft_strlen_gnl(newline));
		free(buffer);
		buffer = NULL;
		if (!tmp)
		{
			data->gnl_error = 1;
			return (tmp = NULL);
		}
		else if (*tmp == '\0')
			return (free(tmp), tmp = NULL, NULL);
		return (tmp);
	}
	else
		return (free(buffer), buffer = NULL, tmp = NULL, NULL);
}

char	*get_next_line_custom(int fd, t_data *data)
{
	static char		*readbuffs[1024] = {NULL};
	char			*new_line;
	ssize_t			readres;

	if (fd < 0 || BUFFER_SIZE < 1 || fd >= 1024)
		return (free(readbuffs[fd]), readbuffs[fd] = NULL, NULL);
	readres = BUFFER_SIZE;
	while (!ft_strchr_gnl(readbuffs[fd], '\n') && (readres == BUFFER_SIZE))
	{
		readbuffs[fd] = ft_createnewbuff(fd, &readbuffs[fd], &readres, data);
		if (readbuffs[fd] == NULL)
			return (NULL);
	}
	new_line = ft_getline(readbuffs[fd], data);
	if (!new_line)
	{
		data->gnl_error = 1;
		return (free(readbuffs[fd]), readbuffs[fd] = NULL, NULL);
	}
	readbuffs[fd] = ft_clean_buffer(readbuffs[fd], data);
	return (new_line);
}
