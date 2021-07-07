#include "../push_swap.h"

void	push_to_stack(t_stack *dst, t_stack *from, int print_flag)
{
	t_list	*elt_to_push;

	if (from->top == NULL || from->size == 0)
		return ;
	elt_to_push = from->top;
	from->top = (from->top)->next;
	ft_lstadd_front(&(dst->top), elt_to_push);
	dst->size++;
	from->size--;
	if (print_flag && dst->no == 1)
		write(1, "pa\n", 3);
	else if (print_flag && dst->no == 2)
		write(1, "pb\n", 3);
}

void	swap_one(t_stack *stack, int print_flag)
{
	t_list	*bottom_elt;
	t_list	*stack_top;

	if (stack->size < 2)
		return ;
	stack_top = stack->top;
	bottom_elt = stack_top->next;
	stack_top->next = bottom_elt->next;
	ft_lstadd_front(&(stack->top), bottom_elt);
	if (print_flag)
	{
		if (stack->no == 1)
			write(1, "sa\n", 3);
		if (stack->no == 2)
			write(1, "sb\n", 3);
	}
}

void	swap_both(t_stack *stack_a, t_stack *stack_b, int print_flag)
{
	swap_one(stack_a, 0);
	swap_one(stack_b, 0);
	if (print_flag)
		write(1, "ss\n", 3);
}
