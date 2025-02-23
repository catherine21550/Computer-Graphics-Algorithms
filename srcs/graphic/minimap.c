/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuk <khuk@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:14:51 by teesmaa           #+#    #+#             */
/*   Updated: 2025/02/24 00:11:34 by khuk             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphic.h"

/* void	put_pixel_to_image(char *img_data, int x, int y, int color,
	int size_line, int bpp)
{
	int	pixel_index;

	pixel_index = (y * size_line) + (x * (bpp / 8));
	img_data[pixel_index] = color & 0xFF;
	img_data[pixel_index + 1] = (color >> 8) & 0xFF;
	img_data[pixel_index + 2] = (color >> 16) & 0xFF;
} */

void	my_put_pixel_to_image(t_img *img, int x, int y, int color)
{
	int	pixel_index;

	if (x < 0 || y < 0 || x >= img->width || y >= img->height)
		return;
	pixel_index = (y * img->size_line) + (x * (img->bits_per_pixel / 8));
	*((unsigned int *)(img->ptr_imgbit + pixel_index)) = color;
}

void	draw_square_in_image(t_game *main, int x, int y, int color, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			my_put_pixel_to_image(&main->minimap, x + j, y + i, color);
/* 			put_pixel_to_image(
				main->minimap.ptr_imgbit,
				x + j,
				y + i,
				color,
				main->img.size_line,
				main->img.bits_per_pixel
			); */
			j++;
		}
		i++;
	}
}

void	minimap_pixels(t_game *main)
{
	int	i;
	int	j;
	int	size;

	size = 6;
	i = 0;
	while (main->data->map[i])
	{
		j = 0;
		while (main->data->map[i][j] != '\0')
		{
			if (main->data->map[i][j] == '1')
				draw_square_in_image(main, j * size, i * size, 16777215, size);
			else if (ft_strchr(DIRECTIONS, main->data->map[i][j]))
				draw_square_in_image(main, j * size, i * size, 16711680, size);
			else if (main->data->map[i][j] == '0')
				draw_square_in_image(main, j * size, i * size, 8421504, size);
			j++;
		}
		i++;
	}
}

void	draw_minimap_to_img(t_game *main)
{
	double	mini_size[2];
	double	draw[2];

	mini_size[0] = main->win_height / 4;
	mini_size[1] = (mini_size[0] / main->minimap.height) * main->minimap.width;
	draw[0] = 0 + (main->win_width / 20);
	draw[1] = (main->win_height / 20) + mini_size[1];
	draw_scaled_image(main, &main->minimap, (int *)draw, (int *)mini_size);
}

bool	draw_minimap(t_game *main)
{
	if (!create_main_img(main, &main->minimap, W_HEIGHT / 8, W_HEIGHT / 8))
		return (false);
	minimap_pixels(main);
	draw_minimap_to_img(main);
	return (true);
}
