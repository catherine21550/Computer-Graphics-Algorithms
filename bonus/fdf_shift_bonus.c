/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_shift_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuk <khuk@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 16:44:53 by khuk              #+#    #+#             */
/*   Updated: 2024/08/26 00:34:03 by khuk             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

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

void	fdf_rotate_y(t_data *data)
{
	float	t[3];
	long	i[2];

	i[0] = -1;
	t[0] = data->ang/*  * Pi / 180 */;
	while (++i[0] < data->y.arrlen)
	{
		i[1] = -1;
		while (++i[1] < data->x.strlen)
		{
			t[1] = cos(t[0]) * data->x.map[i[0]][i[1]] - sin(t[0]) * data->y.map[i[0]][i[1]];
			t[2] = sin(t[0]) * data->x.map[i[0]][i[1]] - cos(t[0]) * data->y.map[i[0]][i[1]];
			data->x.map[i[0]][i[1]] = t[1];
			data->y.map[i[0]][i[1]] = t[2];
		}
	}
}
