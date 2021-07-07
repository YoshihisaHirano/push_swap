#include "../push_swap.h"

int	swap_decision(t_stack *stck)
{
	if (stck->size > 1)
	{
		if (stck->order && ((stck->top)->next)->content < (stck->top)->content)
			return (1);
		if (((stck->top)->next)->content > (stck->top)->content && !stck->order)
			return (1);
	}
	return (0);
}

int	rotate_decision(t_stack *stack)
{
	if (stack->size > 2)
	{
		if ((stack->top)->content > (stack->last)->content && stack->order)
			return (1);
		if ((stack->top)->content < (stack->last)->content && !stack->order)
			return (1);
	}
	return (0);
}

int	rr_decision(t_stack *stck)
{
	if (stck->size > 2)
	{
		if (stck->order && (stck->last)->content < (stck->top)->content)
			return (1);
		if (stck->order && stck->size == 3
			&& (((stck->top)->next)->content > (stck->top)->content)
			&& ((stck->top)->next)->content > (stck->last)->content)
			return (1);
		if (!stck->order && (stck->last)->content > (stck->top)->content)
			return (1);
		if (!stck->order && stck->size == 3
			&& (((stck->top)->next)->content < (stck->top)->content)
			&& ((stck->top)->next)->content < (stck->last)->content)
			return (1);
	}
	return (0);
}

void	sort_three(t_stack *stack)
{
	int	max;

	max = find_max_of_three(stack);
	if ((stack->top)->content == max && stack->order)
		rotate_one(stack, 1);
	if (!stack->order && (stack->last)->content == max)
		rr_one(stack, 1);
	while (!(check_three_sorted(stack, stack->order)))
	{
		if (swap_decision(stack))
			swap_one(stack, 1);
		if (rr_decision(stack))
			rr_one(stack, 1);
		if (rotate_decision(stack))
			rotate_one(stack, 1);
		if (rr_decision(stack))
			rr_one(stack, 1);
	}
	stack->sorted = 1;
}
