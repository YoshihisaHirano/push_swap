#include "../push_swap.h"

void	initialize_stack(t_stack *stack, int no)
{
	stack->top = NULL;
	stack->last = NULL;
	stack->size = 0;
	stack->sorted = 1;
	if (no == 1)
		stack->order = 1;
	else
		stack->order = 0;
	stack->no = no;
}

void	check_sorted(t_stack *stack)
{
	t_list	*curr;
	t_list	*prev;
	int		qty;

	prev = NULL;
	curr = stack->top;
	qty = 0;
	stack->sorted = 1;
	if (!curr)
		return ;
	while (curr->next)
	{
		qty++;
		prev = curr;
		curr = curr->next;
		if ((prev->content > curr->content && stack->order)
			|| (prev->content < curr->content && !stack->order))
			stack->sorted = 0;
	}
	qty++;
	stack->size = qty;
	stack->last = curr;
}

void	insertion_sort(int *arr, int arr_len)
{
	int	i;
	int	j;
	int	temp;

	i = 1;
	while (i < arr_len)
	{
		temp = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > temp)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = temp;
		i++;
	}
}

int	find_median(t_stack *stack, int qty, int div)
{
	int		*arr;
	int		i;
	t_list	*temp;
	int		res;

	if (qty < 2)
		return ((stack->top)->content);
	arr = malloc(qty * sizeof(int));
	i = 0;
	temp = stack->top;
	while (i < qty && temp)
	{
		arr[i] = temp->content;
		i++;
		temp = temp->next;
	}
	insertion_sort(arr, qty);
	i = qty / div - 1;
	res = arr[i];
	if (qty <= 4)
		res = arr[1];
	free(arr);
	return (res);
}
