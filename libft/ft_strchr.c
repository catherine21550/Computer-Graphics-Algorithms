/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuk <khuk@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 19:13:50 by khuk              #+#    #+#             */
/*   Updated: 2024/04/22 20:29:24 by khuk             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
 
char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char *)s;
	while (s[i] != 0)
	{
		if (s[i] == (char)c)
			return (str + i);
		i++;
	}
	if ((char)c == '\0' && s[i] == '\0')
		return (str + i);
	return (0);
}
/*  	
int main() {
    char str[] = "Hello, world!";
    char *ptr;

    // Знаходимо перше входження символу 'o' в рядок str
    ptr = strchr(str, 'o');

    if (ptr != NULL) {
        printf("Перше входження символу 'o' 
		знайдено в позиції: %ld\n", ptr - str);
    } else {
        printf("Символ 'o' не знайдено в рядку.\n");
    }

    return 0;
}*/
