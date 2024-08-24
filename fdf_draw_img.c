/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw_img.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuk <khuk@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 17:12:07 by khuk              #+#    #+#             */
/*   Updated: 2024/08/24 11:40:12 by khuk             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	shift_img(t_data *data)
{
	int	shift[2];
	int	j[2];
	int temp;

	temp = 0;
	fdf_center(data, &shift[0], &shift[1]);
	j[0] = -1;
	while (++j[0] < data->y.arrlen)
	{
		j[1] = -1;
		while (++j[1] < data->x.strlen)
		{
			temp = (data->x.map[j[0]][j[1]] + shift[0]);
			data->x.map[j[0]][j[1]] = temp;
			temp = (data->y.map[j[0]][j[1]] + shift[1]);
			data->y.map[j[0]][j[1]] = temp;
		}
	}
}

void	fdf_iter(t_data *data, double *i, int *j)
{
	i[3] = i[0] / i[2];
	i[4] = i[1] / i[2];
	i[0] = data->x.map[j[0]][j[1] - 1];
	i[1] = data->y.map[j[0]][j[1] - 1];
	j[2] = 0;
	while (++j[2] <= i[2])
	{
		i[0] += i[3];
		i[1] += i[4];
		my_put_pixel(data, ((int)i[0]), ((int)i[1]), 0x0000FF);
	}
}

void	fdf_iter2(t_data *data, double *i, int *j)
{
	i[3] = i[0] / i[2];
	i[4] = i[1] / i[2];
	i[0] = data->x.map[j[0] - 1][j[1]];
	i[1] = data->y.map[j[0] - 1][j[1]];
	j[2] = 0;
	while (++j[2] <= i[2])
	{
		i[0] += i[3];
		i[1] += i[4];
		my_put_pixel(data, (int)i[0], (int)i[1], 0xFF0000);
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

void	draw_img(t_data *data, int ac, char *av[])
{
	int		i[2];

	(void)ac;
	(void)av;
	i[0] = -1;
	while (++i[0] < data->y.arrlen)
	{
		i[1] = -1;
		while (++i[1] < data->x.strlen)
		{
			data->x.map[i[0]][i[1]] = ((i[1] * (cos(145))) + (i[0]
						* (cos(145 + 2))) + (data->map.map[i[0]][i[1]]
						* cos(145 - 2)))  * data->scale;
			data->y.map[i[0]][i[1]] = ((i[1] * (sin(145))) + (i[0]
						* (sin(145 + 2))) + (data->map.map[i[0]][i[1]]
						* sin(145 - 2)))  * data->scale;
		}
	}
	shift_img(data);//temp
	connect_dots(data);
	connect_dots2(data);
}
