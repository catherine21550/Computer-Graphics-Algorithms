/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuk <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 15:41:34 by khuk              #+#    #+#             */
/*   Updated: 2024/06/17 14:23:14 by khuk             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_check_double(int ac, char *av[])
{
	int	i;
	int	j;
	int last;

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

int	ft_if_valid(char *str)
{
	int	i;

	i = 0;
	if (!str)
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

int	*create_stack_a(int ac, char *av[])
{
	int	*my_stack;
	int	n;
	int	i;
	char	*str;

	if (ac == 1)
		
	if (ac == 2)
	{
		str = ft_strjoin("first ", av[1]);
		n = ft_counter(str, " ") - 1;
		av = ft_split(str, " ");
	}
	else
		n = ac - 1;
	i = 0;
	my_stack = (int *)malloc(n * sizeof(int));
	if (!my_stack)
		return (NULL);
	if (!ft_check_double(n + 1, av))
	{
		ft_printf("%s\n", "Error");
		return (free(my_stack), NULL);
	}
	while (i < n)
	{
		if (!ft_if_valid(av[1 + i]))
		{
			ft_printf("%s\n", "Error");
			return (free(my_stack), NULL);
		}
		my_stack[i] = ft_new_atoi(av[1 + i]);
		i++;
	}
	return (my_stack);
}