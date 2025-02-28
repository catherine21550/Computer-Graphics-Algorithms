/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teesmaa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 11:29:49 by teesmaa           #+#    #+#             */
/*   Updated: 2025/02/25 15:09:31 by teesmaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	char_check(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->map[i])
	{
		if (data->map[i][0] == '\0' || data->map[i][0] == '\n')
		{
			cleanup(data);
			exit_error("Map has empty lines");
		}
		j = 0;
		while (data->map[i][j] && data->map[i][j] != '\n')
		{
			if (data->map[i][j] != '1' && !ft_isspace(data->map[i][j])
				&& !ft_strchr(INSIDE_MAP, data->map[i][j]))
			{
				cleanup(data);
				exit_error("map contains forbidden characters");
			}
			j++;
		}
		i++;
	}
}

bool	next_to_space(t_data *data, int i, int j)
{
	if (ft_isspace(data->map[i][j + 1]))
		return (true);
	else if (ft_isspace(data->map[i][j - 1]))
		return (true);
	else if (ft_isspace(data->map[i + 1][j]))
		return (true);
	else if (ft_isspace(data->map[i - 1][j]))
		return (true);
	return (false);
}

bool	find_walls(t_data *data, int i, int j)
{
	int	directions[4][2];
	int	wall;
	int	x;
	int	y;
	int	d;

	set_directions(directions);
	wall = 0;
	d = -1;
	while (++d < 4)
	{
		x = i;
		y = j;
		while (x >= 0 && y >= 0 && x < data->rows && data->map[x][y])
		{
			if (data->map[x][y] == '1')
			{
				wall++;
				break ;
			}
			x += directions[d][0];
			y += directions[d][1];
		}
	}
	return (wall == 4);
}

void	is_map_closed(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j] != '\n' && data->map[i][j])
		{
			if (ft_strchr(INSIDE_MAP, data->map[i][j]))
			{
				if (!find_walls(data, i, j) || next_to_space(data, i, j))
				{
					cleanup(data);
					exit_error("Map is not closed by walls");
				}
			}
			j++;
		}
		i++;
	}
}

void	check_map(t_data *data)
{
	char_check(data);
	is_map_closed(data);
}
