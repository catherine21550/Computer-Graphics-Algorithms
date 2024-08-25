/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_shift.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuk <khuk@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 16:44:53 by khuk              #+#    #+#             */
/*   Updated: 2024/08/25 16:44:56 by khuk             ###   ########.fr       */
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
