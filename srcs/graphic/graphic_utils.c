/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuk <khuk@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 13:11:40 by khuk              #+#    #+#             */
/*   Updated: 2025/02/14 21:07:04 by khuk             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphic.h"

int	ft_abs(int i)
{
	int	j;

	j = i;
	if (i < 0)
		j *= -1;
	return (j);
}
int	ft_sign_dda(double i)
{
	int	res;

	res = 0;
	if (i >= 0)
		res = 1;
	else
		res = -1;
	return (res);
}
