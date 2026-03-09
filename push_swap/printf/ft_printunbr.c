/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuk <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 17:47:40 by khuk              #+#    #+#             */
/*   Updated: 2024/05/02 13:29:54 by khuk             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printunbr(unsigned int nb, int fd)
{
	int	i;

	i = 0;
	if (nb > 9)
		i += ft_printunbr(nb / 10, fd);
	ft_putchar_fd(nb % 10 + '0', fd);
	i++;
	return (i);
}
/*
#include <stdio.h>

int main(int ac, char **av)
{
    int count;
    int count2;
    count = ft_printunbr(atoi(av[1]), 1);
    printf("\nCount: %i\n", count);
    count2 = printf("%u", atoi(av[1]));
    printf("\nCount check: %i\n", count2);
    return (0);
}*/
