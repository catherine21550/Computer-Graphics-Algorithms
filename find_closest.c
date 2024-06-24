/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_closest.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuk <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 21:26:52 by khuk              #+#    #+#             */
/*   Updated: 2024/06/24 21:26:57 by khuk             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*find_closest(int *arr_a, int *arr_b, int size_a, int size_b)
{
	int	i;
	int *calc;

	calc = (int *)malloc(size_b * sizeof(int));
	if (!calc)
		return (NULL);
	i = 0;
	while (i < size_b)
	{
		calc[i] = ind_of_next(arr_a, size_a, arr_b[i]);
		i++;
	}
	return (calc);
}

int	ind_of_next(int *arr, int size, int nb)
{
	int	res;
	int	i;

	res = 0;
	i = 1;
	while (i < size)
	{
		if ((arr[i] - nb) < (arr[i - 1] - nb))
			res = i;
		i++;
	}
	return (res);
}