/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuk <khuk@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 13:12:24 by khuk              #+#    #+#             */
/*   Updated: 2025/02/18 22:31:07 by khuk             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphic.h"

void rotate_camera(t_game *main, double angle)
{
	printf("Angle is: %f\n", angle);
	main->scene->x_dir = cos(main->scene->angle * (CUB_PI / 180));
	main->scene->y_dir = sin(main->scene->angle * (CUB_PI / 180));
/* 	main->scene->x_plane = -main->scene->plane_lenght * sin(main->scene->angle * (CUB_PI / 180));
	main->scene->y_plane = main->scene->plane_lenght * cos(main->scene->angle * (CUB_PI / 180));
	double old_dir_x = main->scene->x_dir;
	main->scene->x_dir = old_dir_x  * cos(main->scene->angle * CUB_PI / 180) - main->scene->y_dir * sin(main->scene->angle * CUB_PI / 180);
	main->scene->y_dir = old_dir_x * sin(main->scene->angle * CUB_PI / 180) + main->scene->y_dir * cos(main->scene->angle * CUB_PI / 180); */
	double old_plane_x = main->scene->x_plane;
	main->scene->x_plane = old_plane_x * cos(main->scene->angle * CUB_PI / 180) - main->scene->y_plane * sin(main->scene->angle * CUB_PI / 180);
	main->scene->y_plane = old_plane_x * sin(main->scene->angle * CUB_PI / 180) + main->scene->y_plane * cos(main->scene->angle * CUB_PI / 180);

	draw_img(main);
	mlx_put_image_to_window(main->mlx_ptr, main->win_ptr, main->img.img_ptr, 0, 0);
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

int mouse_move_function(int x, int y, void *param)
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
