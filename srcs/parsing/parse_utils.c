#include "../../includes/cub3d.h"

bool     ft_isspace(char c)
{
    if ((c >= '\t' && c <= '\r') || c == ' ')
        return (true);
    return (false); 
}

void	free_array(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

int	count_digits(char *str)
{
	int	count;

	count = 0;
	while (*str)
	{
		if (ft_isdigit(*str))
			count++;
		str++;
	}
	return (count);
}
