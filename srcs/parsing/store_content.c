/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_content.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teesmaa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 12:34:09 by teesmaa           #+#    #+#             */
/*   Updated: 2025/01/30 12:34:57 by teesmaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/cub3d.h"

static int	count_lines(char *arg)
{
	int		lines;
	char	*str;
	int		fd;

	fd = open(arg, O_RDONLY);
	if (fd == -1)
		exit_error(strerror(errno));
	lines = 0;
	str = get_next_line(fd);
	while (str != 0)
	{
		lines++;
		free(str);
		str = get_next_line(fd);
	}
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
	data->floor = 0;
	data->ceiling = 0;
}

void	save_data(char *arg, t_data *data)
{
	int		fd;
	int		i;

	init_data(data);
	fd = open(arg, O_RDONLY);
	if (fd == -1)
		exit_error(strerror(errno));
	data->content = malloc(sizeof(char *) * (count_lines(arg) + 1));
	if (!data->content)
		exit_error("Failed to allocate memory");
	i = 0;
	data->content[i] = get_next_line(fd);
	while (data->content[i])
	{
		i++;
		data->content[i] = get_next_line(fd);
	}
}
