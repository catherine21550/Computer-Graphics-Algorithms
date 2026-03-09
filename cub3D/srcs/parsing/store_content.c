/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_content.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuk <khuk@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 12:34:09 by teesmaa           #+#    #+#             */
/*   Updated: 2025/03/05 14:57:10 by khuk             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	count_lines(char *arg, t_data *data)
{
	int		lines;
	char	*str;
	int		fd;

	fd = open(arg, O_RDONLY);
	if (fd == -1)
		exit_error(strerror(errno));
	lines = 0;
	str = get_next_line_custom(fd, data);
	while (str != NULL)
	{
		lines++;
		free(str);
		str = get_next_line_custom(fd, data);
	}
	clean_gnl(fd, data);
	if (data->gnl_error)
		exit_error("get_next_line() failed");
	if (close(fd) == -1)
		exit_error("Failed to close file");
	return (lines);
}

static void	init_data(t_data *data)
{
	data->content = NULL;
	data->map = NULL;
	data->rows = 0;
	data->player_pos[0] = 0;
	data->player_pos[1] = 0;
	data->player_dir = 0;
	data->no = NULL;
	data->so = NULL;
	data->we = NULL;
	data->ea = NULL;
	data->floor = -1;
	data->ceiling = -1;
	data->gnl_error = 0;
}

void	save_data(char *arg, t_data *data)
{
	int		fd[2];
	int		i;

	init_data(data);
	fd[0] = open(arg, O_RDONLY);
	if (fd[0] == -1)
		exit_error(strerror(errno));
	fd[1] = count_lines(arg, data);
	if (fd[1] > 0)
		data->content = ft_calloc(sizeof(char *), (fd[1] + 1));
	if (!data->content)
		return (close(fd[0]), exit_error("Failed to allocate memory"));
	i = 0;
	data->content[i] = get_next_line_custom(fd[0], data);
	while (data->content[i++] != NULL)
	{
		data->content[i] = get_next_line_custom(fd[0], data);
		if (data->gnl_error)
			return (cleanup(data), close(fd[0]), exit_error(GNL_ER));
	}
	clean_gnl(fd[0], data);
	if (data->gnl_error)
		return (cleanup(data), close(fd[0]), exit_error(GNL_ER));
	if (close(fd[0]) == -1)
		return (cleanup(data), exit_error("Failed to close file"));
}
