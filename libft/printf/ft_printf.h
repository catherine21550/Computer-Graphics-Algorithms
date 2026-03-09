/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuk <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 19:13:46 by khuk              #+#    #+#             */
/*   Updated: 2024/05/02 13:36:04 by khuk             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stddef.h>
# include "../libft.h"

int	ft_printf(const char *format, ...);
int	ft_check_specifiers(char c, va_list *args);
int	ft_printchar(char c, int fd);
int	ft_printhex(int nbr);
int	ft_printhexbig(int nbr);
int	ft_printnbr(long int nb, int fd);
int	ft_print_ptr(void *ptr);
int	ft_printstr(char *s, int fd);
int	ft_printunbr(unsigned int nb, int fd);

#endif
