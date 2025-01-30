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
		i++;
	}
}
