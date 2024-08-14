/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_get_map->c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuk <khuk@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 21:29:54 by khuk              #+#    #+#             */
/*   Updated: 2024/08/14 21:29:58 by khuk             ###   ########.fr       */
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
		{
			i[1] = -1;
			while (++i[1] < my_map->arrlen)
				free(my_map->map[i[1]]);
			return (free(my_map->map), 0);
		}
	}
	my_map->map[my_map->arrlen] = NULL;
	return (1);
}

/* static void	free_split(char **arr)
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
} */

t_map	*get_map(int ac, char *av[])
{
	t_map	*map;
	char	*line;
	char	**str_arr;
	int		i[3];

	map = NULL;
	if (!create_struct(ac, av, map))
		return (NULL);
	i[0] = open(av[1], O_RDONLY);
	i[1] = 0;
	while (i[1] < map->arrlen)
	{
		i[2] = -1;
		line = get_next_line(i[0]);
		str_arr = ft_split(line, ' ');
		while (++i[2] < map->strlen)
			map->map[i[1]][i[2]] = ft_atoi(str_arr[i[2]]);
		//free_split(str_arr);//something wrong with free!!!
		free(line);
		i[1]++;
	}
	close(i[0]);
	return (map);
}

int	main(int ac, char *av[])
{
	t_map	*map;

	map = get_map(ac, av);
	if(!map)
		return (1);
	for(int i = 0; i < map->arrlen; i++)
	{
		for(int j = 0; j < map->strlen; j++)
			ft_printf("%d ", map->map[i][j]);
		ft_printf("\n");
	}
	return (0);
}
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
	while (i[1] < map->arrlen)
	{
		i[2] = -1;
		line = get_next_line(i[0]);
		str_arr = ft_split(line, ' ');
		while (++i[2] < map->strlen)
			map->map[i[1]][i[2]] = ft_atoi(str_arr[i[2]]);
		free_split(str_arr);//something wrong with free!!!
		free(line);
		i[1]++;
	}
	close(i[0]);
	return (0);
} */
