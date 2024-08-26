/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_handling_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuk <khuk@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 16:54:15 by khuk              #+#    #+#             */
/*   Updated: 2024/08/26 21:42:31 by khuk             ###   ########.fr       */
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
		fdf_redraw_img(data);
	}
	else if (button == 5)
	{
		data->scale -= 1;
		if (data->scale <= 0)
			data->scale = 1;
		fdf_redraw_img(data);
	}
	return (0);
}

int	exit_function(t_data *data)
{
	mlx_loop_end (data->mlx_ptr);
	return (0);
}

void	key_rotate(int key, t_data *data)
{
	if (key == 65363 || key == 65361)
	{
		if (key == 65363 && data->alpha <= 360)
			data->alpha += 1;
		if (key == 65361 && data->alpha >= 0)
			data->alpha -= 1;
		fdf_rotate_z(data);
	}
	fdf_redraw_img(data);
}

void	key_translate(int key, t_data *data)
{
	if (key == 65362 || key == 65364)
	{
		if (key == 65362)
		{
			if (data->tr_num < 80)
			{
				data->tr_num++;
				data->tr = 1.03;
				fdf_translate(data);
			}
		}
		if (key == 65364)
		{
			if (data->tr_num > 0)
			{
				data->tr_num--;
				data->tr = 0.97;
				fdf_translate(data);
			}
		}
	}
	fdf_redraw_img(data);
}

int	key_function(int key, t_data *data)
{
	if (key == XK_Escape)
		mlx_loop_end (data->mlx_ptr);
	if (key == L || key == R)
		key_rotate(key, data);
	if (key == A || key == D)
		key_translate(key, data);
	else if (key == 99)
	{
		if (++data->color_pic == 8)
			data->color_pic = 0;
		fdf_redraw_img(data);
	}
	else if (key == XK_Return)
	{
		if (++data->color == 8)
			data->color = 0;
		fdf_redraw_img(data);
	}
	return (0);
}
