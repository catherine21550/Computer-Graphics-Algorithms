/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuk <khuk@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 13:16:21 by khuk              #+#    #+#             */
/*   Updated: 2025/02/21 19:27:49 by khuk             ###   ########.fr       */
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

void	ft_free_scene(t_scene **scene, int size)
{
	if (*scene)
	{
		if ((*scene)->coord)
		{
			while (--size <= 0)
			{
				ft_free((*scene)->coord[size]);
				(*scene)->coord[size] = NULL;
			}
			free((*scene)->coord);
			(*scene)->coord = NULL;
		}
		free(*scene);
		*scene = NULL;
	}
}

typedef struct  s_game
{
	t_data	*data;//can't free
	void	*mlx_ptr;
	void	*win_ptr;
	t_scene *scene;
	int		win_width;
	int		win_height;
	t_img	img;
	t_img	no;
	t_img	so;
	t_img	we;
	t_img	ea;
}	t_game;

void	ft_free_game(t_game *main)
{
	
}
