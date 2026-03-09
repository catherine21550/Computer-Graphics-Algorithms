/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuk <khuk@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 19:53:30 by khuk              #+#    #+#             */
/*   Updated: 2024/04/18 21:57:46 by khuk             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*last;

	last = NULL;
	if ((char)c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (*s != 0)
	{
		if (*s == (char)c)
			last = (char *)s;
		s++;
	}
	return (last);
}
