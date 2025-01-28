/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuk <khuk@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 17:58:51 by khuk              #+#    #+#             */
/*   Updated: 2024/04/24 22:26:54 by khuk             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	size;

	if (!s1 && !s2)
		return (0);
	if (!s1)
		return (ft_strdup((char *)s2));
	if (!s2)
		return (ft_strdup((char *)s1));
	size = ft_strlen(s1) + ft_strlen(s2);
	res = (char *)malloc(sizeof (char) * (size + 1));
	if (!res)
		return (0);
	else
	{
		ft_strlcpy(res, s1, (ft_strlen(s1) + 1));
		ft_strlcat(res, s2, (size + 1));
	}
	return (res);
}
