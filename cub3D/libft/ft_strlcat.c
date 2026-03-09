/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuk <khuk@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 15:57:33 by khuk              #+#    #+#             */
/*   Updated: 2024/04/26 12:56:08 by khuk             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	j;
	size_t	lendst;
	size_t	lensrc;
	size_t	res;

	j = 0;
	lensrc = ft_strlen((char *)src);
	if (size == 0)
		return (lensrc);
	lendst = ft_strlen(dst);
	if (size <= lendst)
		res = size + lensrc;
	else
		res = lensrc + lendst;
	while (src[j] != 0 && lendst < (size - 1))
	{
		dst[lendst] = src[j];
		lendst++;
		j++;
	}
	dst[lendst] = '\0';
	return (res);
}
/*
#include <stdio.h>
#include <bsd/string.h>
int main()
{
    char    *src = " world!";
    char    dst[20] = "Hallo";
    char    *src1 = " world!";
    char    dst1[20] = "Hallo";

    printf("My function: %zu\n", ft_strlcat(dst, src, 20));
    printf("My destination and source: %s, %s\n", dst, src);
    printf("Check function: %zu\n", strlcat(dst1, src1, 20));
    printf("Check destination and source: %s, %s\n", dst1, src1);
    return (0);
}*/
