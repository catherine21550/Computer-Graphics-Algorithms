/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuk <khuk@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 13:11:40 by khuk              #+#    #+#             */
/*   Updated: 2025/02/18 22:40:50 by khuk             ###   ########.fr       */
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
	printf("Printirn solid color size %dx%d\n", x, y);
	while (++i[0] < y)
	{
		if (i[0] < d->win_height / 2)
			color = d->scene->color_floor;
		else
			color = d->scene->color_ceiling;
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
		fprintf(stderr, "Error: Image buffer is NULL\n");
		return ;//debug
	}
	if (x > main->img.width || y > main->img.height || x < 0 || y < 0)
	{
		printf("Out of range %d > %d width, %d > %d height\n", x, main->img.width, y, main->img.height);
		return ;//debug
	}
		
	i = (main->img.size_line * y) + ((main->img.bits_per_pixel / 8) * x);
	*((unsigned int *)(i + main->img.ptr_imgbit)) = color;
}

void	draw_line(t_game *main, double	x, double *line_param, int color)
{
	double	i;

	i = line_param[0];
	while (i <= line_param[1])
	{
		my_put_pixel(main, x, i, color);
		i++;
	}
}
