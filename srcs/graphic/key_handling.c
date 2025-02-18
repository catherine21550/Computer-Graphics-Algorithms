/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuk <khuk@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 13:12:24 by khuk              #+#    #+#             */
/*   Updated: 2025/02/17 00:42:55 by khuk             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphic.h"

void rotate_camera(t_game *main, double angle)
{
    double tmp[2];

    tmp[0] = main->scene->x_dir;
	tmp[1] = main->scene->x_plane;
    main->scene->x_dir = tmp[0] * cos(angle) - main->scene->y_dir * sin(angle);
    main->scene->y_dir = tmp[0] * sin(angle) + main->scene->y_dir * cos(angle);
    main->scene->x_plane = tmp[1] * cos(angle) - main->scene->y_plane * sin(angle);
    main->scene->y_plane = tmp[1] * sin(angle) + main->scene->y_plane * cos(angle);
	draw_img(main);
	mlx_put_image_to_window(main->mlx_ptr, main->win_ptr, main->img.img_ptr, 0, 0);
}

int	key_function(int key, t_game *data)
{
	if (key == ESC)
		mlx_loop_end (data->mlx_ptr);
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
