#include "push_swap.h"

void	exit_program(t_stack *stack)
{
	write(1, "Error\n", 6);
	ft_lstclear(&(stack->top));
	exit(1);
}

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;

	initialize_stack(&stack_a, 1);
	initialize_stack(&stack_b, 2);
	if (argc == 1)
		return (0);
	if (!(fill_stack(argc, argv, &(stack_a.top))))
		exit_program(&stack_a);
	check_sorted(&stack_a);
	if (stack_a.sorted)
	{
		ft_lstclear(&(stack_a.top));
		return (0);
	}
	if (stack_a.size > 10)
		sort_main(&stack_a, &stack_b);
	else
		sort_small(&stack_a, &stack_b);
	ft_lstclear(&(stack_a.top));
	return (0);
}
