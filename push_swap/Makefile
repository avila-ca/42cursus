SRC = src/push_swap.c\
	  src/utils.c\
	  src/lists.c\
	  src/checks.c\
	  src/movements.c\
	  src/engines.c\
	  src/find_positions.c\
	  src/costs.c\
	  src/sorter.c\

OBJ = $(SRC:.c=.o)
DEPS = $(SRC:.c=.d)

CFLAGS = -Wall -Wextra -Werror -MMD

HEADER = -I src -I libft

LIBFT = ./libft/libft.a

NAME = push_swap

LDPATH = -L libft

LDLIB = -lft
LIB = libft/libft.a

%.o : %.c
	$(CC) -c $(CFLAGS) $(HEADER) $< -o $@

all: make_lib $(NAME)

make_lib:
	make -C libft

-include $(DEPS)
$(NAME):	$(OBJ) $(LIB)
	$(CC) $(CFLAGS) $(LDPATH) $(LDLIB) $(FRAMES) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ) 
	make clean -C libft

fclean:	clean
	$(RM) $(NAME) $(DEPS)
	make fclean -C libft

re:	fclean
	$(MAKE)

.PHONY: all make_lib clean fclean re

