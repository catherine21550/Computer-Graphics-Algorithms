/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuk <khuk@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 13:42:19 by khuk              #+#    #+#             */
/*   Updated: 2024/08/22 00:26:49 by khuk             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	mouse_handling(int button, int x, int y, t_data *data)
{
	(void)x;
	(void)y;
	(void)data;
	if (button == 1)
		ft_printf("Left click\n");
	else
		ft_printf("Button %d was clicked\n", button);
	return (0);
}

int	exit_function(t_data *data)
{
	mlx_loop_end (data->mlx_ptr);
	return (0);
}

int	key_function(int key, t_data *data)
{
	ft_printf("The key %d is pressed\n", key);
	if (key == XK_Escape)
		mlx_loop_end (data->mlx_ptr);
	return (0);
}

void	destroy_evrth(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->img.img_ptr);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
}

int	init_funct(t_data *data, int ac, char *av[])
{
	if (ac < 2 || ac > 4)
		return (0);
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		return (0);
	if (ac == 2)
	{
		av[2] = "1200";
		av[3] = "1000";
	}
	if (ft_atoi(av[2]) < 100 || !str_isnum(av[2]))
		av[2] = "1200";
	if (ft_atoi(av[3]) < 100 || !str_isnum(av[3]))
		av[3] = "1000";
	data->win_w = ft_atoi(av[2]);
	data->win_h = ft_atoi(av[3]);
	data->win_ptr = mlx_new_window(data->mlx_ptr, ft_atoi(av[2]),
				ft_atoi(av[3]), "FdF");
	if (!data->win_ptr)
		return (free(data->mlx_ptr), 0);
	return (1);
}

int	main(int ac, char *av[])
{
	t_data	data;
	
	if (!init_funct(&data, ac, av))
		return (1);
	mlx_mouse_hook(data.win_ptr, &mouse_handling, &data);
	data.img.img_ptr = mlx_new_image(data.mlx_ptr, data.win_w, data.win_h);
	data.img.ptr_imgbit = mlx_get_data_addr(data.img.img_ptr, &data.img.bits_per_pixel, &data.img.size_line, &data.img.endian);
	solid_color(&data, data.win_w, data.win_h);
	if (!make_dots(&data, ac, av))
		return (destroy_evrth(&data), 1);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img.img_ptr, 0, 0);
	mlx_hook(data.win_ptr, 17, (1L<<0), &exit_function, &data);
	mlx_hook(data.win_ptr, 2, (1L<<0), &key_function, &data);
	mlx_loop(data.mlx_ptr);
	destroy_evrth(&data);
	free_data(&data);
	return (0);
}
