/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuk <khuk@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 17:03:18 by khuk              #+#    #+#             */
/*   Updated: 2024/06/23 17:19:50 by khuk             ###   ########.fr       */
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

int	is_sorted(int **stack, int *size)
{
	int	i;

	i = 0;
	while (i < *size - 1)
	{
		if ((*stack)[i] > (*stack)[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	ft_is_sorted_before(int **stack, int begin, int end)
{ 
	if (begin == end)
		return (1);
	while (begin < end)
	{
		if ((*stack)[begin] < (*stack)[begin + 1])
			return (0);
		begin++;
	}
	return (1);
}

int	ft_is_sorted_after(int **stack, int begin, int end)
{
	if (begin == end)
		return (1);
	while (begin < end)
	{
		if ((*stack)[begin] > (*stack)[begin + 1])
			return (0);
		begin++;
	}
	return (1);
}