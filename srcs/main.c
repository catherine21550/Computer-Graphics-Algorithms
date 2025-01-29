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
    ft_putendl_fd("Error", 2);
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

int save_data(char *arg, t_data *data)
{
    int     fd;
    int     i;
    (void)data;

    fd = open(arg, O_RDONLY);
    if (fd == -1)
        exit_error(strerror(errno));
    i = 0;
    //read byte by byte
    if (close(fd) == -1)
        exit_error("Failed to close file");
    return (0);
}

int main(int argc, char **argv)
{
    t_data data;

    check_arg(argc, argv[1]);
    save_data(argv[1], &data);
    return (0);
}
