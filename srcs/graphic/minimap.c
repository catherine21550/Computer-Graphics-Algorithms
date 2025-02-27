/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuk <khuk@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:14:51 by teesmaa           #+#    #+#             */
/*   Updated: 2025/02/27 21:50:30 by khuk             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphic.h"

void	my_put_pixel_to_image(t_img *img, int x, int y, int color)
{
	int	pixel_index;

	if (x < 0 || y < 0 || x >= img->width || y >= img->height)
		return;
	pixel_index = (y * img->size_line) + (x * (img->bits_per_pixel / 8));
	*((unsigned int *)(img->ptr_imgbit + pixel_index)) = color;
}

void	mini_solid_color(t_game *d, int x, int y, int size)
{
	int		color;
	int		i;
	int		j;
	int		border = 4;

	color = d->scene->color_floor;
	i = y - border;
	while (i < y + size + border)
	{
		j = x - border;
		while (j < x + size + border)
		{
			if (i < y || j < x || i >= y + size || j >= x + size)
				my_put_pixel_to_image(&d->img, j, i, 0x000000);
			else
				my_put_pixel_to_image(&d->img, j, i, color);
			j++;
		}
		i++;
	}
}

void	draw_square_in_image(t_game *main, int x, int y, int color, int size)
{
	int	i;
	int	j;

	i = y;
	while (i < size + y)
	{
		j = x;
		while (j < size + x)
		{
			my_put_pixel_to_image(&main->img, i, j, color);
			j++;
		}
		i++;
	}
}

void	minimap_pixels(t_game *main, int x_offset, int y_offset)
{
	int	i[2];
	int	j[2];
	int	size;
	int initial_x_offset;
	int initial_y_offset;
	int x;
	int y;

	size = 12;
	i[0] = fmax(0, main->data->player_pos[0] - 4);
	i[1] = fmin(i[0] + 8, main->scene->y_size);
	initial_x_offset = x_offset;
	initial_y_offset = y_offset;
	y = y_offset;
	while (main->data->map[i[0]] && i[0] < i[1])
	{
		j[0] = fmax(0, main->data->player_pos[1] - 4);
		j[1] = fmin(j[0] + 8, main->scene->x_size);
		x_offset = initial_x_offset;
		x = x_offset;
		while (j[0] < j[1])
		{
			if (main->scene->coord[i[0]][j[0]].type == WALL)
				draw_square_in_image(main, x, y, WHITE, size);
			else if (main->scene->coord[i[0]][j[0]].type == FLOOR
					|| main->scene->coord[i[0]][j[0]].type == PLAY)
				draw_square_in_image(main, x, y, GREY, size);
			j[0]++;
			x += size;
		}
		i[0]++;
		y += 10;
	}
	int player_x = (main->data->player_pos[1] - fmax(0, main->data->player_pos[1] - 4)) * size + initial_x_offset;
	int player_y = (main->data->player_pos[0] - fmax(0, main->data->player_pos[0] - 4)) * size + initial_y_offset;
	draw_square_in_image(main, player_x, player_y, 0xFF0000, size);
}

bool	draw_minimap(t_game *main)
{
	int	x_offset;
	int	y_offset;
	int size;

	x_offset = W_HEIGHT / 30;
	y_offset = W_HEIGHT / 30;
	size = 12 * 12;
	mini_solid_color(main, x_offset, y_offset, size);
	x_offset += (12 * 12 - 12 * 12) / 2;
	y_offset = x_offset;
	minimap_pixels(main, x_offset, y_offset);
	return (true);
} 
