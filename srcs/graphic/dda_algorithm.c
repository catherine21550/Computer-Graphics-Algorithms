/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_algorithm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuk <khuk@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 23:49:31 by khuk              #+#    #+#             */
/*   Updated: 2025/02/28 15:51:12 by teesmaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphic.h"

void	scene_init(t_game *main)
{
	struct timeval	t;

	fill_coordinates(main);
	main->win_width = W_WIDTH;
	main->win_height = W_HEIGHT;
	main->img.width = main->win_width;
	main->img.height = main->win_height;
	main->scene->plane_length = tan((66 / 2.0) * (CUB_PI / 180.0));
	main->scene->radians = main->scene->angle * (CUB_PI / 180.0);
	main->scene->x_plane = -main->scene->plane_length
		* sin(main->scene->radians);
	main->scene->y_plane = main->scene->plane_length
		* cos(main->scene->radians);
	main->scene->x_dir = cos(main->scene->radians);
	main->scene->y_dir = sin(main->scene->radians);
	main->scene->color_ceiling = main->data->ceiling;
	main->scene->color_floor = main->data->floor;
	if (gettimeofday(&t, NULL) == -1)
		return (ft_free_scene(&main->scene, main->scene->y_size),
			free(main->scene), cleanup(main->data),
			exit_error("Get time failed"));
	main->scene->time = t.tv_sec + (t.tv_usec / 1000000.0);
	main->scene->old_time = main->scene->time;
	main->scene->d.x_pos = (double)main->scene->player->x + 0.5;
	main->scene->d.y_pos = (double)main->scene->player->y;
}

static void	ft_dda_util(t_game *main, t_dda *d, double *delta)
{
	char	param;

	while (true)
	{
		param = 'y';
		if (d->x_dist_wall < d->y_dist_wall)
			param = 'x';
		d->side = 0;
		if (param == 'x')
		{
			d->x_dist_wall = d->x_dist_wall + delta[0];
			d->x_map = d->x_map + d->x_step;
			d->side = 0;
		}
		else
		{
			d->y_dist_wall = d->y_dist_wall + delta[1];
			d->y_map = d->y_map + d->y_step;
			d->side = 1;
		}
		if (main->scene->coord[(int)d->y_map][(int)d->x_map].type == WALL
			|| main->scene->coord[(int)d->y_map][(int)d->x_map].type == NONE)
			break ;
	}
}

void	ft_dda(t_game *main, t_dda *d, double *delta, double *k)
{
	d->x_step = 1;
	if (k[1] >= 0)
		d->x_dist_wall = (d->x_map + 1.0 - main->scene->d.x_pos) * delta[0];
	else
	{
		d->x_dist_wall = (main->scene->d.x_pos - d->x_map) * delta[0];
		d->x_step = -1;
	}
	d->y_step = 1;
	if (k[2] >= 0)
		d->y_dist_wall = (d->y_map + 1.0 - main->scene->d.y_pos) * delta[1];
	else
	{
		d->y_dist_wall = (main->scene->d.y_pos - d->y_map) * delta[1];
		d->y_step = -1;
	}
	ft_dda_util(main, d, delta);
}
