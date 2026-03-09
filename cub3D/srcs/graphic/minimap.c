/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuk <khuk@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:14:51 by teesmaa           #+#    #+#             */
/*   Updated: 2025/02/28 01:09:30 by khuk             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphic.h"

void	my_put_pixel_to_image(t_img *img, int x, int y, int color)
{
	int	pixel_index;

	if (x < 0 || y < 0 || x >= img->width || y >= img->height)
		return ;
	pixel_index = (y * img->size_line) + (x * (img->bits_per_pixel / 8));
	*((unsigned int *)(img->ptr_imgbit + pixel_index)) = color;
}

void	mini_solid_color(t_game *d, int x, int y, int size)
{
	int		color;
	int		i;
	int		j;
	int		border;

	border = 4;
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

void	draw_square_in_image(t_game *main, int *k, int color, int size)
{
	int	i;
	int	j;

	i = k[1];
	while (i < size + k[1])
	{
		j = k[0];
		while (j < size + k[0])
		{
			my_put_pixel_to_image(&main->img, i, j, color);
			j++;
		}
		i++;
	}
}

void	minimap_pixels(t_game *main, int x_offset, int y_offset, int size)
{
	int	i[2];
	int	shift[2];

	i[0] = -1;
	while (++i[0] < size)
	{
		i[1] = -1;
		shift[0] = main->data->player_pos[1] - ((size + 1) / 2) + 1 + i[0];
		while (++i[1] < size)
		{
			shift[1] = main->data->player_pos[0] - ((size + 1) / 2) + 1 + i[1];
			if (shift[0] >= 0 && shift[0] < (int)main->scene->y_size
				&& shift[1] >= 0 && shift[1] < (int)main->scene->x_size)
			{
				if (main->scene->coord[shift[0]][shift[1]].type == WALL)
					draw_square_in_image(main, (int []){i[0] * size + x_offset,
						i[1] * size + y_offset}, WHITE, size);
				else
					draw_square_in_image(main, (int []){i[0] * size + x_offset,
						i[1] * size + y_offset}, GREY, size);
			}
		}
	}
}

bool	draw_minimap(t_game *main)
{
	int	x_offset;
	int	y_offset;
	int	size;
	int	x;
	int	y;

	x_offset = W_HEIGHT / 30;
	y_offset = W_HEIGHT / 30;
	size = 13;
	mini_solid_color(main, x_offset, y_offset, size * size);
	minimap_pixels(main, x_offset, y_offset, size);
	x = ((size + 1) / 2) * size + size / 2 + 1;
	y = ((size + 1) / 2) * size + size / 2 + 1;
	draw_square_in_image(main, (int []){x, y}, 0xFF0000, size);
	return (true);
}
