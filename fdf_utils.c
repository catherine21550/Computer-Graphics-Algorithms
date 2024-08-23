/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuk <khuk@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 17:02:04 by khuk              #+#    #+#             */
/*   Updated: 2024/08/23 17:02:14 by khuk             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	str_isnum(char	*str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
	}
	return (1);
}

int	ft_abs(int i)
{
	int	j;

	j = i;
	if (i < 0)
		j *= -1;
	return (j);
}

void	my_put_pixel(t_data *d, int x, int y, int color)
{
	int		i;

	if (x < 0 || y < 0 || x > d->win_w || y > d->win_h)
		return ;
	i = (d->img.size_line * y) + ((d->img.bits_per_pixel / 8) * x);
	*((unsigned int *)(i + d->img.ptr_imgbit)) = color;
}

void	solid_color(t_data *d, int x, int y)
{
	int		i[2];

	i[0] = -1;
	while (++i[0] < y)
	{
		i[1] = -1;
		while (++i[1] < x)
			my_put_pixel(d, i[1], i[0], 0x000000);
	}
}
/* 
int main(int ac, char *av[])
{
    if (ac != 2)
        return (-1);
    ft_printf("My atoi_fdf: %d\n", ft_atoi_fdf(av[1]));
    return (0);
} */
