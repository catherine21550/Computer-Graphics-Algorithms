/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuk <khuk@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 09:49:45 by teesmaa           #+#    #+#             */
/*   Updated: 2025/03/05 14:21:03 by khuk             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	check_arg(int argc, char *map)
{
	char	*format;

	if (argc != 2)
		exit_error("use one argument");
	format = ft_strnstr(map, ".cub", ft_strlen(map));
	if (!format || format[4] != '\0')
		exit_error("file format must be .cub");
}

int	main(int argc, char **argv)
{
	t_game	main;
	t_data	data;

	ft_bzero(&main, sizeof(t_game));
	main.data = &data;
	check_arg(argc, argv[1]);
	save_data(argv[1], main.data);
	parser(main.data);
	if (!handle_graphics(&main))
		return (1);
	return (0);
}
