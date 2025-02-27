/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuk <khuk@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:14:51 by teesmaa           #+#    #+#             */
/*   Updated: 2025/02/27 16:38:17 by khuk             ###   ########.fr       */
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
	int	offset;

	size = 6;
	offset = 10;
	i = 0;
	while (main->data->map[i])
	{
		j = 0;
		while (main->data->map[i][j] != '\0')
		{
			if (abs(main->data->player_pos[0] - i) < 8 && abs(main->data->player_pos[1] - j) < 8)
			{
				if (main->data->map[i][j] == '1')
					draw_square_in_image(main, j * size + offset, i * size + offset, WHITE, size);
				else if (main->data->map[i][j] == '0')
					draw_square_in_image(main, j * size + offset, i * size + offset, GREY, size);
			}
			j++;
		}
		i++;
	}
	draw_square_in_image(main, main->data->player_pos[1] * size + offset,
		main->data->player_pos[0] * size + offset, 0xFF0000, size);
}

void	draw_minimap_to_img(t_game *main)
{
	double	mini_size[2];
	double	draw[2];

	mini_size[0] = main->win_height / 4;
	mini_size[1] = (mini_size[0] / main->minimap.height) * main->minimap.width;
	draw[0] = 12 + (main->win_width / 20);
	draw[1] = (main->win_height / 20) + mini_size[1];
	draw_scaled_image(main, &main->minimap, (int *)draw, (int *)mini_size);
}

bool	draw_minimap(t_game *main)
{
	minimap_pixels(main);
	draw_minimap_to_img(main);
	return (true);
}
