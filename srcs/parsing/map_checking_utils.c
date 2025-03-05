/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checking_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teesmaa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:17:22 by teesmaa           #+#    #+#             */
/*   Updated: 2025/02/28 15:50:27 by teesmaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	number_of_spaces(char *str)
{
	int	tab;

	tab = 0;
	while (*str)
	{
		if (*str == '\t')
			tab++;
		str++;
	}
	return (tab * 4);
}

char	*tab_to_spaces(char *str, t_data *data)
{
	char	*new;
	int		i;
	int		j;

	new = malloc(sizeof(char) * (ft_strlen(str) + number_of_spaces(str) + 1));
	if (!new)
		clean_exit(data, "malloc() failed");
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '\t')
		{
			new[j++] = ' ';
			new[j++] = ' ';
			new[j++] = ' ';
			new[j++] = ' ';
		}
		else
			new[j++] = str[i];
		i++;
	}
	free(str);
	return (new);
}

void	is_one_player(t_data *data)
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
			if (ft_strchr("NEWS", data->map[i][j]))
				count++;
			j++;
		}
		i++;
	}
	if (count != 1)
		clean_exit(data, "Map should contain one player");
}

bool	is_map(char *str)
{
	if (ft_strnstr(str, "1", 1)
		|| ft_strnstr(str, "0", 1)
		|| (ft_strnstr(str, "N", 1) && !ft_strnstr (str, "NO", 2))
		|| (ft_strnstr(str, "S", 1) && !ft_strnstr (str, "SO", 2))
		|| (ft_strnstr(str, "E", 1) && !ft_strnstr (str, "EA", 2))
		|| (ft_strnstr(str, "W", 1) && !ft_strnstr (str, "WE", 2)))
		return (true);
	return (false);
}

int	start_index(char *str, char *type)
{
	int	i;
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
