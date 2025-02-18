/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teesmaa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:14:51 by teesmaa           #+#    #+#             */
/*   Updated: 2025/02/17 14:20:21 by teesmaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphic.h"

void	put_pixel_to_image(char *img_data, int x, int y, int color, int size_line, int bpp)
{
	int	pixel_index;

	pixel_index = (y * size_line) + (x * (bpp / 8));
	img_data[pixel_index] = color & 0xFF;
	img_data[pixel_index + 1] = (color >> 8) & 0xFF;
	img_data[pixel_index + 2] = (color >> 16) & 0xFF;
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
			put_pixel_to_image(
				main->minimap.ptr_imgbit,
				x + j,
				y + i,
				color,
				main->img.size_line,
				main->img.bits_per_pixel
			);
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

void	draw_minimap(t_game *main)
{
	main->minimap.img_ptr = mlx_new_image(main->mlx_ptr, 200, 100);
	//protect
	main->minimap.ptr_imgbit = mlx_get_data_addr(main->minimap.img_ptr, &main->img.bits_per_pixel, &main->img.size_line, &main->img.endian);
	//protect
	minimap_pixels(main);
}
