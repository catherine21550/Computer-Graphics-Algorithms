/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teesmaa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 11:31:37 by teesmaa           #+#    #+#             */
/*   Updated: 2025/02/25 14:36:06 by teesmaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	get_player_position(t_data *data)
{
	int		i;
	int		j;

	is_one_player(data);
	i = 0;
	while (data->map[i++])
	{
		j = 0;
		while (data->map[i][j] != '\n' && data->map[i][j])
		{
			if (ft_strchr("NEWS", data->map[i][j]))
			{
				data->player_dir = data->map[i][j];
				data->player_pos[0] = i;
				data->player_pos[1] = j;
				return ;
			}
			j++;
		}
	}
}

void	parse_input(t_data *data)
{
	int	i;

	i = 0;
	while (data->content[i])
	{
		if (information_type(data->content[i]) == NORTH)
			data->no = get_texture_path(data->content[i], "NO", data, data->no);
		else if (information_type(data->content[i]) == SOUTH)
			data->so = get_texture_path(data->content[i], "SO", data, data->so);
		else if (information_type(data->content[i]) == WEST)
			data->we = get_texture_path(data->content[i], "WE", data, data->we);
		else if (information_type(data->content[i]) == EAST)
			data->ea = get_texture_path(data->content[i], "EA", data, data->ea);
		else if (information_type(data->content[i]) == GROUND)
			data->floor = get_color(data->content[i], data, "F", data->floor);
		else if (information_type(data->content[i]) == CEILING)
			data->ceiling = get_color(data->content[i], data,
					"C", data->ceiling);
		else if (information_type(data->content[i]) == MAP)
		{
			data->map = &data->content[i];
			break ;
		}
		i++;
	}
}

static void	count_rows(t_data *data)
{
	int	i;

	i = 0;
	while (data->map[i])
		i++;
	data->rows = i;
}

void	parser(t_data *data)
{
	parse_input(data);
	if (!data->no || !data->so || !data->we || !data->ea
		|| !data->map || data->floor == -1 || data->ceiling == -1)
	{
		cleanup(data);
		exit_error("Missing data");
	}
	count_rows(data);
	check_map(data);
	get_player_position(data);
}
