/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuk <khuk@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 22:46:22 by khuk              #+#    #+#             */
/*   Updated: 2024/04/24 21:25:10 by khuk             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*str1;
	char	*str2;

	i = 0;
	if (!dest || !src)
		return (0);
	str1 = (char *)src;
	str2 = (char *)dest;
	while (i < n)
	{
		str2[i] = str1[i];
		i++;
	}
	return (dest);
}
