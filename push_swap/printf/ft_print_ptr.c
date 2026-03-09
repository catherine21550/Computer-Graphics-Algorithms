/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuk <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 11:36:29 by khuk              #+#    #+#             */
/*   Updated: 2024/05/01 19:55:57 by khuk             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_ptr(void *ptr)
{
	char		*hex;
	uintptr_t	adress;
	int			i;
	int			sizeptr;

	if (!ptr)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	hex = "0123456789abcdef";
	adress = (uintptr_t)ptr;
	ft_putstr_fd("0x", 1);
	i = 2;
	sizeptr = sizeof(adress) * 2 - 1;
	while (sizeptr >= 0 && !(((adress) >> (sizeptr * 4)) & 0xF))
		sizeptr--;
	while (sizeptr >= 0)
	{
		ft_putchar_fd(hex[((adress) >> (sizeptr * 4)) & 0xF], 1);
		sizeptr--;
		i++;
	}
	return (i);
}
/*
#include <stdio.h>

int	main()
{
//	int	x = 10;
//	int	*p = NULL;
	int count;
	int countcheck;

	count = ft_print_ptr(NULL);
	printf("\n");
	countcheck = printf("%p", NULL);
	printf("\nCounter: %i\nCountercheck: %i\n", count, countcheck);
	return (0);
}*/
