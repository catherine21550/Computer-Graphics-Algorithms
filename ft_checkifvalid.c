/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkifvalid.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuk <khuk@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 13:44:05 by khuk              #+#    #+#             */
/*   Updated: 2024/07/11 12:14:52 by khuk             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_double(int ac, char *av[])
{
	int	i;
	int	j;
	int	last;

	i = 1;
	last = ac - 1;
	while (i < last)
	{
		j = i + 1;
		while (j <= last)
		{
			if (ft_atoi(av[i]) == ft_atoi(av[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_check_limits(char *str)
{
	int			i;
	long long	nb;
	int			sign;

	i = 0;
	sign = 1;
	nb = 0;
	if (ft_strlen(str) > 11 || (str[0] == '-' && str[1] == '\0'))
		return (0);
	if (str[0] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i] == '0' && str[i])
		i++;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		nb = nb * 10 + (str[i] - 48);
		i++;
	}
	nb = nb * sign;
	if (nb > INT_MAX || nb < INT_MIN)
		return (0);
	return (1);
}

int	ft_if_valid(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (ft_strlen(str) > 11)
		return (0);
	if (str[0] == '-' && str[1] == '0')
		return (0);
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			i++;
		}
		else
			return (0);
	}
	return (1);
}
