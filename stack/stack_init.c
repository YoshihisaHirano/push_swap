#include "../push_swap.h"

void	*free_char_arr(char **arr, size_t index)
{
	size_t	i;

	i = 0;
	while (i < index)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}

int	check_numeric(char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
	{
		if (!(ft_isdigit(*str)))
			return (0);
		str++;
	}
	return (1);
}

static int	add_if_no_dupl(t_list **begin, int num)
{
	t_list	*new_elt;
	t_list	*temp;

	temp = *begin;
	while (temp)
	{
		if (temp->content == num)
			return (0);
		temp = temp->next;
	}
	new_elt = ft_lstnew(num);
	if (!new_elt)
		return (0);
	ft_lstadd_back(begin, new_elt);
	return (1);
}

char	**parse_args(int argc, char **argv, int *qty)
{
	char	**str;
	int		i;
	char	**temp;

	i = 0;
	if (argc == 2)
	{
		str = ft_split(argv[1], ' ');
		temp = str;
		while (temp[i])
			i++;
		*qty = i;
	}
	else
	{
		str = argv;
		*qty = argc;
	}
	return (str);
}

int	fill_stack(int argc, char **argv, t_list **stack)
{
	int		i;
	int		overflow_flag;
	int		num;
	char	**str;
	int		qty;

	i = 0;
	overflow_flag = 1;
	str = parse_args(argc, argv, &qty);
	if (qty == argc)
		i++;
	while (i < qty)
	{
		if (!(check_numeric(str[i])))
			return (0);
		num = ft_atoi(str[i], &overflow_flag);
		if (overflow_flag == -1)
			return (0);
		if (!(add_if_no_dupl(stack, num)))
			return (0);
		i++;
	}
	if (qty != argc)
		free_char_arr(str, qty + 1);
	return (1);
}
