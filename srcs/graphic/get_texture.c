/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuk <khuk@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 20:01:27 by khuk              #+#    #+#             */
/*   Updated: 2025/02/19 20:51:00 by khuk             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphic.h"

bool	get_textures(t_game *main)
{
	main->texture.height = 65;
	main->texture.width = 65;
	main->texture.img_ptr = mlx_xpm_file_to_image(main->mlx_ptr, main->data->no, &main->texture.width, &main->texture.height);
	if (!main->texture.img_ptr)
		return(printf("Textureload error\n%s\n", strerror(errno)), false);//print into stderror!!!!!
	main->texture.ptr_imgbit = mlx_get_data_addr(main->texture.img_ptr,
			&main->texture.bits_per_pixel, &main->texture.size_line, &main->texture.endian);
	if (!main->texture.ptr_imgbit)
		return (printf("Textureload data error\n%s\n", strerror(errno)), false);//print into stderror!!!!!
	return (true);
}