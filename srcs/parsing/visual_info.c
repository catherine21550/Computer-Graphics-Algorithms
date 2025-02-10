/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teesmaa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 11:32:17 by teesmaa           #+#    #+#             */
/*   Updated: 2025/02/10 11:32:22 by teesmaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	start_index(char *str, char *type)
{
	int i;
	int	len;

	len = ft_strlen(type);
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (ft_strncmp(type, str + i, len) == 0)
		i += len;
	while (ft_isspace(str[i]))
		i++;
	return (i);
}

char	*get_texture_path(char *str, char *type)
{
	int	i;

	str += start_index(str, type);
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			str[i] = '\0';
		i++;
	}
	return (str);
}

static int rgb_to_int(char **rgb, t_data *data)
{
	int	r;
	int	g;
	int	b;

	r = ft_atoi(rgb[0]);
	g = ft_atoi(rgb[1]);
	b = ft_atoi(rgb[2]);
	if (r < 0 || r > 255 || g < 0 
		|| g > 255 || b < 0 || b > 255)
	{
		free_array(rgb);
		cleanup(data);
		exit_error("Invalid color value");
	}
	return ((r << 16) | (g << 8) | b);
}

static void	color_check(char **rgb, t_data *data)
{
	int	i;
	int	digits;

	i = 0;
	while (rgb[i])
	{
		digits = count_digits(rgb[i]);
		if (i > 2 || digits < 1 || digits > 3)
		{
			free_array(rgb);
			cleanup(data);
			exit_error("Invalid color value");
		}
		i++;
	}
	if (i < 3)
	{
		free_array(rgb);
		cleanup(data);
		exit_error("Invalid color value");
	}
}

int	get_color(char *str, t_data *data, char *type)
{
	int		color;
	char 	**rgb;

	color = 0;
	str += start_index(str, type);
	rgb = ft_split(str, ',');
	if (!rgb)
	{
		cleanup(data);
		exit_error("ft_split() failed");
	}
	color_check(rgb, data);
	color = rgb_to_int(rgb, data);
	free_array(rgb);
	return (color);
}
