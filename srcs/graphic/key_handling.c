/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuk <khuk@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 13:12:24 by khuk              #+#    #+#             */
/*   Updated: 2025/02/24 17:23:18 by khuk             ###   ########.fr       */
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
	else if (key == W)
	{
		struct timeval t;

		gettimeofday(&t, NULL);
		data->scene->time = t.tv_sec + t.tv_usec;
		double move_speed = (data->scene->time - data->scene->old_time) / 1000 * 5.0;
		double tmp[2];
		tmp[0] = data->scene->player->x + data->scene->x_dir * move_speed;
		if (data->scene->coord[(int)data->scene->player->y][(int)tmp[0]].type == FLOOR
			|| data->scene->coord[(int)data->scene->player->y][(int)tmp[0]].type == PLAY)
			data->scene->d->x_map = tmp[0];
		tmp[1] = data->scene->player->y + data->scene->y_dir * move_speed;
		if (data->scene->coord[(int)tmp[1]][(int)data->scene->player->x].type == FLOOR
			|| data->scene->coord[(int)tmp[1]][(int)data->scene->player->x].type == PLAY)
			data->scene->d->y_map = tmp[1];
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
