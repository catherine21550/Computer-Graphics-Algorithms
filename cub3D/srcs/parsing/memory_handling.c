/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_handling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teesmaa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 11:00:38 by teesmaa           #+#    #+#             */
/*   Updated: 2025/03/05 11:00:57 by teesmaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_array(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

void	clean_exit(t_data *data, char *str)
{
	cleanup(data);
	exit_error(str);
}

void	exit_error(char *str)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(str, 2);
	exit (EXIT_FAILURE);
}

void	cleanup(t_data *data)
{
	int	i;

	i = 0;
	while (data->content[i])
	{
		free(data->content[i]);
		i++;
	}
	if (data->content)
		free(data->content);
}
