/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuk <khuk@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 13:42:19 by khuk              #+#    #+#             */
/*   Updated: 2024/08/25 14:16:04 by khuk             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	mouse_handling(int button, int x, int y, t_data *data)
{
	(void)x;
	(void)y;
	if (button == 4)
	{
		data->scale += 1;
		fdf_redraw_img(data, data->ac, data->av);
	}
	else if (button == 5)
	{
		data->scale -= 1;
		if (data->scale <= 0)
			data->scale = 1;
		fdf_redraw_img(data, data->ac, data->av);
	}
	return (0);
}

int	exit_function(t_data *data)
{
	mlx_loop_end (data->mlx_ptr);
	return (0);
}

int	key_function(int key, t_data *data)
{
	if (key == XK_Escape)
		mlx_loop_end (data->mlx_ptr);
	else if (key == XK_Left)
		ft_putstr_fd("Left", 1);
	else if (key == XK_Right)
		ft_putstr_fd("Right", 1);
	else if (key == XK_Return)
	{
		if (++data->color == 4)
			data->color = 0;
		fdf_redraw_img(data, data->ac, data->av);
	}
	return (0);
}

void	destroy_evrth(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->img.img_ptr);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
}

int	memalloc_coord(t_data *data, int ac, char *av[])
{
	if (!get_map(ac, av, &data->map, data) || !get_map(ac, av, &data->x, data)
	|| !get_map(ac, av, &data->y, data))
		return (0);
	return (1);
}

void	fdf_redraw_img(t_data *data, int ac, char *av[])
{
	solid_color(data, data->win_w, data->win_h);
	draw_img(data, ac, av);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.img_ptr, 0, 0);
}

int	main(int ac, char *av[])
{
	t_data	data;
	
	init_func(&data, ac, av);
	data.img.img_ptr = mlx_new_image(data.mlx_ptr, data.win_w, data.win_h);
	if (!data.img.img_ptr)
	{
		mlx_destroy_window(data.mlx_ptr, data.win_ptr);
		mlx_destroy_display(data.mlx_ptr);
		free(data.mlx_ptr);
		return (1);
	}
	data.img.ptr_imgbit = mlx_get_data_addr(data.img.img_ptr, &data.img.bits_per_pixel, &data.img.size_line, &data.img.endian);
	solid_color(&data, data.win_w, data.win_h);
	if (!memalloc_coord(&data, ac, av))
		return (destroy_evrth(&data), 1);
	draw_img(&data, ac, av);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img.img_ptr, 0, 0);
	mlx_mouse_hook(data.win_ptr, &mouse_handling, &data);
	mlx_hook(data.win_ptr, 17, (1L<<0), &exit_function, &data);
	mlx_hook(data.win_ptr, 2, (1L<<0), &key_function, &data);
	mlx_loop(data.mlx_ptr);
	destroy_evrth(&data);
	free_data(&data);
	return (0);
}
