/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checking_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teesmaa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:17:22 by teesmaa           #+#    #+#             */
/*   Updated: 2025/02/25 15:18:58 by teesmaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
			if (ft_strchr(DIRECTIONS, data->map[i][j]))
				count++;
			j++;
		}
		i++;
	}
	if (count != 1)
	{
		cleanup(data);
		exit_error("Map should contain one player");
	}
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
