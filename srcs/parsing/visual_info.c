/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teesmaa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 11:32:17 by teesmaa           #+#    #+#             */
/*   Updated: 2025/02/25 15:12:38 by teesmaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*get_texture_path(char *str, char *type, t_data *data, char *path)
{
	int		i;
	char	*format;

	if (path)
	{
		cleanup(data);
		exit_error("More than one file per direction");
	}
	str += start_index(str, type);
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			str[i] = '\0';
		i++;
	}
	format = ft_strnstr(str, ".xpm", ft_strlen(str));
	if (!format || format[4] != '\0')
	{
		cleanup(data);
		exit_error("Texture file must be .xpm");
	}
	return (str);
}

static int	rgb_to_int(char **rgb, t_data *data)
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

void	digits_check(char **rgb, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (rgb[i])
	{
		j = 0;
		while (rgb[i][j] != '\n' && rgb[i][j] != '\0')
		{
			if ((!ft_isdigit(rgb[i][j]) && !ft_isspace(rgb[i][j])))
			{
				free_array(rgb);
				cleanup(data);
				exit_error("Invalid color value");
			}
			j++;
		}
		i++;
	}
}

static void	color_check(char **rgb, t_data *data)
{
	int	i;
	int	digits;

	i = 0;
	while (rgb[i])
	{
		digits_check(rgb, data);
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

int	get_color(char *str, t_data *data, char *type, int oldcolor)
{
	int		color;
	char	**rgb;

	if (oldcolor != -1)
	{
		cleanup(data);
		exit_error("More than one color per surface");
	}
	color = 0;
	extra_commas_check(str, data);
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
