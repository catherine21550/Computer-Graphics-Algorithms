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

void	save_data(char *arg, t_data *data)
{
	int		fd;
	int		i;

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

