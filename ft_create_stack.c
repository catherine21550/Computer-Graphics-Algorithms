/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuk <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 15:41:34 by khuk              #+#    #+#             */
/*   Updated: 2024/06/20 15:50:34 by khuk             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_check_double(int ac, char *av[])
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

static void	free_split(char **arr)
{
	int	j;

	j = 0;
	while (arr[j])
	{
		free (arr[j]);
		j++;
	}
	free(arr);
}

int	ft_fillarray(char **str_arr, int *arr, int size, int ac)
{
	int	i;
	
	i = 0;
	while (i < size)
	{
		if (!ft_if_valid(str_arr[1 + i]))
		{
			ft_printf("%s\n", "Error");
			if (ac == 2)
				free_split(str_arr);
			free (arr);
			return (0);
		}
		arr[i] = ft_new_atoi(str_arr[1 + i]);
		i++;
	}
	return (1);
}

void	process_argv(char *av[], int *n) 
{
	char *str;
	
	str = ft_strjoin("first ", av[1]);
	if (str == NULL)
		return ;
	*n = ft_counter(str, ' ') - 1;
	av = ft_split(str, ' ');
	free(str);
}

int	*create_stack_a(int ac, char *av[])
{
	int		*my_stack;
	int		n;
	char	*str;

	n = ac - 1;
	if (ac == 2)
	{
		str = ft_strjoin("first ", av[1]);
		n = ft_counter(str, ' ') - 1;
		av = ft_split(str, ' ');
		free(str);
		//process_argv(av, &n);
	}
	my_stack = (int *)malloc(n * sizeof(int));
	if (!my_stack)
		return (NULL);
	if (!ft_check_double(n + 1, av))
	{
		if (ac == 2)
			free_split(av);
		return (ft_printf("%s\n", "Error"), free(my_stack), NULL);
	}
	if (!ft_fillarray(av, my_stack, n, ac))
		return (NULL);
	if (ac == 2)
		free_split(av);
	return (my_stack);
}
