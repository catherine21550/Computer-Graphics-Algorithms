/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuk <khuk@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 16:35:22 by khuk              #+#    #+#             */
/*   Updated: 2024/04/22 20:18:08 by khuk             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_intsize(int n)
{
	size_t	size;

	size = 0;
	if (n == 0)
		return (1);
	else if (n == -2147483648)
		return (11);
	else if (n < 0)
	{
		n *= -1;
		size++;
	}
	while (n > 0)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	char		*str;
	long int	temp;
	size_t		size;

	temp = n;
	size = ft_intsize(n);
	if (temp < 0)
		temp *= -1;
	str = (char *)malloc (sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	str[size] = '\0';
	while (size-- > 0 && temp > 0)
	{
		str[size] = (temp % 10) + '0';
		temp /= 10;
	}
	if (n == 0)
		str[0] = '0';
	if (n < 0)
		str[0] = '-';
	return (str);
}
/*
#include <stdio.h> 

int	main()
{
	int	max = 2147483647;
	int min = -2147483648;
	int zero = 0;

	printf("My input1: %d\n My itoa1: %s\n", min, ft_itoa(min));
	free(ft_itoa(min));
	printf("My input1: %d\n My itoa1: %s\n", max, ft_itoa(max));
	free(ft_itoa(min));
	printf("My input1: %d\n My itoa1: %s\n", zero, ft_itoa(zero));
	free(ft_itoa(zero));
	return (0);
}
*/