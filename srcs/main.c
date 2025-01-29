/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teesmaa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 09:49:45 by teesmaa           #+#    #+#             */
/*   Updated: 2025/01/29 09:55:28 by teesmaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void exit_error(char *str)
{
    ft_putstr_fd("Error: ", 2);
    ft_putendl_fd(str, 2);
    exit (EXIT_FAILURE);
}

void check_arg(int argc, char *map)
{
    char    *format;

    if (argc != 2)
        exit_error("use one argument");
    format = ft_strnstr(map, ".cub", ft_strlen(map));
    if (!format || format[4] != '\0')
        exit_error("file format must be .cub");
}

int save_data(char **argv, t_data *data)
{
    int fd;
    (void)data;

    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
        exit_error(strerror(errno));
    return (0);
}

int main(int argc, char **argv)
{
    t_data data;

    check_arg(argc, argv[1]);
    save_data(argv, &data);
    return (0);
}
