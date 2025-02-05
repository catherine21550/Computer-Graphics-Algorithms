/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triinueesmaa <triinueesmaa@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:16:40 by teesmaa           #+#    #+#             */
/*   Updated: 2025/02/05 15:00:22 by triinueesma      ###   ########.fr       */
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
	if (ft_strnstr(str, "1", 1) ||
		ft_strnstr(str, "0", 1) ||
		(ft_strnstr(str, "N", 1) && !ft_strnstr (str, "NO", 2)) ||
		(ft_strnstr(str, "S", 1) && !ft_strnstr (str, "SO", 2)) ||
		(ft_strnstr(str, "E", 1) && !ft_strnstr (str, "EA", 2)) ||
		(ft_strnstr(str, "W", 1) && !ft_strnstr (str, "WE", 2)) )
		return (true);
	return (false);
}

int	information_type(char *str)
{
	while (ft_isspace(*str))
		str++;
	if (ft_strnstr(str, "NO", 2))
		return (NORTH);
	if (ft_strnstr(str, "SO", 2))
		return (SOUTH);
	if (ft_strnstr(str, "WE", 2))
		return (WEST);
	if (ft_strnstr(str, "EA", 2))
		return (EAST);
	if (ft_strnstr(str, "F", 1))
		return (FLOOR);
	if (ft_strnstr(str, "C", 1))
		return (CEILING);
	if (is_map(str))
		return (MAP);
	return (-1);
}

void	parse_input(t_data *data)
{
	int	i;

	i = 0;
	while (data->content[i])
	{
		if (information_type(data->content[i]) == NORTH)
			data->no = get_texture_path(data->content[i], "NO");
		else if (information_type(data->content[i]) == SOUTH)
			data->so = get_texture_path(data->content[i], "SO");
		else if (information_type(data->content[i]) == WEST)
			data->we = get_texture_path(data->content[i], "WE");
		else if (information_type(data->content[i]) == EAST)
			data->ea = get_texture_path(data->content[i], "EA");
		else if (information_type(data->content[i]) == FLOOR)
			data->floor = get_color(data->content[i], data, "F");
		else if (information_type(data->content[i]) == CEILING)
			data->ceiling = get_color(data->content[i], data, "C");
		else if (information_type(data->content[i]) == MAP)
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