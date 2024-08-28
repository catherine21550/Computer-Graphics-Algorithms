/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuk <khuk@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 01:52:19 by khuk              #+#    #+#             */
/*   Updated: 2024/08/25 13:35:46 by khuk             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	input_check(int ac, char *av[])
{
	if (ac < 2 || ac > 4 || ac == 3)
	{
		ft_putstr_fd("Error: wrong number of arguments\n", 2);
		ft_putstr_fd("./fdf <map.fdf> <window width> <window height>\n", 2);
		exit (1);
	}
	if (ac == 2)
	{
		av[2] = "1200";
		av[3] = "1000";
	}
	if (!str_isnum(av[2]) || !str_isnum(av[3]))
	{
		ft_putstr_fd("Error: invalid parameters\n", 2);
		ft_putstr_fd("./fdf <map.fdf> <window width> <window height>\n", 2);
		exit (1);
	}
	if (ft_atoi(av[2]) < 50 || ft_atoi(av[3]) < 50
		|| ft_atoi(av[2]) > 1920 || ft_atoi(av[3]) > 1080)
	{
		ft_putstr_fd("Error: The window needs to be larger!\n", 2);
		exit (1);
	}
}

void	init_func(t_data *data, int ac, char *av[])
{
	input_check(ac, av);
	data->win_w = ft_atoi(av[2]);
	data->win_h = ft_atoi(av[3]);
	data->scale = 15;
	data->mlx_ptr = mlx_init();
	data->color = 0;
	data->color_pic = 0;
	data->ang = 145;
	if (!data->mlx_ptr)
		exit (1);
	data->win_ptr = mlx_new_window(data->mlx_ptr, ft_atoi(av[2]),
			ft_atoi(av[3]), "FdF");
	if (!data->win_ptr)
	{
		free(data->mlx_ptr);
		exit (1);
	}
	data->ac = ac;
	data->av = av;
}
