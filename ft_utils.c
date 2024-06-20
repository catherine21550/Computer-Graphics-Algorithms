/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuk <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 17:03:18 by khuk              #+#    #+#             */
/*   Updated: 2024/06/20 17:03:22 by khuk             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_new_atoi(char *str)
{
	long	i;
	long	res;
	long	sign;

	i = 0;
	res = 0;
	sign = 1;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while ((str[i] >= '0' && str[i] <= '9') && str[i])
	{
		res = res * 10 + (str[i] - 48);
		i++;
	}
	return (res * sign);
}

size_t	ft_counter(const char *str, char delc)
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
