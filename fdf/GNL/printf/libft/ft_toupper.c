/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuk <khuk@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 13:51:40 by khuk              #+#    #+#             */
/*   Updated: 2024/04/17 15:24:16 by khuk             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>
#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		c = c - ('a' - 'A');
	return (c);
}
/*
int	main()
{
	int a = 100;

	printf("Control: %d\n", toupper(a));
	printf("My function: %d\n", ft_toupper(a));
	return (0);
}*/