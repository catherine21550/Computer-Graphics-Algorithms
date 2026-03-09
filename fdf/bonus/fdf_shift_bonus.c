/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_shift_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuk <khuk@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 16:44:53 by khuk              #+#    #+#             */
/*   Updated: 2024/08/26 21:33:11 by khuk             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	shift_img(t_data *data)
{
	int	shift[2];
	int	j[2];
	int	temp;

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

void	xyz_alloc(t_data *data)
{
	int	i;

	data->xyz = ft_calloc(sizeof(t_coord *), data->map.arrlen + 1);
	if (!data->xyz)
	{
		destroy_evrth(data);
		free_data(data);
		exit (1);
	}
	i = -1;
	while (++i < data->map.arrlen)
	{
		data->xyz[i] = ft_calloc(sizeof(t_coord), data->map.strlen);
		if (!data->xyz[i])
		{
			while (--i >= 0)
				free(data->xyz[i]);
			free(data->xyz);
			destroy_evrth(data);
			free_data(data);
			exit(1);
		}
	}
}

void	fdf_rotate_z(t_data *data)
{
	double	t;
	long	i[2];

	i[0] = -1;
	t = data->alpha * PI / 180;
	while (++i[0] < data->y.arrlen)
	{
		i[1] = -1;
		while (++i[1] < data->x.strlen)
		{
			data->xyz[i[0]][i[1]].x = cos(t) * i[1] - sin(t) * i[0];
			data->xyz[i[0]][i[1]].y = sin(t) * i[0] + cos(t) * i[0];
		}
	}
	data->xyz[data->y.arrlen] = NULL;
}

void	fdf_translate(t_data *data)
{
	int		i[2];
	double	temp;

	i[0] = -1;
	while (++i[0] < data->map.arrlen)
	{
		i[1] = -1;
		while (++i[1] < data->map.strlen)
		{
			if (data->map.map[i[0]][i[1]] != 0)
			{
				temp = data->xyz[i[0]][i[1]].z * data->tr;
				if (temp > 1)
					data->xyz[i[0]][i[1]].z = temp;
			}
		}
	}
}

/* void	fdf_rotate_y(t_data *data)
{
	double	t;
	long	i[2];

	i[0] = -1;
	t = data->betta * PI / 180;
	while (++i[0] < data->y.arrlen)
	{
		i[1] = -1;
		while (++i[1] < data->x.strlen)
		{
			data->xyz[i[0]][i[1]].x = cos(t) * i[1] 
			+ sin(t) * data->map.map[i[0]][i[1]];
			data->xyz[i[0]][i[1]].y = i[0];
			data->xyz[i[0]][i[1]].z = data->map.map[i[0]][i[1]] 
			* cos(t) - i[1] * sin(t);
		}
	}
	data->xyz[data->y.arrlen] = NULL; 
}*/
/* 
void	fdf_rotate_x(t_data *data)
{
	double	t;
	long	i[2];

	i[0] = -1;
	t = data->ang * PI / 180;
	while (++i[0] < data->y.arrlen)
	{
		i[1] = -1;
		while (++i[1] < data->x.strlen)
		{
		//	data->xyz[i[0]][i[1]].x = i[1];
			data->xyz[i[0]][i[1]].y = i[0];
			data->xyz[i[0]][i[1]].z = data->map.map[i[0]][i[1]] 
			* cos(t) - i[1] * sin(t);
		}
	}
	data->xyz[data->y.arrlen] = NULL;
} */
