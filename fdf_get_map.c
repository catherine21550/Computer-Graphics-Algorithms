/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_get_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuk <khuk@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 18:59:03 by khuk              #+#    #+#             */
/*   Updated: 2024/08/13 19:11:39 by khuk             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	create_struct(int ac, char *av[])
{
	t_map	my_map;
	size_t	i[3];

	my_map.strlen = 0;
	i[0] = lines_number(ac, av, &my_map.strlen);
	ft_printf("1: %d, 2: %d\n", my_map.strlen, i[0]);// temp
	my_map.map = ft_calloc(sizeof(int *), (i[0] + 1));
	if (!my_map.map)
		return (0);
	i[1] = -1;
	while (++i[1] < i[0])
	{
		my_map.map[i[1]] = ft_calloc(sizeof(int), my_map.strlen);
		if (!my_map.map[i[1]])
		{
			i[2] = -1;
			while (++i[2] < i[1])
				free(my_map.map[i[2]]);
			return (free(my_map.map), 0);
		}
	}
	my_map.map[i[0]] = NULL;
	return (1);
}

int	main(int ac, char *av[])
{
	create_struct(ac, av);
	return (0);
}
