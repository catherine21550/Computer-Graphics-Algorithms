#include "push_swap.h"
#include "printf/ft_printf.h"

int	main(int ac, char *av[])
{
	int	*my_stack;
	int *my_stack2 = NULL;
    int size_1 = ac - 1;
    int size_2 = 0;

	my_stack = create_stack_a(ac, av);
	if (!my_stack)
		return (1);
	if (ac == 2)
		size_1 = ft_counter(av[1], ' ');
	printf("My stack_a:\n");
	for (int i = 0; i < size_1; i++)
		ft_printf("%i\n", my_stack[i]);
	ft_printf("---------------------\n");
	printf("My stack_b:\n");
	for (int i = 0; i < size_2; i++)
		ft_printf("%i\n", my_stack2[i]);
	ft_printf("---------------------\n");
	sort_in_two(&my_stack, &my_stack2, &size_1, &size_2);
		printf("My stack_a after merging:\n");
	for (int i = 0; i < size_1; i++)
		ft_printf("%i\n", my_stack[i]);
	ft_printf("---------------------\n");
	printf("My stack_b after merging:\n");
	for (int i = 0; i < size_2; i++)
		ft_printf("%i\n", my_stack2[i]);
	ft_printf("---------------------\n");
	sort_small(&my_stack, &my_stack2, &size_1, &size_2);
	printf("My stack_a sorted:\n");
	for (int i = 0; i < size_1; i++)
		ft_printf("%i\n", my_stack[i]);
	ft_printf("---------------------\n");
	inf_node *inf = find_closest(my_stack, my_stack2, size_1, size_2);
	int size_arr = size_2;
	fill_one(inf, my_stack, size_arr);
	fill_two(inf, my_stack2, size_arr);
	for (int i = 0; i < size_arr; i++)
		ft_printf("nb:%i, ind_of_clos:%i, clos:%i, res_mvs:%i\n", inf[i].nb, inf[i].ind_clos, inf[i].closest, inf[i].res_mvs);
	ft_printf("---------------------\n");
	free (my_stack);
	free (my_stack2);
	free (inf);
	return (0);
}
