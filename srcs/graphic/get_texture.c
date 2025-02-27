/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuk <khuk@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 20:01:27 by khuk              #+#    #+#             */
/*   Updated: 2025/02/26 19:06:45 by khuk             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphic.h"

bool	get_texture(t_game *main, t_img *texture, char *path)
{
	texture->width = 0;
	texture->height = 0;
	texture->img_ptr = mlx_xpm_file_to_image(main->mlx_ptr, path,
			&texture->width, &texture->height);
	if (!texture->img_ptr)
		return (ft_putstr_fd("Error: textureload error\n", 2), false);
	texture->ptr_imgbit = mlx_get_data_addr(texture->img_ptr,
			&texture->bits_per_pixel, &texture->size_line, &texture->endian);
	if (!texture->ptr_imgbit)
		return (ft_putstr_fd("Error: textureload data error\n", 2), false);
	return (texture->created = true);
}

bool	get_char(t_game *main, t_img *texture, char *path)
{
	texture->width = 0;
	texture->height = 0;
	texture->img_ptr = mlx_xpm_file_to_image(main->mlx_ptr, path,
			&texture->width, &texture->height);
	//printf("%s\n", strerror(errno));//temp debug
	if (!texture->img_ptr)
		return (texture->created = false);
	texture->ptr_imgbit = mlx_get_data_addr(texture->img_ptr,
			&texture->bits_per_pixel, &texture->size_line, &texture->endian);
	if (!texture->ptr_imgbit)
		return (texture->created = false);
	return (texture->created = true);
}

bool	get_all_textures(t_game *main)
{
	if (!get_texture(main, &main->no, main->data->no)
		|| !get_texture(main, &main->so, main->data->so)
		|| !get_texture(main, &main->we, main->data->we)
		|| !get_texture(main, &main->ea, main->data->ea))
		return (ft_free_game(main), false);
	get_char(main, &main->player, "./textures/main_char_2.xpm");
	return (true);
}
