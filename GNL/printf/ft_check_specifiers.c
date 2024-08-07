/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_specifiers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuk <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 19:16:08 by khuk              #+#    #+#             */
/*   Updated: 2024/05/01 19:55:02 by khuk             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_specifiers(char c, va_list *args)
{
	int	count;

	if (c == 'c')
		count = ft_printchar(va_arg(*args, int), 1);
	if (c == 's')
		count = ft_printstr(va_arg(*args, char *), 1);
	if (c == 'p')
		count = ft_print_ptr(va_arg(*args, void *));
	if (c == 'd' || c == 'i')
		count = ft_printnbr(va_arg(*args, int), 1);
	if (c == 'u')
		count = ft_printunbr(va_arg(*args, int), 1);
	if (c == 'x')
		count = ft_printhex(va_arg(*args, int));
	if (c == 'X')
		count = ft_printhexbig(va_arg(*args, int));
	if (c == '%')
		count = ft_printchar('%', 1);
	return (count);
}
