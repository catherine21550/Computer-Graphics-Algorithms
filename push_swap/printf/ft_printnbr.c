/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuk <khuk@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 16:27:57 by khuk              #+#    #+#             */
/*   Updated: 2024/05/02 13:32:19 by khuk             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printnbr(long int nb, int fd)
{
	int	i;

	i = 0;
	if (nb < 0)
	{
		write (fd, "-", 1);
		nb *= -1;
		i++;
	}
	if (nb > 9)
		i += ft_printnbr(nb / 10, fd);
	ft_putchar_fd(nb % 10 + '0', fd);
	i++;
	return (i);
}
/*
#include <stdio.h>

int main(int ac, char **av)
{
	int	count;
	int count2;
	count = ft_printnbr(atoi(av[1]), 1);
	printf("\nCount: %i\n", count);
	count2 = printf("%i", atoi(av[1]));
	printf("\nCount check: %i\n", count2);
	return (0);
}*/
