/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triinueesmaa <triinueesmaa@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 09:49:45 by teesmaa           #+#    #+#             */
/*   Updated: 2025/02/03 12:11:18 by triinueesma      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
/* 
void	print_data(t_data *data)
{
	int	i;

	i = 0;
	while (data->map[i])
	{
		printf("%s", data->map[i]);
		i++;
	}
	printf("\n");
	printf("rows: %d\n", data->rows);
	printf("player's position: x: %d, y : %d\n", data->player_pos[0], data->player_pos[1]);
	printf("player's direction: %c\n", data->player_dir);
	printf("%s\n", data->no);
	printf("%s\n", data->so);
	printf("%s\n", data->we);
	printf("%s\n", data->ea);
	printf("%d\n", data->floor);
	printf("%d\n", data->ceiling);
}
 */
void exit_error(char *str)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(str, 2);
	exit (EXIT_FAILURE);
}

void check_arg(int argc, char *map)
{
	char    *format;

	if (argc != 2)
		exit_error("use one argument");
	format = ft_strnstr(map, ".cub", ft_strlen(map));
	if (!format || format[4] != '\0')
		exit_error("file format must be .cub");
}

void	cleanup(t_data *data)
{
	int	i;

	i = 0;
	while (data->content[i])
	{
		free(data->content[i]);
		i++;
	}
	if (data->content)
		free(data->content);
}

int main(int argc, char **argv)
{
	t_data data;

	check_arg(argc, argv[1]);
	save_data(argv[1], &data);
	parser(&data);
	//print_data(&data);
	cleanup(&data);
	return (0);
}
