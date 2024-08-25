/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_handling_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuk <khuk@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 16:54:15 by khuk              #+#    #+#             */
/*   Updated: 2024/08/26 00:35:58 by khuk             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

int	mouse_handling(int button, int x, int y, t_data *data)
{
	(void)x;
	(void)y;
	if (button == 4)
	{
		data->scale += 1;
		fdf_redraw_img(data, data->ac, data->av);
	}
	else if (button == 5)
	{
		data->scale -= 1;
		if (data->scale <= 0)
			data->scale = 1;
		fdf_redraw_img(data, data->ac, data->av);
	}
	return (0);
}

int	exit_function(t_data *data)
{
	mlx_loop_end (data->mlx_ptr);
	return (0);
}

int	key_function(int key, t_data *data)
{
	if (key == XK_Escape)
		mlx_loop_end (data->mlx_ptr);
	else if (key == 65363)
	{
		if (data->ang <= 360)
			data->ang += 1;
		//fdf_rotate_y(data);
		fdf_redraw_img(data, data->ac, data->av);
	}
	if (key == 65361)
	{
		if (data->ang >= 1)
			data->ang -= 1;
		//fdf_rotate_y(data);
		fdf_redraw_img(data, data->ac, data->av);
	}
	else if (key == 99)
	{
		if (++data->color_pic == 8)
			data->color_pic = 0;
		fdf_redraw_img(data, data->ac, data->av);
	}
	else if (key == XK_Return)
	{
		if (++data->color == 8)
			data->color = 0;
		fdf_redraw_img(data, data->ac, data->av);
	}
	return (0);
}
