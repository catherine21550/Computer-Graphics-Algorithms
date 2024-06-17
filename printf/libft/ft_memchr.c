/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuk <khuk@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 21:21:21 by khuk              #+#    #+#             */
/*   Updated: 2024/04/22 20:19:29 by khuk             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*ptr;
	size_t	i;

	i = 0;
	ptr = (char *)s;
	while (i < n)
	{
		if ((unsigned char)ptr[i] == (unsigned char)c)
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}
