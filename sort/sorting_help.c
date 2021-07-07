#include "../push_swap.h"

int	check_three_sorted(t_stack *stack, int ord)
{
	if (stack->size == 1)
		return (1);
	else if (stack->size == 2 && stack->sorted)
		return (1);
	else if (((stack->top)->content < ((stack->top)->next)->content)
		&& ((stack->top)->content < (stack->last)->content)
		&& ((stack->last)->content > ((stack->top)->next)->content) && ord)
		return (1);
	else if (((stack->top)->content > ((stack->top)->next)->content)
		&& ((stack->top)->content > (stack->last)->content)
		&& ((stack->last)->content < ((stack->top)->next)->content) && !ord)
		return (1);
	return (0);
}

int	find_max_of_three(t_stack *stack)
{
	int	max;

	max = (stack->top)->content;
	if ((stack->top)->next->content > max)
		max = (stack->top)->next->content;
	if ((stack->last)->content > max)
		max = (stack->last)->content;
	return (max);
}

int	find_max_min(t_stack *stack, int flag)
{
	int		val;
	t_list	*temp;

	temp = stack->top;
	val = temp->content;
	while (temp)
	{
		if (flag && temp->content > val)
			val = temp->content;
		if (!flag && temp->content < val)
			val = temp->content;
		temp = temp->next;
	}
	return (val);
}

int	find_num(t_stack *stack, int pos)
{
	int		i;
	t_list	*temp;

	i = 0;
	temp = stack->top;
	while (i < pos)
	{
		temp = temp->next;
		i++;
	}
	return (temp->content);
}

int	find_min(t_stack *stack)
{
	int		min;
	int		pos_counter;
	t_list	*temp;
	int		pos;

	pos_counter = 0;
	pos = 0;
	temp = stack->top;
	min = temp->content;
	while (temp)
	{
		if (temp->content < min)
		{
			min = temp->content;
			pos = pos_counter;
		}
		pos_counter++;
		temp = temp->next;
	}
	return (pos);
}
