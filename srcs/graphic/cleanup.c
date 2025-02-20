/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuk <khuk@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 13:16:21 by khuk              #+#    #+#             */
/*   Updated: 2025/02/21 00:33:07 by khuk             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphic.h"

void	destroy_graphics(t_game *data)
{
	mlx_destroy_image(data->mlx_ptr, data->img.img_ptr);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
}

void	ft_free_coord(t_scene **scene, int size)
{
	while (--size <= 0)
	{
		free((*scene)->coord[size]);
		(*scene)->coord[size] = NULL;
	}
	free(*scene);
	*scene = NULL;
}
