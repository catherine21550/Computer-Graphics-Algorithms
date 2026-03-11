/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw_img_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuk <khuk@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 17:12:07 by khuk              #+#    #+#             */
/*   Updated: 2024/08/26 17:59:00 by khuk             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	fdf_iter(t_data *data, double *i, int *j)
{
	int	col[8];

	col[0] = 0xFFFFFF;
	col[1] = 0x0000FF;
	col[2] = 0xFF0000;
	col[3] = 0xC0C0C0;
	col[4] = 0xADD8E6;
	col[5] = 0xDA33BF;
	col[6] = 0x843BDB;
	col[7] = 0x003BDB;
	if (i[2] != 0)
	{
		i[3] = i[0] / i[2];
		i[4] = i[1] / i[2];
	}
	i[0] = data->x.map[j[0]][j[1] - 1];
	i[1] = data->y.map[j[0]][j[1] - 1];
	j[2] = 0;
	while (++j[2] <= i[2])
	{
		i[0] += i[3];
		i[1] += i[4];
		my_put_pixel(data, ((int)i[0]), ((int)i[1]), col[data->color_pic]);
	}
}

void	fdf_iter2(t_data *data, double *i, int *j)
{
	int	col[8];

	col[0] = 0xFFFFFF;
	col[1] = 0xFF0000;
	col[2] = 0x0000FF;
	col[3] = 0xFFD700;
	col[4] = 0xFFC0CB;
	col[5] = 0x237CBF;
	col[6] = 0x75E6DF;
	col[7] = 0x000000;
	i[3] = i[0] / i[2];
	i[4] = i[1] / i[2];
	i[0] = data->x.map[j[0] - 1][j[1]];
	i[1] = data->y.map[j[0] - 1][j[1]];
	j[2] = 0;
	while (++j[2] <= i[2])
	{
		i[0] += i[3];
		i[1] += i[4];
		my_put_pixel(data, (int)i[0], (int)i[1], col[data->color_pic]);
	}
}

void	connect_dots(t_data *data)
{
	double	i[5];
	int		j[3];

	j[0] = -1;
	while (++j[0] < data->y.arrlen)
	{
		j[1] = 0;
		while (++j[1] < data->x.strlen)
		{
			i[0] = data->x.map[j[0]][j[1]] - data->x.map[j[0]][j[1] - 1];
			i[1] = data->y.map[j[0]][j[1]] - data->y.map[j[0]][j[1] - 1];
			i[2] = ft_abs(i[1]);
			if (ft_abs(i[0]) > ft_abs(i[1]))
				i[2] = ft_abs(i[0]);
			if (i[2] > 0)
				fdf_iter(data, i, j);
		}
	}
}

void	connect_dots2(t_data *data)
{
	double	i[5];
	int		j[3];

	j[0] = 0;
	while (++j[0] < data->y.arrlen)
	{
		j[1] = -1;
		while (++j[1] < data->x.strlen)
		{
			i[0] = data->x.map[j[0]][j[1]] - data->x.map[j[0] - 1][j[1]];
			i[1] = data->y.map[j[0]][j[1]] - data->y.map[j[0] - 1][j[1]];
			i[2] = ft_abs(i[1]);
			if (ft_abs(i[0]) > ft_abs(i[1]))
				i[2] = ft_abs(i[0]);
			if (i[2] != 0)
				fdf_iter2(data, i, j);
		}
	}
}

void	draw_img(t_data *data)
{
	int		i[2];

	xyz_alloc(data);
	i[0] = -1;
	while (++i[0] < data->y.arrlen)
	{
		i[1] = -1;
		while (++i[1] < data->x.strlen)
		{
			data->xyz[i[0]][i[1]].x = i[1];
			data->xyz[i[0]][i[1]].y = i[0];
			data->xyz[i[0]][i[1]].z = data->map.map[i[0]][i[1]];
		}
	}
	draw_img2(data);
}
