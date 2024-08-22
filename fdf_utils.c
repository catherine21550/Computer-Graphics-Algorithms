#include "fdf.h"

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

int	ft_atoi_fdf(const char *nptr)
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

int main(int ac, char *av[])
{
    if (ac != 2)
        return (-1);
    ft_printf("My atoi_fdf: %d\n", ft_atoi_fdf(av[1]));
    return (0);
}