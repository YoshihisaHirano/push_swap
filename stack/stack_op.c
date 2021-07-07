#include "../push_swap.h"

void	check_stacks(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size > 0)
		check_sorted(stack_a);
	if (stack_b->size > 0)
		check_sorted(stack_b);
	if (stack_b->size == 3 && !stack_b->sorted)
		sort_three(stack_b);
	if (stack_a->size == 3 && !stack_a->sorted)
		sort_three(stack_a);
	if (stack_a->size == 2 && !stack_a->sorted)
	{
		swap_one(stack_a, 1);
		stack_a->sorted = 1;
	}
	if (stack_b->size == 2 && !stack_b->sorted)
	{
		swap_one(stack_b, 1);
		stack_b->sorted = 1;
	}
}

void	rotate_stacks(t_stack *stack_a, t_stack *stack_b)
{
	while (rotate_decision(stack_a) && rotate_decision(stack_b))
		rotate_both(stack_a, stack_b, 1);
	while (rotate_decision(stack_a))
		rotate_one(stack_a, 1);
	while (rotate_decision(stack_b))
		rotate_one(stack_b, 1);
}

void	rr_stacks(t_stack *stack_a, t_stack *stack_b)
{
	while (rr_decision(stack_a) && rr_decision(stack_b))
		rr_both(stack_a, stack_b, 1);
	while (rr_decision(stack_a))
		rr_one(stack_a, 1);
	while (rr_decision(stack_b))
		rr_one(stack_b, 1);
}

void	swap_stacks(t_stack *stack_a, t_stack *stack_b)
{
	while (swap_decision(stack_a) && swap_decision(stack_b))
		swap_both(stack_a, stack_b, 1);
	while (swap_decision(stack_a))
		swap_one(stack_a, 1);
	while (swap_decision(stack_b))
		swap_one(stack_b, 1);
}
