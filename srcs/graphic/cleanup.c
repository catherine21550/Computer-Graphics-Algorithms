/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuk <khuk@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 13:16:21 by khuk              #+#    #+#             */
/*   Updated: 2025/02/27 17:23:32 by khuk             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphic.h"

void	destroy_graphics(t_game *data)
{
	if (data->img.created)
		mlx_destroy_image(data->mlx_ptr, data->img.img_ptr);
	if (data->no.created)
		mlx_destroy_image(data->mlx_ptr, data->no.img_ptr);
	if (data->so.created)
		mlx_destroy_image(data->mlx_ptr, data->so.img_ptr);
	if (data->ea.created)
		mlx_destroy_image(data->mlx_ptr, data->ea.img_ptr);
	if (data->we.created)
		mlx_destroy_image(data->mlx_ptr, data->we.img_ptr);
	if (data->player.created)
		mlx_destroy_image(data->mlx_ptr, data->player.img_ptr);
	if (data->win_ptr)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	if (data->mlx_ptr)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
	}
}

void	ft_free_scene(t_scene **scene, int size)
{
	if (*scene)
	{
		if ((*scene)->coord)
		{
			while (size-- > 0)
			{
				free((*scene)->coord[size]);
				(*scene)->coord[size] = NULL;
			}
			free((*scene)->coord);
			(*scene)->coord = NULL;
		}
		free(*scene);
		*scene = NULL;
	}
}

void	ft_free_game(t_game *main)
{
	cleanup(main->data);
	if (main->scene)
		ft_free_scene(&(main->scene), main->scene->y_size);
	destroy_graphics(main);
}
