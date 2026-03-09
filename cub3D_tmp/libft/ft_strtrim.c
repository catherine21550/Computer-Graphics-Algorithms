/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuk <khuk@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 14:40:02 by khuk              #+#    #+#             */
/*   Updated: 2024/04/22 20:07:29 by khuk             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	findinset(char const *set, char c)
{
	size_t	i;

	i = 0;
	while (set[i] != 0)
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	b;
	size_t	e;

	b = 0;
	if (!s1 || !set)
		return (NULL);
	e = ft_strlen(s1) - 1;
	while (findinset(set, s1[b]) && s1[b] != 0)
		b++;
	while (findinset(set, s1[e]) && e > b)
		e--;
	return (ft_substr(s1, (unsigned int)b, (e - b + 1)));
}
/*
#include <stdio.h>
int	main()
{
	char const	str[] = "    ab cd  f    ";
	char const	set[] = " ";
	char	*res;

	res = ft_strtrim(str, set);
	printf("String: <%s>\n Set: <%s>\n Result: <%s>\n", str, set, res);
	return (0);
}*/
