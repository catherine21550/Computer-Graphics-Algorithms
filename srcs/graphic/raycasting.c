/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuk <khuk@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 22:04:56 by khuk              #+#    #+#             */
/*   Updated: 2025/02/26 00:51:20 by khuk             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphic.h"

void	raycast_prep_calculation(t_game *main, double *k, t_dda *d,
		double *delta)
{
	k[1] = cos(main->scene->angle * CUB_PI / 180) + main->scene->x_plane * k[0];
	k[2] = sin(main->scene->angle * CUB_PI / 180) + main->scene->y_plane * k[0];
	if (k[1] == 0)
		delta[0] = 1e30;
	else
		delta[0] = ft_abs(1 / k[1]);
	if (k[2] == 0)
		delta[1] = 1e30;
	else
		delta[1] = ft_abs(1 / k[2]);
	d->x_map = (int)main->scene->d.x_pos;
	d->y_map = (int)main->scene->d.y_pos;
}

void	draw_with_texture(t_game *main, t_dda *d, double *draw, double *k)
{
	t_img	*texture;

	texture = NULL;
	if (d->side == 0)
	{
		if (k[1] > 0)
			texture = &main->ea;
		else
			texture = &main->we;
		draw[3] = main->scene->player->y + k[3] * k[2];
	}
	else
	{
		if (k[2] > 0)
			texture = &main->so;
		else
			texture = &main->no;
		draw[3] = main->scene->player->x + k[3] * k[1];
	}
	draw[3] = draw[3] - (int)draw[3];
	draw_line(main, d->x, draw, texture);
}

void	draw_line(t_game *main, double x, double *line_param, t_img *text)
{
	double	i;
	int		x_text;
	int		y_text;
	int		color;

	i = line_param[0];
	x_text = (int)(line_param[3] * text->width);
	if (x_text < 0)
		x_text = 0;
	else if (x_text >= text->width)
		x_text = text->width - 1;
	while (i <= line_param[1])
	{
		y_text = (int)((i - line_param[4]) * (double)text->height
				/ (line_param[2]));
		color = *(int *)(text->ptr_imgbit + (y_text * text->size_line
					+ x_text * (text->bits_per_pixel / 8)));
		my_put_pixel(main, x, i, color);
		i++;
	}
}

// k[0] - ray_x_offset, х coordinate of the camera and position of player
// k[1] - raydir_x
// k[2] - raydir_y
// k[3] - perpWallDist
// rey[0] - dist of rey from one x side to another x side of square;
// rey[1] - same for y
// draw[0] - start of line(corrected for screen size)
// draw[1] - end of line (corrected for screen size)
// draw[2] - height of the line
// draw[4] - start of line real
// draw[5] - end of line real
void	draw_walls(t_game *main)
{
	double	k[4];
	double	delta_rey[2];
	double	draw[4];

	main->scene->d.x = -1;
	while (++main->scene->d.x <= main->win_width)
	{
		k[0] = (2 * main->scene->d.x / (double)main->win_width - 1);
		raycast_prep_calculation(main, k, &main->scene->d, delta_rey);
		ft_dda(main, &main->scene->d, delta_rey, k);
		if (main->scene->d.side == 0)
			k[3] = main->scene->d.x_dist_wall - delta_rey[0];
		else
			k[3] = main->scene->d.y_dist_wall - delta_rey[1];
		draw[2] = main->win_height / k[3];
		draw[0] = fmax(0, (main->win_height / 2 - draw[2] / 2));
		draw[1] = fmin((main->win_height - 1),
				(main->win_height / 2 + draw[2] / 2));
		draw_with_texture(main, &main->scene->d, (double []){draw[0], draw[1], draw[2], 0,
			(main->win_height / 2 - draw[2] / 2),
			(main->win_height / 2 + draw[2] / 2)}, k);
	}
}
