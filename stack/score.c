#include "../push_swap.h"

void	assign_score(t_stack *stack_a, t_stack *stack_b, t_list *elt, int pos)
{
	int	score_a;
	int	score_b;
	int	rev_b;
	int	rev_a;

	score_a = find_moves(stack_a, elt->content, &rev_a);
	score_b = find_dst(pos, stack_b->size, &rev_b);
	elt->score = score_a + score_b;
}

int	find_best_score(t_stack *stack_a, t_stack *stack_b)
{
	t_list	*temp;
	int		curr_pos;
	int		min_score;
	int		best_pos;

	temp = stack_b->top;
	curr_pos = 0;
	best_pos = 0;
	assign_score(stack_a, stack_b, temp, curr_pos);
	min_score = temp->score;
	curr_pos++;
	temp = temp->next;
	while (temp)
	{
		assign_score(stack_a, stack_b, temp, curr_pos);
		if (temp->score < min_score)
		{
			min_score = temp->score;
			best_pos = curr_pos;
		}
		curr_pos++;
		temp = temp->next;
	}
	return (best_pos);
}
