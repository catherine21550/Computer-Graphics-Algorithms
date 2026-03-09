/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuk <khuk@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 14:15:03 by khuk              #+#    #+#             */
/*   Updated: 2024/04/21 18:50:18 by khuk             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		c = c + ('a' - 'A');
	return (c);
}
/*
int main()
{
    int a = 70;

    printf("Control: %d\n", tolower(a));
    printf("My function: %d\n", ft_tolower(a));
    return (0);
}*/