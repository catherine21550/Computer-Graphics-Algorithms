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
	if (size_1 > 4)
		sort_in_two(&my_stack, &my_stack2, &size_1, &size_2);
	sort_small(&my_stack, &my_stack2, &size_1, &size_2);
	printf("My stack_a sorted:\n");
	for (int i = 0; i < size_1; i++)
		ft_printf("%i\n", my_stack[i]);
	ft_printf("---------------------\n");
	ft_sort_big(my_stack, size_1, my_stack2, size_2);
	printf("My stack_a sorted:\n");
	for (int i = 0; i < size_1; i++)
		ft_printf("%i\n", my_stack[i]);
	ft_printf("---------------------\n");
	free (my_stack);
	free (my_stack2);
	return (0);
}
