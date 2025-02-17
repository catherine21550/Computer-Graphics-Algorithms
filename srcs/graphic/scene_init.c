/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuk <khuk@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 13:56:16 by khuk              #+#    #+#             */
/*   Updated: 2025/02/17 15:58:27 by khuk             ###   ########.fr       */
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
	main->scene->x_dir = (double)E_DIRX;
	main->scene->y_dir = (double)E_DIRY;
	main->scene->angle = 90;//atan2(E_DIRX, E_DIRY);
	main->scene->x_plane = 0.0;
	main->scene->y_plane = 2 * atan(0.66 / 1.0);
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
