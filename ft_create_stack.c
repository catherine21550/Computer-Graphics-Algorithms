/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuk <khuk@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 15:41:34 by khuk              #+#    #+#             */
/*   Updated: 2024/07/03 23:53:44 by khuk             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_split(char **arr)
{
	int	j;

	j = 0;
	if (arr == NULL)
		return ;
	while (arr[j])
	{
		free (arr[j]);
		j++;
	}
	free(arr);
}

int	ft_fillarray(char **str_arr, t_stack *arr, int ac)
{
	int	i;

	(void)ac;
	i = 0;
	while (i < arr->size)
	{
		if (!ft_if_valid(str_arr[1 + i]) || !ft_check_limits(str_arr[1 + i]))
		{
			ft_printf("%s\n", "Error");
			free (arr->stack);
			arr->stack = NULL;
			return (0);
		}
		arr->stack[i] = ft_new_atoi(str_arr[1 + i]);
		i++;
	}
	return (1);
}

char	**process_argv(char *str, int *n)
{
	char	*str_new;
	char	**new;

	if (*str == '\0')
		str = "empty";
	str_new = ft_strjoin("first ", str);
	if (!str_new)
		return (NULL);
	*n = ft_counter(str_new, ' ') - 1;
	new = ft_split(str_new, ' ');
	if (!new)
		return (free(str_new), NULL);
	free(str_new);
	return (new);
}

int	ft_new_stack(t_stack *new_stack, int size)
{
	if (size == 0)
		return (0);
	else
	{
		new_stack->size = size;
		new_stack->stack = (int *)malloc(sizeof(int) * size);
		if (!new_stack->stack)
			return (0);
	}
	return (1);
}

int	create_stack_a(t_stack *my_stack, int ac, char *av[])
{
	int		n;
	char	**new_av;

	new_av = NULL;
	n = ac - 1;
	if (ac == 2)
	{
		new_av = process_argv(av[1], &n);
		if (!new_av)
			return (ft_printf("%s\n", "Error"), 0);
		av = new_av;
	}
	if (!ft_new_stack(my_stack, n))
		return (free_split(new_av), 0);
	if (!ft_check_double(n + 1, av))
	{
		if (ac == 2)
			free_split(av);
		return (ft_printf("%s\n", "Error"), 0);
	}
	if (!ft_fillarray(av, my_stack, ac))
		return (free_split(new_av), 0);
	return (free_split(new_av), 1);
}
/*
int	main(int ac, char *av[])
{
	t_stack	my_stack;
	int 	i;
	
	if (ac < 2)
		return 1;
	if (!create_stack_a(&my_stack, ac, av))
		return (1);
	i = 0;
	ft_printf("Size is: %i\n", my_stack.size);
	while (i < my_stack.size)
	{
		ft_printf("%i\n", my_stack.stack[i]);
		i++;
	}
	free(my_stack.stack);
	return (0);
} */