#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_stack
{
	int		sorted;
	int		order;
	int		size;
	int		no;
	t_list	*top;
	t_list	*last;
}				t_stack;

int		fill_stack(int argc, char **argv, t_list **stack);
void	initialize_stack(t_stack *stack, int no);
void	check_sorted(t_stack *stack);
void	push_to_stack(t_stack *dst, t_stack *from, int print_flag);
void	swap_one(t_stack *stack, int print_flag);
void	swap_both(t_stack *stack_a, t_stack *stack_b, int print_flag);
void	rotate_one(t_stack *stack, int print_flag);
void	rotate_both(t_stack *stack_a, t_stack *stack_b, int print_flag);
void	rr_one(t_stack *stack, int print_flag);
void	rr_both(t_stack *stack_a, t_stack *stack_b, int print_flag);
int		check_three_sorted(t_stack *stack, int ord);
int		find_max_of_three(t_stack *stack);
void	sort_three(t_stack *stack);
int		swap_decision(t_stack *stack);
int		rotate_decision(t_stack *stack);
int		rr_decision(t_stack *stck);
int		find_median(t_stack *stack, int qty, int div);
void	check_stacks(t_stack *stack_a, t_stack *stack_b);
void	rotate_stacks(t_stack *stack_a, t_stack *stack_b);
void	rr_stacks(t_stack *stack_a, t_stack *stack_b);
void	swap_stacks(t_stack *stack_a, t_stack *stack_b);
int		move_to_top(t_stack *stack, int	elt_pos);
int		find_dst(int elt_pos, int stack_size, int *rev_flag);
void	sort_small(t_stack *stack_a, t_stack *stack_b);
int		find_pos_a(t_stack *stack, int num);
void	push_to_b(t_stack *stack_a, t_stack *stack_b);
int		find_best_score(t_stack *stack_a, t_stack *stack_b);
void	yas(t_stack *stack_a, t_stack *stack_b);
int		find_max_min(t_stack *stack, int flag);
int		find_moves(t_stack *stack, int num, int *rev_flag);
int		find_min(t_stack *stack);
int		find_num(t_stack *stack, int pos);
int		find_num_pos(t_stack *stack, int num);
int		co_dst(int rev_a, int rev_b, int mov_a, int mov_b);
void	sort_main(t_stack *stack_a, t_stack *stack_b);
void	stack_rotate(t_stack *stack, int rev_flag, int move_qty);

#endif
