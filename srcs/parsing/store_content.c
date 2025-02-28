/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_content.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuk <khuk@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 12:34:09 by teesmaa           #+#    #+#             */
/*   Updated: 2025/02/25 14:27:56 by teesmaa          ###   ########.fr       */
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
	int		fd;
	int		i;

	init_data(data);
	fd = open(arg, O_RDONLY);
	if (fd == -1)
		exit_error(strerror(errno));
	data->content = malloc(sizeof(char *) * (count_lines(arg, data) + 1));
	if (!data->content)
		exit_error("Failed to allocate memory");
	i = 0;
	data->content[i] = get_next_line_custom(fd, data);
	while (data->content[i++] != NULL)
		data->content[i] = get_next_line_custom(fd, data);
	clean_gnl(fd, data);
	if (data->gnl_error)
	{
		cleanup(data);
		exit_error("get_next_line() failed");
	}
	if (close(fd) == -1)
	{
		cleanup(data);
		exit_error("Failed to close file");
	}
}
