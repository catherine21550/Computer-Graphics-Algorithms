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
	for (int i = 0; i < size_1; i++)
		ft_printf("%i\n", my_stack[i]);
	ft_printf("---------------------\n");
	ft_push_a(&my_stack, &my_stack2, &size_1, &size_2);
	for (int i = 0; i < size_1; i++)
		ft_printf("%i\n", my_stack[i]);
	ft_printf("---------------------\n");
	for (int i = 0; i < size_2; i++)
		ft_printf("%i\n", my_stack2[i]);
	ft_printf("---------------------\n");
	ft_rev_rotate_rrr(&my_stack, &my_stack2, &size_1, &size_2);
	for (int i = 0; i < size_1; i++)
		ft_printf("%i\n", my_stack[i]);
	ft_printf("---------------------\n");
	for (int i = 0; i < size_2; i++)
		ft_printf("%i\n", my_stack2[i]);
	free (my_stack);
	free (my_stack2);
	return (0);
}
