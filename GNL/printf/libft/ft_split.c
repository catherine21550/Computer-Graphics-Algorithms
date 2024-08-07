/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuk <khuk@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 17:26:40 by khuk              #+#    #+#             */
/*   Updated: 2024/04/22 20:04:41 by khuk             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_counter(const char *str, char delc)
{
	size_t	count1;
	size_t	i;
	int		f;

	i = 0;
	count1 = 0;
	while (str[i] != 0)
	{
		f = 0;
		while (str[i] == delc && str[i] != 0)
			i++;
		while (str[i] != delc && str[i] != 0)
		{
			if (f == 0)
			{
				f = 1;
				count1++;
			}
			i++;
		}
	}
	return (count1);
}

static int	safe_malloc(char	**arr, int position, size_t	buffer)
{
	int	i;

	i = 0;
	arr[position] = malloc(buffer);
	if (!arr[position])
	{
		while (i < position)
		{
			free(arr[i]);
			i++;
		}
		free(arr);
		return (1);
	}
	return (0);
}

static int	fill_strs(char	**arr, char const	*str, char delc)
{
	size_t	i;
	size_t	len;
	int		j;

	i = 0;
	j = 0;
	while (str[i] != 0)
	{
		len = 0;
		while (str[i] == delc && str[i] != 0)
			i++;
		while (str[i] != delc && str[i] != 0)
		{
			i++;
			len++;
		}
		if (len != 0)
		{
			if (safe_malloc(arr, j, len + 1))
				return (1);
			ft_strlcpy(arr[j], str + i - len, len + 1);
		}
		j++;
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**myarray;
	size_t	count;
	int		myfill;

	if (!s)
		return (NULL);
	count = ft_counter(s, c);
	myarray = (char **)malloc (sizeof (char *) * (count + 1));
	if (!myarray)
		return (NULL);
	myarray[count] = NULL;
	myfill = fill_strs(myarray, s, c);
	if (myfill != 0)
		return (NULL);
	return (myarray);
}
/*
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    char const *str = "Hello, world! This is a test string.";
    char **split_words = ft_split(str, ' ');

    if (split_words)
    {
        int i = 0;
        while (split_words[i] != NULL)
        {
            printf("%s\n", split_words[i]);
            free(split_words[i]); // Free each word
            i++;
        }
        free(split_words); // Free the array of pointers
    }
    else
    {
        printf("Split failed!\n");
    }

    return 0;
}*/
