/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_count_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuk <khuk@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 17:44:21 by khuk              #+#    #+#             */
/*   Updated: 2024/08/25 22:38:22 by khuk             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

int	ft_isspace(char c)
{
	return (c == ' ');
}

int	ft_isendornewl(char c)
{
	return (c == '\0' || c == '\n');
}

long	str_width(char *str)
{
	int		in_word;
	long	num;

	num = 0;
	while (!ft_isendornewl(*str))
	{
		in_word = 0;
		while (ft_isspace(*str) && !ft_isendornewl(*str))
			str++;
		while (!ft_isspace(*str) && !ft_isendornewl(*str))
		{
			if (!in_word)
			{
				in_word = 1;
				num++;
			}
			str++;
		}
		str++;
	}
	return (num);
}

long	count_lines(int fd, long *nums)
{
	int		lines;
	char	*new_line;

	lines = 0;
	new_line = get_next_line(fd);
	if (!new_line)
		return (0);
	*nums = str_width(new_line);
	if (!nums)
		return (free(new_line), 0);
	free (new_line);
	while (new_line != NULL)
	{
		new_line = get_next_line(fd);
		free (new_line);
		lines++;
	}
	new_line = NULL;
	return (lines);
}

long	lines_number(int ac, char *av[], long *nums, t_data *data)
{
	int		fd;
	long	lines;

	(void)ac;
	if ((fd = open(av[1], O_RDONLY)) == -1)
	{
		ft_printf("Error occurred: %s\n", strerror(errno));
		destroy_evrth(data);
		exit (1);
	}
	lines = count_lines(fd, nums);
	close(fd);
	return (lines);
}
/* 
void	store_map(int ac, char *av[], t_map *my_map)
{
	int	lines;

	lines = lines_number(ac, av);
	if (!lines)
		return (1)
}

int	main(int ac, char *av[])
{
	int	lines;
	char	str[3] = "o 1";

	lines = lines_number(ac, av);
	if (!lines)
		return (1);
	ft_printf("%d, %d, %d, %d\n", ft_isnum(str[0]), 
	ft_isnum(str[1]), ft_isnum(str[2]), ft_isendornewl(str[1]));
	return (0);
}

int	main(int ac, char *av[])
{
	int	fd;
	int	lines;
	int nums;
	
	nums = 0;
	fd = open(av[1], O_RDONLY);
	if (ac != 2)
		return (1);
	lines = count_lines(fd, &nums);
	ft_printf("I have %d lines\n I have %d numbers in line\n", lines, nums);
	close(fd);
	return(0);
} 
*/