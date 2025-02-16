/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_algorithm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuk <khuk@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 23:49:31 by khuk              #+#    #+#             */
/*   Updated: 2025/02/16 23:51:06 by khuk             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphic.h"

static void	ft_dda_util(t_dda *d, double *delta, char c)
{
	d->side = 0;
	if (c == 'x')
	{
		d->x_dist_wall = d->x_dist_wall + delta[0];
		d->x_map += d->x_step;
		d->side = 0;
	}
	else
	{
		d->y_dist_wall = d->y_dist_wall + delta[1];
		d->y_map += d->y_step;
		d->side = 1;
	}
}

void	ft_dda(t_game *main, t_dda *d, double *delta, double *k)
{
	d->x_step = 1;
	if (k[1] >= 0)
		d->x_dist_wall = (d->x_map + 1.0 - main->scene->player->x) * delta[0];
	else
	{
		d->x_dist_wall = (main->scene->player->x - d->x_map) * delta[0];
		d->x_step = -1;
	}
	d->y_step = 1;
	if (k[2] >= 0)
		d->y_dist_wall = (d->y_map + 1.0 - main->scene->player->y) * delta[1];
	else
	{
		d->y_dist_wall = (main->scene->player->y - d->y_map) * delta[1];
		d->y_step = -1;
	}
	while (true)
	{
		if (d->x_dist_wall < d->y_dist_wall)
			ft_dda_util(d, delta, 'x');
		else
			ft_dda_util(d, delta, 'y');
		if (main->scene->coord[(int)d->y_map][(int)d->x_map].type != FLOOR)
			break ;
	}
}
