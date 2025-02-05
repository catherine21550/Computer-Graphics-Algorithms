/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuk <khuk@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 09:49:45 by teesmaa           #+#    #+#             */
/*   Updated: 2025/02/04 22:21:26 by khuk             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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

void	handle_graphics(t_game *main)
{
	main->mlx_ptr = mlx_init();
	if (!main->mlx_ptr)
		return (cleanup(main->data), exit_error("mlx_init failed\n"));
	main->win_ptr = mlx_new_window(main->mlx_ptr, 1920, 1080, "Cub3D");
	if (!main->win_ptr)
		return (cleanup(main->data), exit_error("mlx_new_window failed\n"));
	mlx_loop(main->mlx_ptr);
}

int main(int argc, char **argv)
{
	t_data data;
	t_game	main;

	main.data = &data;
	check_arg(argc, argv[1]);
	save_data(argv[1], &data);
	parser(&data);
	print_data(&data);
	handle_graphics(&main);
	cleanup(&data);
	return (0);
}
