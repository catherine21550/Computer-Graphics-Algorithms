/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuk <khuk@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 13:11:40 by khuk              #+#    #+#             */
/*   Updated: 2025/02/23 22:18:14 by khuk             ###   ########.fr       */
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

void	draw_scaled_image(t_game *main, t_img *texture, int *dest, int *target)
{
	int	i[3];
	int	src[2];

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
			i[2] = *(int *)(texture->ptr_imgbit + (src[1] * texture->size_line
						+ src[0] * (texture->bits_per_pixel / 8)));
			if (i[2] > 0)
				my_put_pixel(main, dest[0] + i[1], dest[1] + i[0], i[2]);
		}
	}
}
