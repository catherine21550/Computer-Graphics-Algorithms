/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_mem_clean.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuk <khuk@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 14:48:17 by khuk              #+#    #+#             */
/*   Updated: 2024/08/15 20:28:42 by khuk             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_split(char **arr)
{
	int	j;

	j = 0;
	if (arr == NULL)
		return ;
	while (arr[j])
	{
		free (arr[j]);
		j++;
	}
	free(arr);
}

void	free_map(t_map *map)
{
	long	i;

	if (map == NULL)
		return ;
	if (map->map == NULL)
		return ;
	i = 0;
	while (map->map[i])
	{
		free(map->map[i]);
		i++;
	}
	free(map->map);
}

void	cl_gnl(int fd)
{
	char	*tmp;

	tmp = get_next_line(fd);
	free (tmp);
	while (tmp != NULL)
	{
		tmp = get_next_line(fd);
		free (tmp);
	}
}
