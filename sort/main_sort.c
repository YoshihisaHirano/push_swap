#include "../push_swap.h"

void	push_to_b(t_stack *stack_a, t_stack *stack_b)
{
	int	min;
	int	max;
	int	median;

	min = find_max_min(stack_a, 0);
	max = find_max_min(stack_a, 1);
	median = find_median(stack_a, stack_a->size, 2);
	while (stack_a->size != 2)
	{
		if ((stack_a->top)->content == max || (stack_a->top)->content == min)
			rotate_one(stack_a, 1);
		else
		{
			push_to_stack(stack_b, stack_a, 1);
			if (stack_b->top->content > median)
				rotate_one(stack_b, 1);
		}
	}
	if (stack_a->top->content < stack_a->top->next->content)
		swap_one(stack_a, 1);
	check_sorted(stack_a);
}

void	move_stacks(t_stack *stack_a, t_stack *stack_b, int best_pos, int num)
{
	int	rev_b;
	int	rev_a;
	int	mov_a;
	int	mov_b;
	int	i;

	i = 0;
	mov_b = find_dst(best_pos, stack_b->size, &rev_b);
	mov_a = find_moves(stack_a, num, &rev_a);
	if (co_dst(rev_a, rev_b, mov_a, mov_b) > 0)
	{
		while (!rev_a && !rev_b && i++ < co_dst(rev_a, rev_b, mov_a, mov_b))
			rotate_both(stack_a, stack_b, 1);
		while (rev_a && rev_b && i++ < co_dst(rev_a, rev_b, mov_a, mov_b))
			rr_both(stack_a, stack_b, 1);
		if (mov_a >= co_dst(rev_a, rev_b, mov_a, mov_b))
			mov_a -= co_dst(rev_a, rev_b, mov_a, mov_b);
	}
	stack_rotate(stack_a, rev_a, mov_a);
	move_to_top(stack_b, find_num_pos(stack_b, num));
}

void	yas(t_stack *stack_a, t_stack *stack_b)
{
	int	best_pos;
	int	next_num;

	while (stack_b->size > 0)
	{
		check_sorted(stack_a);
		if (stack_b->top->content < stack_a->top->content
			&& stack_b->top->content > stack_a->last->content)
			push_to_stack(stack_a, stack_b, 1);
		else
		{
			best_pos = find_best_score(stack_a, stack_b);
			next_num = find_num(stack_b, best_pos);
			move_stacks(stack_a, stack_b, best_pos, next_num);
			push_to_stack(stack_a, stack_b, 1);
		}
	}
}

void	sort_main(t_stack *stack_a, t_stack *stack_b)
{
	int	min;

	push_to_b(stack_a, stack_b);
	yas(stack_a, stack_b);
	min = find_min(stack_a);
	while (!stack_a->sorted)
	{
		if (min < stack_a->size / 2)
			rotate_one(stack_a, 1);
		else
			rr_one(stack_a, 1);
		check_sorted(stack_a);
	}
}
