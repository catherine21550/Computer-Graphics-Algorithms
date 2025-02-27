/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuk <khuk@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:14:51 by teesmaa           #+#    #+#             */
/*   Updated: 2025/02/27 13:01:10 by khuk             ###   ########.fr       */
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
			my_put_pixel_to_image(&main->img, x + j, y + i, color);
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

	size = 8;
	i = 0;
	while (main->data->map[i])
	{
		j = 0;
		while (main->data->map[i][j] != '\0')
		{
			if (main->data->map[i][j] == '1')
				draw_square_in_image(main, j * size, i * size, 16777215, size);
			else if (ft_strchr(DIRECTIONS, main->data->map[i][j]))
				draw_square_in_image(main, j * size, i * size, 8421504, size);
			else if (main->data->map[i][j] == '0')
				draw_square_in_image(main, j * size, i * size, 8421504, size);
			draw_square_in_image(main, main->data->player_pos[1] * size,
                main->data->player_pos[0] * size, 0xFF0000, size);
			j++;
		}
		i++;
	}
}

bool	draw_minimap(t_game *main)
{
	minimap_pixels(main);
	return (true);
}
