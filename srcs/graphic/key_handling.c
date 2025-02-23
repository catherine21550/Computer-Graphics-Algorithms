/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuk <khuk@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 13:12:24 by khuk              #+#    #+#             */
/*   Updated: 2025/02/23 22:20:19 by khuk             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphic.h"

void	rotate_camera(t_game *main, double angle)
{
	printf("Angle is: %f\n", angle);//temp
	main->scene->radians = main->scene->angle * (CUB_PI / 180.0);
	main->scene->x_dir = cos(main->scene->radians);
	main->scene->y_dir = sin(main->scene->radians);
	main->scene->x_plane = -main->scene->plane_length
		* sin(main->scene->radians);
	main->scene->y_plane = main->scene->plane_length
		* cos(main->scene->radians);
	rendering_process(main);
	mlx_put_image_to_window(main->mlx_ptr, main->win_ptr,
		main->img.img_ptr, 0, 0);
}

int	key_function(int key, t_game *data)
{
	if (key == ESC)
		mlx_loop_end (data->mlx_ptr);
	else if (key == LEFT)
	{
		data->scene->angle -= 1;
		if (data->scene->angle < 0)
			data->scene->angle = 360;
		rotate_camera(data, data->scene->angle);
	}
	else if (key == RIGHT)
	{
		data->scene->angle += 1;
		if (data->scene->angle > 360)
			data->scene->angle = 0;
		rotate_camera(data, data->scene->angle);
	}
	else
		printf("Key: %d is pressed\n", key);
	return (0);
}

int	mouse_move_function(int x, int y, void *param)
{
	(void)param;
	printf("Mouse moved to (%d, %d)\n", x, y);//temp
	return (0);
}

int	exit_function(t_game *data)
{
	if (!data)
		printf("No main data\n");
	if (!data->mlx_ptr)
		printf("No mlx_ptr\n");
	mlx_loop_end (data->mlx_ptr);
	return (0);
}
