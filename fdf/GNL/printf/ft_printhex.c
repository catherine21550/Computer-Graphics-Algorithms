/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuk <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 19:18:38 by khuk              #+#    #+#             */
/*   Updated: 2024/05/01 19:58:40 by khuk             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printhex(int nbr)
{
	char			*hex;
	int				i;
	unsigned int	nb;

	hex = "0123456789abcdef";
	i = 0;
	nb = (unsigned int)nbr;
	if (nb >= 16)
	{
		i += ft_printhex(nb / 16);
	}
	ft_putchar_fd(hex[nb % 16], 1);
	i++;
	return (i);
}
/*
#include <stdio.h>

int	main(int ac, char **av)
{
	printf("My printhex:\n");
	int	count =	ft_printhex(atoi(av[1]));
	printf("\n");
	printf("The actual printf:\n");
	int	countcheck = printf("%x", atoi(av[1]));
	printf("\nCount: %i\nCountcheck: %i\n", count, countcheck);
	return (0);
}*/
