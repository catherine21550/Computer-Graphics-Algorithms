/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuk <khuk@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 13:11:40 by khuk              #+#    #+#             */
/*   Updated: 2025/02/23 20:11:55 by khuk             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphic.h"

double	ft_abs(double i)
{
	double	j;

	j = i;
	if (i < 0)
		j *= -1;
	return (j);
}

int	ft_sign_dda(double i)
{
	int	res;

	res = 0;
	if (i >= 0)
		res = 1;
	else
		res = -1;
	return (res);
}

void	solid_color(t_game *d, int x, int y)
{
	int		i[2];
	int		color;

	i[0] = -1;
	while (++i[0] < y)
	{
		if (i[0] < d->win_height / 2)
			color = d->scene->color_ceiling;
		else
			color = d->scene->color_floor;
		i[1] = -1;
		while (++i[1] < x)
			my_put_pixel(d, i[1], i[0], color);
	}
}

void	my_put_pixel(t_game *main, int x, int y, int color)
{
	int		i;

	if (!main->img.ptr_imgbit)
	{
		exit_error("Image buffer is NULL\n");
		return ;
	}
	if (x > main->img.width || y > main->img.height || x < 0 || y < 0)
		return ;
	i = (main->img.size_line * y) + ((main->img.bits_per_pixel / 8) * x);
	*((unsigned int *)(i + main->img.ptr_imgbit)) = color;
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
		y_text = (int)((i - line_param[0]) * (double)text->height
				/ (line_param[1] - line_param[0]));
		color = *(int *)(text->ptr_imgbit + (y_text * text->size_line
					+ x_text * (text->bits_per_pixel / 8)));
		my_put_pixel(main, x, i, color);
		i++;
	}
}

void draw_scaled_image(t_game *main, t_img *texture, int *dest, int *target)
{
	int i[2];
	int src[2];
	int color;

	i[0] = -1;
	while (++i[0] < target[1])
	{
		i[1] = -1;
		while (++i[1] < target[0])
		{
			src[0] = (i[1] * texture->width) / target[0];
			src[1] = (i[0] * texture->height) / target[1];
			if (src[0] < 0)
				src[0] = 0;
			else if (src[0] >= texture->width)
				src[0] = texture->width - 1;
			if (src[1] < 0)
				src[1] = 0;
			else if (src[1] >= texture->height)
				src[1] = texture->height - 1;
			color = *(int *)(texture->ptr_imgbit + (src[1] * texture->size_line
					+ src[0] * (texture->bits_per_pixel / 8)));
			if (color > 0)
				my_put_pixel(main, dest[0] + i[1], dest[1] + i[0], color);
		}
	}
}
