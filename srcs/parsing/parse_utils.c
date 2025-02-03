
#include "../../includes/cub3d.h"

bool     ft_isspace(char c)
{
    if ((c >= '\t' && c <= '\r') || c == ' ')
        return (true);
    return (false); 
}
