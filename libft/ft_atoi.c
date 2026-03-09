/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuk <khuk@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 13:54:19 by khuk              #+#    #+#             */
/*   Updated: 2024/04/22 17:52:46 by khuk             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	atoiwithlimits(const char *nptr, int min, int i)
{
	unsigned long long int	res;

	res = 0;
	while (nptr[i] >= 48 && nptr[i] <= 57)
	{
		res = res * 10 + (nptr[i] - '0');
		if (res >= 9223372036854775807 && min == 1)
			return (-1);
		if (res >= 9223372036854775807 && min == -1)
			return (0);
		i++;
	}
	return (res * min);
}

int	ft_atoi(const char *nptr)
{
	int	min;
	int	i;

	min = 1;
	i = 0;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-')
	{
		min *= -1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	return (atoiwithlimits(nptr, min, i));
}
/*
int	main(void)
{
	const char	*str = "	-34567213";
	const char  *str1 = "+-34567213";
	const char  *str2 = "34567213";
	const char  *str3 = "-34567213";
	const char  *str4 = "+213";
	const char  *str5 = "     34567213";
	const char  *str6 = "-2147483648";
	const char  *str7 = "-9223372036854775808";
	const char  *str8 = "9223372036854775807";
	
	printf("My example is \"%s\"\n", str);
	printf("The actual atoi: %d\n", atoi(str));
	printf("My ft_atoi: %d\n", ft_atoi(str));
    printf("My example1 is \"%s\"\n", str1);
    printf("The actual atoi: %d\n", atoi(str1));
	printf("My ft_atoi: %d\n", ft_atoi(str1));
	printf("My example2 is \"%s\"\n", str2);
    printf("The actual atoi: %d\n", atoi(str2));
	printf("My ft_atoi: %d\n", ft_atoi(str2));
	printf("My example3 is \"%s\"\n", str3);
    printf("The actual atoi: %d\n", atoi(str3));
	printf("My ft_atoi: %d\n", ft_atoi(str3));
	printf("My example4 is \"%s\"\n", str4);
    printf("The actual atoi: %d\n", atoi(str4));
	printf("My ft_atoi: %d\n", ft_atoi(str4));
	printf("My example5 is \"%s\"\n", str5);
    printf("The actual atoi: %d\n", atoi(str5));
	printf("My ft_atoi: %d\n", ft_atoi(str5));
	printf("My example6 is \"%s\"\n", str6);
	printf("The actual atoi: %d\n", atoi(str6));
	printf("My ft_atoi: %d\n", ft_atoi(str6));
	printf("My example7 is \"%s\"\n", str7);
	printf("The actual atoi: %d\n", atoi(str7));
	printf("My ft_atoi: %d\n", ft_atoi(str7));
	printf("My example8 is \"%s\"\n", str8);
	printf("The actual atoi: %d\n", atoi(str8));
	printf("My ft_atoi: %d\n", ft_atoi(str8));

	return (0);
}
*/
