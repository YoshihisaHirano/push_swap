SRC		=	main.c gnl/get_next_line.c gnl/get_next_line_utils.c ../stack/stack_check.c ../ps_operations/push_swap_op.c ../ps_operations/rotate_op.c ../stack/stack_init.c
PROG	=	checker
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
LIBDIR	=	../libft
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