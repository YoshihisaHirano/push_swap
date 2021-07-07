#include "../push_swap.h"

void	sort_small(t_stack *stack_a, t_stack *stack_b)
{
	check_stacks(stack_a, stack_b);
	if (stack_a->sorted && stack_b->size == 0)
		return ;
	swap_stacks(stack_a, stack_b);
	rr_stacks(stack_a, stack_b);
	rotate_stacks(stack_a, stack_b);
	check_sorted(stack_a);
	if (stack_a->sorted && stack_b->size == 0)
		return ;
	if (stack_a->sorted && stack_b->size > 0)
	{
		push_to_stack(stack_a, stack_b, 1);
		sort_small(stack_a, stack_b);
	}
	else
	{
		push_to_stack(stack_b, stack_a, 1);
		sort_small(stack_a, stack_b);
	}
}
