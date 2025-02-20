/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuk <khuk@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 13:56:16 by khuk              #+#    #+#             */
/*   Updated: 2025/02/19 23:58:54 by khuk             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphic.h"

void	scene_init(t_game *main)
{
	struct timeval	tmp;

	fill_coordinates(main);
	main->win_width = W_WIDTH;
	main->win_height = W_HEIGHT;
	main->img.width = main->win_width;
	main->img.height = main->win_height;
	main->scene->plane_length = tan((66 / 2.0) * (CUB_PI / 180.0));
	main->scene->angle = 90.0;
	main->scene->radians = main->scene->angle * (CUB_PI / 180.0);
	main->scene->x_plane = -main->scene->plane_length * sin(main->scene->radians);
	main->scene->y_plane = main->scene->plane_length * cos(main->scene->radians);
	main->scene->x_dir = cos(main->scene->radians);
	main->scene->y_dir = sin(main->scene->radians);
	main->scene->color_wall = BLACK;
	main->scene->color_wall2 = GREY;
	main->scene->color_ceiling = main->data->ceiling;
	main->scene->color_floor = main->data->floor;
	if (gettimeofday(&tmp, NULL) == -1)
		return;//clean everything!!!!
	//main->scene->old_time = (double)(tmp.tv_sec * 1000000 + tmp.tv_usec);
	//main->scene->time = main->scene->old_time;
	main->scene->old_time = 0;
	main->scene->time = 0;
}
