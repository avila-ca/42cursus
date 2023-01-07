# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avila-ca <avila-ca@student.42barcelona.co  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/01 16:13:45 by avila-ca          #+#    #+#              #
#    Updated: 2022/03/05 18:06:31 by avila-ca         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRC = libftprintf.c ft_checking.c ft_putting.c

OBJ = $(SRC:.c=.o)

NAME = libftprintf.a

FLAGS = -Wall -Werror -Wextra

CC = gcc

all : $(NAME)

${NAME}:	${OBJ}
		${MAKE} -C ./libft all
		cp ./libft/libft.a ${NAME}
		ar -src ${NAME} ${OBJ}

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all
