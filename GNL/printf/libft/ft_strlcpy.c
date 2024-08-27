/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuk <khuk@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 14:37:21 by khuk              #+#    #+#             */
/*   Updated: 2024/04/17 18:53:40 by khuk             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bsd/string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (dst == NULL || size == 0)
	{
		while (src[i] != 0)
			i++;
		return (i);
	}
	while (src[i] != 0 && i < (size - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	while (src[i] != 0)
		i++;
	return (i);
}
/*
int	main()
{
	char	*src = "Hello, world!";
	char	dst[6];
	//char	dst2[6];

	printf("Check: %zu\n", ft_strlcpy(dst, src, 25));
	printf("Check: %s\n", dst);
	//printf("Check real strlcpy: %zu\n", strlcpy(dst2, src, 25));
	//printf("Check: %s\n", dst2);
	return (0);
}*/