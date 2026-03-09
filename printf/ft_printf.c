/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuk <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 18:35:56 by khuk              #+#    #+#             */
/*   Updated: 2024/05/02 13:35:26 by khuk             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_checkstr(const char *str)
{
	int	i;
	int	persent;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != 0)
	{
		if (str[i] == '%')
		{
			persent = 1;
			if (!(ft_strchr("cspdiuxX%", str[i + 1])))
				return (0);
			i++;
		}
		i++;
	}
	return (persent);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	size_t	i;
	int		count;

	i = 0;
	va_start(args, format);
	count = 0;
	if (!(ft_checkstr(format)))
		return (-1);
	while (format[i] != 0)
	{
		if (format[i] == '%')
		{
			count += ft_check_specifiers(format[i + 1], &args);
			i++;
		}
		else
		{
			ft_putchar_fd(format[i], 1);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}
/*
// #include <stdio.h>
// #include <limits.h>

// int	main()
// {
// 	printf(" %p ", (void*)-1);
// 	printf("\nMy printf:\n");

// 	ft_printf(" %p ", (void*)-1);
// 	printf("\n\n");


// 	printf(" %p ", (void*)1);
// 	printf("\nMy printf:\n");

// 	ft_printf(" %p ", (void*)1);
// 	printf("\n\n");


// 	printf(" %p ", (void*)15);
// 	printf("\nMy printf:\n");

// 	ft_printf(" %p ", (void*)15);
// 	printf("\n\n");


// 	printf(" %p ", (void*)16);
// 	printf("\nMy printf:\n");

// 	ft_printf(" %p ", (void*)16);
// 	printf("\n\n");


// 	printf(" %p ", (void*)0);
// 	printf("\nMy printf:\n");

// 	ft_printf(" %p ", (void*)0);
// 	printf("\n\n");
// 	return (0);
// }
*/
