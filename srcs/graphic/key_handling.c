/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuk <khuk@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 13:12:24 by khuk              #+#    #+#             */
/*   Updated: 2025/02/26 14:46:04 by khuk             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphic.h"

void	rotate_camera(t_game *main)
{
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

void	position_calculation(t_scene *scene, int key)
{
	double	tmp[5];

	tmp[0] = scene->x_plane;
	tmp[1] = scene->y_plane;
	if (key == W || key == S)
	{
		tmp[0] = scene->x_dir;
		tmp[1] = scene->y_dir;
	}
	tmp[4] = -1.0;
	if (key == W || key == D)
		tmp[4] = 1.0;
	tmp[2] = scene->d.x_pos + tmp[4] * tmp[0] * scene->move_speed;
	if ((int)tmp[2] < (int)scene->x_size && (int)tmp[2] >= 0
		&& (scene->coord[(int)scene->d.y_pos][(int)tmp[2]].type == FLOOR
		|| scene->coord[(int)scene->d.y_pos][(int)tmp[2]].type == PLAY))
		scene->d.x_pos = tmp[2];
	tmp[3] = scene->d.y_pos + tmp[4] * tmp[1] * scene->move_speed;
	if ((int)tmp[3] < (int)scene->y_size && (int)tmp[3] >= 0
		&& (scene->coord[(int)tmp[3]][(int)scene->d.x_pos].type == FLOOR
		|| scene->coord[(int)tmp[3]][(int)scene->d.x_pos].type == PLAY))
		scene->d.y_pos = tmp[3];
}

void	move_handling(t_game *data, int key)
{
	struct timeval	t;
	double			delta_time;

	data->scene->old_time = data->scene->time;
	gettimeofday(&t, NULL);
	data->scene->time = t.tv_sec + (t.tv_usec / 1000000.0);
	delta_time = (data->scene->time - data->scene->old_time);
	if (delta_time > 0.1 || delta_time <= 0)
		delta_time = 0.1;
	data->scene->move_speed = delta_time * 1.5;
	position_calculation(data->scene, key);
	rendering_process(data);
/* 	if (data->scene->player->x != data->scene->d.x_map
		|| data->scene->player->y != data->scene->d.y_map)
	{
		data->scene->player->type = FLOOR;
		data->scene->player = &data->scene->coord[(int)data->scene->d.y_map] \
		[(int)data->scene->d.x_map];
		data->scene->player->type = PLAY;
	} */
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img.img_ptr, 0, 0);
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
		rotate_camera(data);
	}
	else if (key == RIGHT)
	{
		data->scene->angle += 1.5;
		if (data->scene->angle > 360)
			data->scene->angle = 0;
		rotate_camera(data);
	}
	else if (key == W || key == S || key == A || key == D)
		move_handling(data, key);
	else
		printf("Key: %d is pressed\n", key);
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

/*
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
		tmp[2] = data->scene->d.x_pos + data->scene->x_dir * move_speed;
		if ((int)tmp[2] < (int)data->scene->x_size && (int)tmp[2] >= 0
			&& (data->scene->coord[(int)data->scene->d.y_pos] \
			[(int)tmp[2]].type == FLOOR
			|| data->scene->coord[(int)data->scene->d.y_pos] \
			[(int)tmp[2]].type == PLAY))
			data->scene->d.x_pos = tmp[2];
		tmp[3] = data->scene->d.y_pos + data->scene->y_dir * move_speed;
		if ((int)tmp[3] < (int)data->scene->y_size && (int)tmp[3] >= 0
			&& (data->scene->coord[(int)tmp[3]] \
			[(int)data->scene->d.x_pos].type == FLOOR
			|| data->scene->coord[(int)tmp[3]] \
			[(int)data->scene->d.x_pos].type == PLAY))
			data->scene->d.y_pos = tmp[3];
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
		tmp[2] = data->scene->d.x_pos - data->scene->x_dir * move_speed;
		if ((int)tmp[2] < (int)data->scene->x_size && (int)tmp[2] >= 0
			&& (data->scene->coord[(int)data->scene->d.y_pos] \ 
			[(int)tmp[2]].type == FLOOR
			|| data->scene->coord[(int)data->scene->d.y_pos] \ 
			[(int)tmp[2]].type == PLAY))
			data->scene->d.x_pos = tmp[2];
		tmp[3] = data->scene->d.y_pos - data->scene->y_dir * move_speed;
		if ((int)tmp[3] < (int)data->scene->y_size && (int)tmp[3] >= 0
			&& (data->scene->coord[(int)tmp[3]] \ 
			[(int)data->scene->d.x_pos].type == FLOOR
			|| data->scene->coord[(int)tmp[3]] \ 
			[(int)data->scene->d.x_pos].type == PLAY))
			data->scene->d.y_pos = tmp[3];
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
		tmp[2] = data->scene->d.x_pos - data->scene->x_plane * move_speed;
		if ((int)tmp[2] < (int)data->scene->x_size && (int)tmp[2] >= 0
			&& (data->scene->coord[(int)data->scene->d.y_pos] \ 
			[(int)tmp[2]].type == FLOOR
			|| data->scene->coord[(int)data->scene->d.y_pos] \ 
			[(int)tmp[2]].type == PLAY))
			data->scene->d.x_pos = tmp[2];
		tmp[3] = data->scene->d.y_pos - data->scene->y_plane * move_speed;
		if ((int)tmp[3] < (int)data->scene->y_size && (int)tmp[3] >= 0
			&& (data->scene->coord[(int)tmp[3]] \ 
			[(int)data->scene->d.x_pos].type == FLOOR
			|| data->scene->coord[(int)tmp[3]] \ 
			[(int)data->scene->d.x_pos].type == PLAY))
			data->scene->d.y_pos = tmp[3];
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
		tmp[2] = data->scene->d.x_pos + data->scene->x_plane * move_speed;
		if ((int)tmp[2] < (int)data->scene->x_size && (int)tmp[2] >= 0
			&& (data->scene->coord[(int)data->scene->d.y_pos] \ 
			[(int)tmp[2]].type == FLOOR
			|| data->scene->coord[(int)data->scene->d.y_pos] \ 
			[(int)tmp[2]].type == PLAY))
			data->scene->d.x_pos = tmp[2];
		tmp[3] = data->scene->d.y_pos + data->scene->y_plane * move_speed;
		if ((int)tmp[3] < (int)data->scene->y_size && (int)tmp[3] >= 0
			&& (data->scene->coord[(int)tmp[3]] \ 
			[(int)data->scene->d.x_pos].type == FLOOR
			|| data->scene->coord[(int)tmp[3]] \ 
			[(int)data->scene->d.x_pos].type == PLAY))
			data->scene->d.y_pos = tmp[3];
		rendering_process(data);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img.img_ptr, 0, 0);
	} */