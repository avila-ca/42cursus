SRC = src/so_long.c\
	  src/errors_argv.c\
	  src/errors.c\
	  src/errors_path.c\
	  src/errors_path_next.c\
	  src/single_move.c\
	  src/move.c\
	  src/check_directions.c\
	  src/put_image.c\
	  gnl/get_next_line.c\
	  gnl/get_next_line_utils.c\

SRC_BONUS = src_bonus/so_long_bonus.c\
			src_bonus/errors_argv_bonus.c\
			src_bonus/errors_bonus.c\
			src_bonus/errors_path_bonus.c\
			src_bonus/errors_path_next_bonus.c\
			src_bonus/single_move_bonus.c\
			src_bonus/move_bonus.c\
			src_bonus/check_directions_bonus.c\
			src_bonus/put_image_bonus.c\
 			src_bonus/enemies_bonus.c\
			src_bonus/enemy_frames_bonus.c\
			src_bonus/enemy_move_bonus.c\
			gnl/get_next_line.c\
			gnl/get_next_line_utils.c\

OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)
DEPS = $(SRC:.c=.d)
DEPS_BONUS = $(SRC_BONUS:.c=.d)


CFLAGS = -Wall -Wextra -Werror -MMD

HEADER = -I src -I src_bonus -I libft -I mlx -I gnl

LIBFT = ./libft/libft.a

CC = gcc

NAME = so_long

MANDA = .manda

NAME_BONUS = so_long_bonus

NORM = norminette -R CheckForbiddenSourceHeader

LDPATH = -L mlx -L libft
LDLIBS = -lmlx -lft
FRAMES = -framework OpenGL -framework Appkit 
LIBS = libft/libft.a mlx/libmlx.a

%.o : %.c
	$(CC) -c $(CFLAGS) $(HEADER)  $< -o $@

all: make_libs	$(NAME)

bonus: make_libs	$(NAME_BONUS)

make_libs:
	make -C mlx
	make -C libft

-include $(DEPS)
$(NAME):	$(OBJ) $(LIBS)
	$(CC) $(CFLAGS) $(LDPATH) $(LDLIBS) $(FRAMES) $(OBJ)  -o $(NAME)

-include $(DEPS_BONUS)
$(NAME_BONUS):	$(OBJ_BONUS) $(LIBS)  
	$(CC) $(CFLAGS) $(LDPATH) $(LDLIBS) $(FRAMES) $(OBJ_BONUS)  -o $(NAME_BONUS)

clean:	
	$(RM) $(OBJ) $(OBJ_BONUS)
	make clean -C libft
	make clean -C mlx

fclean: clean
	$(RM) $(NAME) $(NAME_BONUS) $(DEPS) $(DEPS_BONUS)
	make fclean -C libft

re: fclean
	$(MAKE)

re_bonus: fclean
	$(MAKE) bonus	

.PHONY: all bonus make_libs clean fclean re re_bonus
