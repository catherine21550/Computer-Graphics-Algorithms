/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teesmaa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 11:31:57 by teesmaa           #+#    #+#             */
/*   Updated: 2025/02/25 15:14:34 by teesmaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	extra_commas_check(char *str, t_data *data)
{
	int	comma;

	comma = 0;
	while (*str)
	{
		if (*str == ',')
			comma++;
		str++;
	}
	if (comma > 2)
	{
		cleanup(data);
		exit_error("Invalid color value");
	}
}

bool	ft_isspace(char c)
{
	if ((c >= '\t' && c <= '\r') || c == ' ')
		return (true);
	return (false);
}

void	set_directions(int directions[4][2])
{
	directions[0][0] = -1;
	directions[0][1] = 0;
	directions[1][0] = 1;
	directions[1][1] = 0;
	directions[2][0] = 0;
	directions[2][1] = -1;
	directions[3][0] = 0;
	directions[3][1] = 1;
}

int	count_digits(char *str)
{
	int	count;

	count = 0;
	while (*str)
	{
		if (ft_isdigit(*str))
			count++;
		str++;
	}
	return (count);
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
		return (GROUND);
	if (ft_strnstr(str, "C", 1))
		return (CEILING);
	if (is_map(str))
		return (MAP);
	return (-1);
}
