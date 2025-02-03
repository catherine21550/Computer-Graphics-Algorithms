#include "../../includes/cub3d.h"

char	*get_texture_path(char *str)
{
	int	i = 0;

	str += 2;
	while (ft_isspace(*str))
		str++;
	while (str[i++])
		if (str[i] == '\n')
			str[i] = '\0';
	return (str);
}

static int rgb_to_int(char **rgb)
{
	int	r;
	int	g;
	int	b;

	r = ft_atoi(rgb[0]);
	g = ft_atoi(rgb[1]);
	b = ft_atoi(rgb[2]);
	return ((r << 16) | (g << 8) | b);
}

int	get_color(char *str)
{
	int		color;
	char 	**rgb;
	int		i;

	color = 0;
	str++;
	while (ft_isspace(*str))
		str++;
	rgb = ft_split(str, ',');
	color = rgb_to_int(rgb);
	i = 0;
	while (rgb[i])
		free(rgb[i++]);
	free(rgb);
	return (color);
}
