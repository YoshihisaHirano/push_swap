#include "../push_swap.h"

static t_list	*extract_last(t_stack *stack)
{
	t_list	*prev;
	t_list	*temp;

	prev = NULL;
	temp = stack->top;
	while (temp->next)
	{
		prev = temp;
		temp = temp->next;
	}
	prev->next = NULL;
	stack->last = prev;
	return (temp);
}

void	rotate_one(t_stack *stack, int print_flag)
{
	t_list	*elt_to_move;

	if (stack->size < 2)
		return ;
	elt_to_move = stack->top;
	stack->last = stack->top;
	stack->top = (stack->top)->next;
	elt_to_move->next = NULL;
	ft_lstadd_back(&(stack->top), elt_to_move);
	if (print_flag)
	{
		if (stack->no == 1)
			write(1, "ra\n", 3);
		if (stack->no == 2)
			write(1, "rb\n", 3);
	}
}

void	rotate_both(t_stack *stack_a, t_stack *stack_b, int print_flag)
{
	rotate_one(stack_a, 0);
	rotate_one(stack_b, 0);
	if (print_flag)
		write(1, "rr\n", 3);
}

void	rr_one(t_stack *stack, int print_flag)
{
	t_list	*last_elt;

	if (stack->size < 2)
		return ;
	last_elt = extract_last(stack);
	ft_lstadd_front(&(stack->top), last_elt);
	if (print_flag)
	{
		if (stack->no == 1)
			write(1, "rra\n", 4);
		if (stack->no == 2)
			write(1, "rrb\n", 4);
	}
}

void	rr_both(t_stack *stack_a, t_stack *stack_b, int print_flag)
{
	rr_one(stack_a, 0);
	rr_one(stack_b, 0);
	if (print_flag)
		write(1, "rrr\n", 4);
}
