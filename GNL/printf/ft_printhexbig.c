/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhexbig.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuk <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 19:16:37 by khuk              #+#    #+#             */
/*   Updated: 2024/05/01 19:55:32 by khuk             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printhexbig(int nbr)
{
	char			*hexbig;
	int				i;
	unsigned int	nb;

	hexbig = "0123456789ABCDEF";
	i = 0;
	nb = (unsigned int)nbr;
	if (nb >= 16)
	{
		i += ft_printhexbig(nb / 16);
	}
	ft_putchar_fd(hexbig[nb % 16], 1);
	i++;
	return (i);
}
/*
#include <stdio.h>

int main(int ac, char **av)
{
    printf("My printhex:\n");
    int count = ft_printHEX(atoi(av[1]));
    printf("\n");
    printf("The actual printf:\n");
    int countcheck = printf("%X", atoi(av[1]));
    printf("\nCount: %i\nCountcheck: %i\n", count, countcheck);
    return (0);
}*/
