SRC		=	main.c sort/main_sort.c sort/sort_utils.c ps_operations/push_swap_op.c ps_operations/rotate_op.c stack/score.c stack/stack_init.c stack/stack_check.c stack/stack_op.c sort/move_elt.c sort/sorting.c sort/sorting_help.c sort/sorting_three.c
PROG	=	push_swap
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
LIBDIR	=	./libft
LIB		=	$(LIBDIR)/libft.a

.PHONY:		all clean fclean re

all:		$(PROG)

$(LIB):
			make -C $(LIBDIR)

$(PROG):	$(LIB) $(SRC)
			$(CC) $(CFLAGS) $(SRC) -L $(LIBDIR) -lft -o $(PROG)

clean:
			rm -f */*.o

fclean:		clean
			rm -f $(PROG) */*.a

re:			fclean all
