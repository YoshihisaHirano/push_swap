#include "checker.h"

void	exit_program(t_stack *stack_a, t_stack *stack_b)
{
	write(1, "Error\n", 6);
	ft_lstclear(&(stack_a->top));
	ft_lstclear(&(stack_b->top));
	exit(1);
}

void	perform_operations(t_stack *stack_a, t_stack *stack_b, char *op)
{
	if (!ft_strncmp(op, "sa", ft_strlen(op)))
		swap_one(stack_a, 0);
	else if (!ft_strncmp(op, "sb", ft_strlen(op)))
		swap_one(stack_b, 0);
	else if (!ft_strncmp(op, "pa", ft_strlen(op)))
		push_to_stack(stack_a, stack_b, 0);
	else if (!ft_strncmp(op, "pb", ft_strlen(op)))
		push_to_stack(stack_b, stack_a, 0);
	else if (!ft_strncmp(op, "ra", ft_strlen(op)))
		rotate_one(stack_a, 0);
	else if (!ft_strncmp(op, "rb", ft_strlen(op)))
		rotate_one(stack_b, 0);
	else if (!ft_strncmp(op, "rra", ft_strlen(op)))
		rr_one(stack_a, 0);
	else if (!ft_strncmp(op, "rrb", ft_strlen(op)))
		rr_one(stack_b, 0);
	else if (!ft_strncmp(op, "rrr", ft_strlen(op)))
		rr_both(stack_a, stack_b, 0);
	else if (!ft_strncmp(op, "rr", ft_strlen(op)))
		rotate_both(stack_a, stack_b, 0);
	else if (!ft_strncmp(op, "ss", ft_strlen(op)))
		swap_both(stack_a, stack_b, 0);
	else
		exit_program(stack_a, stack_b);
}

void	read_input(t_stack *stack_a, t_stack *stack_b)
{
	char	*read_line;

	while (get_next_line(0, &read_line) > 0)
	{
		if (*read_line)
			perform_operations(stack_a, stack_b, read_line);
		free(read_line);
	}
	if (*read_line)
		perform_operations(stack_a, stack_b, read_line);
	free(read_line);
}

int	main(int argc, char **argv)
{
	t_stack		stack_a;
	t_stack		stack_b;

	initialize_stack(&stack_a, 1);
	initialize_stack(&stack_b, 2);
	if (argc == 1)
		return (0);
	if (!(fill_stack(argc, argv, &(stack_a.top))))
		exit_program(&stack_a, &stack_b);
	check_sorted(&stack_a);
	read_input(&stack_a, &stack_b);
	check_sorted(&stack_a);
	check_sorted(&stack_b);
	if (stack_a.sorted && stack_b.size == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (0);
}
