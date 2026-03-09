/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuk <khuk@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 14:46:20 by khuk              #+#    #+#             */
/*   Updated: 2024/04/26 12:23:45 by khuk             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*subs;
	size_t	i;
	size_t	j;

	i = (size_t)start;
	j = 0;
	if (!s)
		return (NULL);
	if ((size_t)start >= ft_strlen(s) || len == 0)
	{
		subs = ft_calloc(1, sizeof(char));
		if (!subs)
			return (NULL);
		return (subs);
	}
	if (len > (ft_strlen(s) - (size_t)start))
		len = ft_strlen(s) - (size_t)start;
	subs = (char *)malloc(sizeof(char) * (len + 1));
	if (!subs)
		return (NULL);
	while (i < ft_strlen(s) && j < len)
		subs[j++] = s[i++];
	subs[j] = '\0';
	return ((char *)subs);
}
/*
int	main()
{
	char const	str[] = "Hello World";
	char *p = ft_substr(str, 6, 5);
	printf("My result: %s\n", p);
	return(0);
}*/
