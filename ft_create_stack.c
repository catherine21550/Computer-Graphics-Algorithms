/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuk <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 15:41:34 by khuk              #+#    #+#             */
/*   Updated: 2024/06/14 12:19:50 by khuk             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "printf/ft_printf.h"

int	ft_if_valid(char *str)
{
	int	i;
	
	i = 0;
	if (!str)
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
			return(0);
	}
	return(1);
}

int     ft_new_atoi(char *str)
{
	long	i;
	long	res;
	long	sign;
	
	i = 0;
	res = 0;
	sign = 1;
	if(str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while((str[i] >= '0' && str[i] <= '9') && str[i])
	{
		res = res * 10 + (str[i] - 48);
		i++;
	}
	return (res * sign);
}

int	*create_stack_a(int ac, char *av[])
{
	int	*my_stack;
	int	n;
	int	i;

	n = ac - 1;
	i = 0;
	my_stack = (int *)malloc(n * sizeof(int));
	if (!my_stack)
		return (NULL);
	while (i < n)
	{
		if (!ft_if_valid(av[1 + i]))
		{
			ft_printf("%s\n", "Error");
			return(free(my_stack), NULL);
		}
		my_stack[i] = ft_new_atoi(av[1 + i]);
		i++;
	}
	return (my_stack);
}

