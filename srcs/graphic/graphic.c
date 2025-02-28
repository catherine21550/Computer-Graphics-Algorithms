/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuk <khuk@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 19:44:46 by khuk              #+#    #+#             */
/*   Updated: 2025/02/28 01:00:37 by khuk             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphic.h"

void	rendering_process(t_game *main)
{
	solid_color(main, main->win_width, main->win_height);
	draw_walls(main);
	draw_minimap(main);
}

bool	handle_graphics(t_game *main)
{
	scene_init(main);
	if (!ft_init_mlx(main)
		|| !create_main_img(main, &main->img, W_WIDTH, W_HEIGHT))
		return (false);
	if (!get_all_textures(main))
		return (false);
	rendering_process(main);
	mlx_put_image_to_window(main->mlx_ptr, main->win_ptr,
		main->img.img_ptr, 0, 0);
	mlx_hook(main->win_ptr, 17, (1L << 0), &exit_function, main);
	mlx_hook(main->win_ptr, 2, (1L << 0), &key_function, main);
	mlx_loop(main->mlx_ptr);
	ft_free_game(main);
	return (true);
}
