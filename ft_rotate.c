/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuk <khuk@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 20:53:44 by khuk              #+#    #+#             */
/*   Updated: 2024/06/17 09:20:20 by khuk             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_rotate(int **my_stack, int *size)
{
	int	temp;
	int	i;

	temp = (*my_stack)[0];
	i = 0;
	while (i <= (*size - 1 - 1))
	{
		(*my_stack)[i] = (*my_stack)[i + 1];
		i++;
	}
	(*my_stack)[*size - 1] = temp;
}

int	ft_rotate_a(int **my_stack, int *size)
{
	if (*size <= 0 || *my_stack == NULL)
		return (0);
	ft_rotate(my_stack, size);
	write(1, "ra\n", 3);
	return (1);
}

int	ft_rotate_b(int **my_stack, int *size)
{
	if (*size <= 0 || *my_stack == NULL)
		return (0);
	ft_rotate(my_stack, size);
	write(1, "rb\n", 3);
	return (1);
}

int	ft_rotate_rr(int **my_stack_a, int **my_stack_b, int *size_a, int *size_b)
{
	if (*size_a <= 0 || !(*my_stack_a) || *size_b <= 0 || !(*my_stack_a))
		return (0);
	ft_rotate(my_stack_a, size_a);
	ft_rotate(my_stack_b, size_b);
	write(1, "rr\n", 3);
	return (1);
}
