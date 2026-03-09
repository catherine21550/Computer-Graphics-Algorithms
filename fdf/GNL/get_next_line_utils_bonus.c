/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuk <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 14:50:59 by khuk              #+#    #+#             */
/*   Updated: 2024/08/12 16:42:13 by khuk             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strchr(const char *str, int c)
{
	char	*ptr;

	ptr = (char *)str;
	if (!str)
		return (NULL);
	while (*ptr != 0)
	{
		if (*ptr == (char)c)
			return (ptr);
		ptr++;
	}
	return (NULL);
}

size_t	ft_strlen_gnl(const char *str)
{
	size_t	len;

	len = 0;
	if (!str)
		return (0);
	while (str[len])
		len++;
	return (len);
}

void	*ft_calloc_gnl(size_t nmemb, size_t size)
{
	unsigned char	*res;
	size_t			i;

	i = 0;
	if (nmemb == 0 || size == 0)
		return (NULL);
	else if ((nmemb * size) > SIZE_MAX)
		return (NULL);
	res = (void *)malloc(nmemb * size);
	if (!res)
		return (NULL);
	while (i < (nmemb * size))
	{
		res[i] = (unsigned char) '\0';
		i++;
	}
	return (res);
}

char	*ft_strndup(const char *str, size_t size)
{
	char	*newstr;
	size_t	i;

	if (!str)
		return (NULL);
	newstr = ft_calloc_gnl(size + 1, sizeof(char));
	if (!newstr)
		return (NULL);
	i = 0;
	while (str[i] && i < size)
	{
		newstr[i] = str[i];
		i++;
	}
	newstr[i] = '\0';
	return ((char *)newstr);
}

char	*ft_strjoin_new(char *s1, char *s2)
{
	char	*res;
	char	*ptr;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strndup(s2, ft_strlen_gnl(s2)));
	if (!s2)
		return (ft_strndup(s1, ft_strlen_gnl(s1)));
	res = (char *)ft_calloc_gnl ((ft_strlen_gnl(s1)
				+ ft_strlen_gnl(s2) + 1), sizeof(char));
	if (!res)
		return (res = NULL, NULL);
	ptr = res;
	while (*s1)
		*ptr++ = *s1++;
	while (*s2)
		*ptr++ = *s2++;
	*ptr = '\0';
	return (res);
}
