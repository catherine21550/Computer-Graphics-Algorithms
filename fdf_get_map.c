/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_get_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuk <khuk@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 21:29:54 by khuk              #+#    #+#             */
/*   Updated: 2024/08/15 20:27:36 by khuk             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	create_struct(int ac, char *av[], t_map *my_map)
{
	long	i[2];

	my_map->strlen = 0;
	my_map->arrlen = lines_number(ac, av, &my_map->strlen);
	my_map->map = ft_calloc(sizeof(int *), (my_map->arrlen + 1));
	if (!my_map->map)
		return (0);
	i[0] = -1;
	while (++i[0] < my_map->arrlen)
	{
		my_map->map[i[0]] = ft_calloc(sizeof(int), my_map->strlen);
		if (!my_map->map[i[0]])
			return (0);
	}
	my_map->map[my_map->arrlen] = NULL;
	return (1);
}

int	get_map(int ac, char *av[], t_map *map)
{
	char	*line;
	char	**str_arr;
	int		i[3];

	if (!create_struct(ac, av, map))
		return (free_map(map), 0);
	i[0] = open(av[1], O_RDONLY);
	if (i[0] <= 0)
		return (free_map(map), 0);
	i[1] = -1;
	while (++i[1] < map->arrlen)
	{
		i[2] = -1;
		line = get_next_line(i[0]);
		if (!line)
			return (free_map(map), cl_gnl(i[0]), close(i[0]), 0);
		str_arr = ft_split(line, ' ');
		if (!str_arr)
			return (free_map(map), free(line), cl_gnl(i[0]), close(i[0]), 0);
		while (++i[2] < map->strlen)
			map->map[i[1]][i[2]] = ft_atoi(str_arr[i[2]]);
		free_split(str_arr);
		free(line);
	}
	return (cl_gnl(i[0]) , close(i[0]), 1);
}

/* int	main(int ac, char *av[])
{
	t_map	map;

	if (!get_map(ac, av, &map))
		return (1);
	for(int i = 0; i < map.arrlen; i++)
	{
		for(int j = 0; j < map.strlen; j++)
			ft_printf("%d ", map.map[i][j]);
		ft_printf("\n");
	}
	free_map(&map);
	return (0);
} */
/*
int	main(int ac, char *av[])
{
	t_map	map;
	char	*line;
	char	**str_arr;
	int		i[3];

	if (!create_struct(ac, av, &map))
		return (1);
	i[0] = open(av[1], O_RDONLY);
	i[1] = 0;
	ft_printf("Map len = %d\n", map.arrlen);
	ft_printf("str len = %d\n", map.strlen);
	while (i[1] < map.arrlen)
	{
		ft_printf("Current line num = %d\n", i[1]);
		i[2] = -1;
		line = get_next_line(i[0]);
		ft_printf("Current line = %s\n", line);
		str_arr = ft_split(line, ' ');
		int j = 0;
		while (str_arr[j])
		{
			j++;
		}
		ft_printf("Current split size = %d\n", j);
		while (++i[2] < map.strlen){
			map.map[i[1]][i[2]] = ft_atoi(str_arr[i[2]]);
			ft_printf("%d  ", map.map[i[1]][i[2]]);
			}
		ft_printf("\n");
		free_split(str_arr);//something wrong with free!!!
		free(line);
		i[1]++;
	}
	for(int i = 0; i < map.arrlen; i++)
	{
		for(int j = 0; j < map.strlen; j++)
			ft_printf("%d ", map.map[i][j]);
		ft_printf("\n");
	}
	close(i[0]);
	return (0);
}
*/
