#include "../push_swap.h"

int	find_dst(int elt_pos, int stack_size, int *rev_flag)
{
	int	dst;
	int	middle;

	middle = stack_size / 2;
	if (elt_pos > middle)
	{
		dst = stack_size - elt_pos;
		*rev_flag = 1;
	}
	else
	{
		dst = elt_pos;
		*rev_flag = 0;
	}
	return (dst);
}

int	move_to_top(t_stack *stack, int	elt_pos)
{
	int	rev_flag;
	int	dst;
	int	i;

	i = 0;
	dst = find_dst(elt_pos, stack->size, &rev_flag);
	if (rev_flag)
	{
		while (i < dst)
		{
			rr_one(stack, 1);
			i++;
		}
	}
	else
	{
		while (i < dst)
		{
			rotate_one(stack, 1);
			i++;
		}
	}
	return (rev_flag);
}

void	stack_rotate(t_stack *stack, int rev_flag, int move_qty)
{
	int	i;

	i = 0;
	while (!rev_flag && i++ < move_qty)
		rotate_one(stack, 1);
	while (rev_flag && i++ < move_qty)
		rr_one(stack, 1);
}
