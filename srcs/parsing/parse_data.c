/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triinueesmaa <triinueesmaa@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:16:40 by teesmaa           #+#    #+#             */
/*   Updated: 2025/02/03 13:06:18 by triinueesma      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void    is_one_player(t_data *data)
{
    int	i;
	int	j;
    int	count;

    i = 0;
	count = 0;
    while (data->map[i])
    {
		j = 0;
		while (data->map[i][j] != '\n' && data->map[i][j])
		{
			if (ft_strchr(DIRECTIONS, data->map[i][j]))
				count++;
			j++;
		}
		i++;
    }
	if (count != 1)
	{
		cleanup(data);
		exit_error("Wrong number of players");
	}
}

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
			if (ft_strchr(DIRECTIONS, data->map[i][j]))
			{
				data->player_dir = data->map[i][j];
				data->player_pos[0] = i;
				data->player_pos[1] = j;
				return ;
			}
			j++;
		}
	}
	cleanup(data);
	exit_error("No player found");
}

static void	count_rows(t_data *data)
{
	int	i;

	i = 0;
	while (data->map[i])
		i++;
	data->rows = i;
}

static bool	is_map(char *str)
{
	if (ft_strnstr(str, " ", 1) ||
		ft_strnstr(str, "1", 1) ||
		ft_strnstr(str, "0", 1) ||
		ft_strnstr(str, " ", 1) ||
		(ft_strnstr(str, "N", 1) && !ft_strnstr (str, "NO", 2)) ||
		(ft_strnstr(str, "S", 1) && !ft_strnstr (str, "SO", 2)) ||
		(ft_strnstr(str, "E", 1) && !ft_strnstr (str, "EA", 2)) ||
		(ft_strnstr(str, "W", 1) && !ft_strnstr (str, "WE", 2)) )
		return (true);
	return (false);
}

void	parse_input(t_data *data)
{
	int	i;

	i = 0;
	while (data->content[i])
	{
		if (ft_strnstr(data->content[i], "NO", 2))
			data->no = get_texture_path(data->content[i]);
		else if (ft_strnstr(data->content[i], "SO", 2))
			data->so = get_texture_path(data->content[i]);
		else if (ft_strnstr(data->content[i], "WE", 2))
			data->we = get_texture_path(data->content[i]);
		else if (ft_strnstr(data->content[i], "EA", 2))
			data->ea = get_texture_path(data->content[i]);
		else if (ft_strnstr(data->content[i], "F", 1))
			data->floor = get_color(data->content[i]);
		else if (ft_strnstr(data->content[i], "C", 1))
			data->ceiling = get_color(data->content[i]);
		else if (is_map(data->content[i]))
		{
			data->map = &data->content[i];
			break ;
		}
		i++;
	}
}

void	parser(t_data *data)
{
	parse_input(data);
	get_player_position(data);
    count_rows(data);
	check_map(data);
}