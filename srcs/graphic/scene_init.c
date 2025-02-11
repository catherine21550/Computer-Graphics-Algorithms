/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuk <khuk@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 13:56:16 by khuk              #+#    #+#             */
/*   Updated: 2025/02/11 21:57:25 by khuk             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphic.h"

//  Player look to the right
// main->scene->x_dir = 1.0;
// main->scene->y_dir = 0.0;
//  Player look up
// main->scene->x_dir = 0.0;
// main->scene->y_dir = 1.0;
//  Player look down
// main->scene->x_dir = 0.0;
// main->scene->y_dir = -1.0;
//  Player look to the left
// main->scene->x_dir = -1.0;
// main->scene->y_dir = 0.0;

void	scene_init(t_game *main)
{
	struct timeval	tmp;

	fill_coordinates(main);
	main->scene->x_dir = 1.0;
	main->scene->y_dir = 0.0;
	main->scene->x_plane = 0.0;
	main->scene->x_plane = 2 * atan(0.66/1.0);
	if (gettimeofday(&tmp, NULL) == -1)
		return ;//clean everything!!!!
	//main->scene->old_time = (double)(tmp.tv_sec * 1000000 + tmp.tv_usec);
	//main->scene->time = main->scene->old_time;
	main->scene->old_time = 0;
	main->scene->time = 0;
}


