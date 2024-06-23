#include "push_swap.h"
/*
int	find_second_min(int **arr, int *size)
{
	int min;
	int	min_2;
	int	i;

	min = (*arr)[find_min_index(arr, size)];
	if (find_min_index(arr, size) != 0)
	{
		min_2 = (*arr)[0];
		i = 1;
	}
	else
	{
		min_2 = (*arr)[1];
		i = 2;
	}
	while (i < (*size - 1))
	{
		if (min_2 > (*arr)[i] && min_2 != min)
			min_2 = (*arr)[i];
		i++;
	}
	return (i);
}
*/
int find_min_index(int **arr, int *size)
{
    int min;
    int i;
    int i_min;

	i = 0;
    min = (*arr)[i];
    while (i < (*size - 1))
    {
        if (min > (*arr)[i])
        {
            min = (*arr)[i];
            i_min = i;
        }
        i++;
    }
    return (i_min);
}

int find_max_index(int **arr, int *size)
{
    int max;
    int i;
    int i_max;

	i = 0;
    max = (*arr)[i];
    while (i < (*size - 1))
    {
        if (max < (*arr)[i])
        {
            max = (*arr)[i];
            i_max = i;
        }
        i++;
    }
    return (i_max);
}