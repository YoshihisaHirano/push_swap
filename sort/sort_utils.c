#include "../push_swap.h"

int	find_right_pos(t_stack *stack, int num)
{
	int		pos;
	t_list	*temp;
	int		min_pos;
	int		i;

	pos = 0;
	temp = stack->top;
	i = -1;
	min_pos = find_min(stack);
	if (num < stack->top->content && num > stack->last->content)
		return (0);
	pos = min_pos;
	while (i++ < min_pos)
		temp = temp->next;
	while (temp)
	{
		pos++;
		if (temp->content > num)
			break ;
		temp = temp->next;
	}
	return (pos);
}

int	find_pos_a(t_stack *stack, int num)
{
	int		pos;
	t_list	*temp;

	pos = 0;
	temp = stack->top;
	if (num > stack->top->content)
	{
		while (temp)
		{
			if (temp->content > num)
				return (pos);
			pos++;
			temp = temp->next;
		}
	}
	else
		pos = find_right_pos(stack, num);
	return (pos);
}

int	find_num_pos(t_stack *stack, int num)
{
	t_list	*temp;
	int		pos;

	pos = 0;
	temp = stack->top;
	while (temp)
	{
		if (temp->content == num)
			return (pos);
		pos++;
		temp = temp->next;
	}
	return (pos);
}

int	find_moves(t_stack *stack, int num, int *rev_flag)
{
	int	move_qty;

	move_qty = find_pos_a(stack, num);
	*rev_flag = 0;
	if (move_qty >= stack->size / 2 && stack->size > 4)
	{
		*rev_flag = 1;
		move_qty = stack->size - move_qty;
	}
	return (move_qty);
}

int	co_dst(int rev_a, int rev_b, int mov_a, int mov_b)
{
	if ((!rev_a && rev_b) || (!rev_b && rev_a) || (!mov_b || !mov_a))
		return (0);
	if (mov_b < mov_a)
		return (mov_b);
	else
		return (mov_a);
}
