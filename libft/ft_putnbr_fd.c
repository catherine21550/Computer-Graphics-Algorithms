/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuk <khuk@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 16:27:57 by khuk              #+#    #+#             */
/*   Updated: 2024/04/22 20:26:26 by khuk             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int		nb;

	nb = n;
	if (nb < 0)
	{
		write (fd, "-", 1);
		nb *= -1;
	}
	if (nb > 9)
		ft_putnbr_fd(nb / 10, fd);
	ft_putchar_fd(nb % 10 + '0', fd);
}
/*
#include <unistd.h>

int main()
{

	ft_putnbr_fd(42, 1);
	write (1, "\n", 1);
	ft_putnbr_fd(-2147483648, 1);
	write (1, "\n", 1);
	ft_putnbr_fd(2147483647, 1);

	return (0);
}
*/