/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuk <khuk@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 22:03:57 by khuk              #+#    #+#             */
/*   Updated: 2025/02/23 22:14:21 by khuk             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphic.h"

bool	create_main_img(t_game *main)
{
	main->img.img_ptr = mlx_new_image(main->mlx_ptr, W_WIDTH, W_HEIGHT);
	if (!main->img.img_ptr)
		return (ft_free_game(main), ft_putstr_fd(IMG_ER, 2), false);
	main->img.ptr_imgbit = mlx_get_data_addr(main->img.img_ptr,
			&main->img.bits_per_pixel, &main->img.size_line, &main->img.endian);
	if (!main->img.ptr_imgbit)
		return (ft_free_game(main),
			ft_putstr_fd("Error: mlx_get_data failed\n", 2), false);
	return (main->img.created = true);
}

bool	ft_init_mlx(t_game *main)
{
	main->mlx_ptr = mlx_init();
	if (!main->mlx_ptr)
		return (ft_free_game(main),
			ft_putstr_fd("Error: mlx_init failed\n", 2), false);
	main->win_ptr = mlx_new_window(main->mlx_ptr, W_WIDTH, W_HEIGHT, "Cub3D");
	if (!main->win_ptr)
		return (ft_free_game(main),
			ft_putstr_fd("Error: mlx_new_window failed\n", 2), false);
	return (true);
}
