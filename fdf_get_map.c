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
	size_t	i[2];

	i[0] = 0;
	i[1] = lines_number(ac, av, &i[0]);
	ft_printf("1: %d, 2: %d\n", i[0], i[1]);
	return (0);
}

int	main(int ac, char *av[])
{
	create_struct(ac, av);
	return (0);
}
