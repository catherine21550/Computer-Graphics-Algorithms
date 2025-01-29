/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teesmaa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 09:49:45 by teesmaa           #+#    #+#             */
/*   Updated: 2025/01/29 09:55:28 by teesmaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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
	int i = 0;
	while (data.content[i])
	{
		printf("%s\n", data.content[i]);
		i++;
	}
	cleanup(&data);
	return (0);
}
