/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teesmaa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:16:40 by teesmaa           #+#    #+#             */
/*   Updated: 2025/01/30 12:36:12 by teesmaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/cub3d.h"

char	*get_texture_path(char *str)
{
	int	i = 0;

	str += 2;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	while (str[i++])
		if (str[i] == '\n')
			str[i] = '\0';
	return (str);
}

int rgb_to_int(char **rgb)
{
	int	r;
	int	g;
	int	b;

	r = ft_atoi(rgb[0]);
	g = ft_atoi(rgb[1]);
	b = ft_atoi(rgb[2]);
	return ((r << 16) | (g << 8) | b);
}

static int	get_color(char *str)
{
	int		color;
	char 	**rgb;
	int		i;

	color = 0;
	str++;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	rgb = ft_split(str, ',');
	color = rgb_to_int(rgb);
	i = 0;
	while (rgb[i])
		free(rgb[i++]);
	free(rgb);
	return (color);
}
bool	is_map(char *str)
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

void	get_player_location(t_data *data)
{
	int		i;
	int		j;
	bool	found;

	found = false;
	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j] != '\n' && data->map[i][j])
		{
			if (data->map[i][j] == 'N' || data->map[i][j] == 'S'
				|| data->map[i][j] == 'W' || data->map[i][j] == 'E')
			{
				data->player_dir = data->map[i][j];
				data->player_pos[0] = i;
				data->player_pos[1] = j;
				found = true;
			}
			j++;
		}
		i++;
	}
	if (!found)
		exit_error("No player found");
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
	get_player_location(data);
}

void	parser(t_data *data)
{
	parse_input(data);
	printf("player is at row: %d column: %d, direction: %c", data->player_pos[0], data->player_pos[1], data->player_dir);
	//TO DO:
	//check_map(data);
}