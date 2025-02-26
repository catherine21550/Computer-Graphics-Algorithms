/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuk <khuk@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 13:12:24 by khuk              #+#    #+#             */
/*   Updated: 2025/02/26 02:26:47 by khuk             ###   ########.fr       */
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
		data->scene->angle -= 1.5;
		if (data->scene->angle < 0)
			data->scene->angle = 360;
		rotate_camera(data, data->scene->angle);
	}
	else if (key == RIGHT)
	{
		data->scene->angle += 1.5;
		if (data->scene->angle > 360)
			data->scene->angle = 0;
		rotate_camera(data, data->scene->angle);
	}
	else if (key == W)
	{
		struct timeval t;
		double tmp[3];
		double move_speed;

		data->scene->old_time = data->scene->time;
		gettimeofday(&t, NULL);
		data->scene->time = t.tv_sec + (t.tv_usec / 1000000.0);
		tmp[2] = (data->scene->time - data->scene->old_time);
		if (tmp[2] > 0.1 || tmp[2] <= 0)
			tmp[2] = 0.1;
		move_speed = tmp[2] * 1.5;
		tmp[0] = data->scene->d.x_pos + data->scene->x_dir * move_speed;
		if ((int)tmp[0] < (int)data->scene->x_size && (int)tmp[0] >= 0
			&& data->scene->x_size && (data->scene->coord[(int)data->scene->d.y_pos][(int)tmp[0]].type == FLOOR
			|| data->scene->coord[(int)data->scene->d.y_pos][(int)tmp[0]].type == PLAY))
			data->scene->d.x_pos = tmp[0];
		tmp[1] = data->scene->d.y_pos + data->scene->y_dir * move_speed;
		if ((int)tmp[1] < (int)data->scene->y_size && (int)tmp[1] >= 0
			&& (data->scene->coord[(int)tmp[1]][(int)data->scene->d.x_pos].type == FLOOR
			|| data->scene->coord[(int)tmp[1]][(int)data->scene->d.x_pos].type == PLAY))
			data->scene->d.y_pos = tmp[1];
		rendering_process(data);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img.img_ptr, 0, 0);
	}
	else if (key == S)
	{
		struct timeval t;
		double tmp[3];
		double move_speed;

		data->scene->old_time = data->scene->time;
		gettimeofday(&t, NULL);
		data->scene->time = t.tv_sec + (t.tv_usec / 1000000.0);
		tmp[2] = (data->scene->time - data->scene->old_time);
		if (tmp[2] > 0.1 || tmp[2] <= 0)
			tmp[2] = 0.1;
		move_speed = tmp[2] * 1.5;
		tmp[0] = data->scene->d.x_pos - data->scene->x_dir * move_speed;
		if ((int)tmp[0] < (int)data->scene->x_size && (int)tmp[0] >= 0
			&& data->scene->x_size && (data->scene->coord[(int)data->scene->d.y_pos][(int)tmp[0]].type == FLOOR
			|| data->scene->coord[(int)data->scene->d.y_pos][(int)tmp[0]].type == PLAY))
			data->scene->d.x_pos = tmp[0];
		tmp[1] = data->scene->d.y_pos - data->scene->y_dir * move_speed;
		if ((int)tmp[1] < (int)data->scene->y_size && (int)tmp[1] >= 0
			&& (data->scene->coord[(int)tmp[1]][(int)data->scene->d.x_pos].type == FLOOR
			|| data->scene->coord[(int)tmp[1]][(int)data->scene->d.x_pos].type == PLAY))
			data->scene->d.y_pos = tmp[1];
		rendering_process(data);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img.img_ptr, 0, 0);
	}
	else if (key == A)
	{
		struct timeval t;
		double tmp[3];
		double move_speed;

		data->scene->old_time = data->scene->time;
		gettimeofday(&t, NULL);
		data->scene->time = t.tv_sec + (t.tv_usec / 1000000.0);
		tmp[2] = (data->scene->time - data->scene->old_time);
		if (tmp[2] > 0.1 || tmp[2] <= 0)
			tmp[2] = 0.1;
		move_speed = tmp[2] * 1.5;
		tmp[0] = data->scene->d.x_pos - data->scene->x_plane * move_speed;
		if ((int)tmp[0] < (int)data->scene->x_size && (int)tmp[0] >= 0
			&& data->scene->x_size && (data->scene->coord[(int)data->scene->d.y_pos][(int)tmp[0]].type == FLOOR
			|| data->scene->coord[(int)data->scene->d.y_pos][(int)tmp[0]].type == PLAY))
			data->scene->d.x_pos = tmp[0];
		tmp[1] = data->scene->d.y_pos - data->scene->y_plane * move_speed;
		if ((int)tmp[1] < (int)data->scene->y_size && (int)tmp[1] >= 0
			&& (data->scene->coord[(int)tmp[1]][(int)data->scene->d.x_pos].type == FLOOR
			|| data->scene->coord[(int)tmp[1]][(int)data->scene->d.x_pos].type == PLAY))
			data->scene->d.y_pos = tmp[1];
		rendering_process(data);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img.img_ptr, 0, 0);
	}
	else if (key == D)
	{
		struct timeval t;
		double tmp[3];
		double move_speed;

		data->scene->old_time = data->scene->time;
		gettimeofday(&t, NULL);
		data->scene->time = t.tv_sec + (t.tv_usec / 1000000.0);
		tmp[2] = (data->scene->time - data->scene->old_time);
		if (tmp[2] > 0.1 || tmp[2] <= 0)
			tmp[2] = 0.1;
		move_speed = tmp[2] * 1.5;
		tmp[0] = data->scene->d.x_pos + data->scene->x_plane * move_speed;
		if ((int)tmp[0] < (int)data->scene->x_size && (int)tmp[0] >= 0
			&& data->scene->x_size && (data->scene->coord[(int)data->scene->d.y_pos][(int)tmp[0]].type == FLOOR
			|| data->scene->coord[(int)data->scene->d.y_pos][(int)tmp[0]].type == PLAY))
			data->scene->d.x_pos = tmp[0];
		tmp[1] = data->scene->d.y_pos + data->scene->y_plane * move_speed;
		if ((int)tmp[1] < (int)data->scene->y_size && (int)tmp[1] >= 0
			&& (data->scene->coord[(int)tmp[1]][(int)data->scene->d.x_pos].type == FLOOR
			|| data->scene->coord[(int)tmp[1]][(int)data->scene->d.x_pos].type == PLAY))
			data->scene->d.y_pos = tmp[1];
		rendering_process(data);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img.img_ptr, 0, 0);
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
