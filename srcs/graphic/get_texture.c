/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuk <khuk@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 20:01:27 by khuk              #+#    #+#             */
/*   Updated: 2025/02/20 16:21:51 by khuk             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphic.h"

bool	get_texture(t_game *main, t_img *texture, char *path)
{
	texture->width = 64;
	texture->height = 64;
	texture->iter = 0;
	texture->img_ptr = mlx_xpm_file_to_image(main->mlx_ptr, path,
		&texture->width, &texture->height);
	if (!texture->img_ptr)
		return(printf("Textureload error\n%s\n", strerror(errno)), false);//print into stderror!!!!!
	texture->ptr_imgbit = mlx_get_data_addr(texture->img_ptr,
			&texture->bits_per_pixel, &texture->size_line, &texture->endian);
	if (!texture->ptr_imgbit)
		return (printf("Textureload data error\n%s\n", strerror(errno)), false);//print into stderror!!!!!
	return (true);
}

bool	get_all_textures(t_game *main)
{
	if (!get_texture(main, &main->no, main->data->no)
		|| !get_texture(main, &main->so, main->data->so)
		|| !get_texture(main, &main->we, main->data->we)
		|| !get_texture(main, &main->ea, main->data->ea))
		return (false);//clean memory if fails
	return (true);
}