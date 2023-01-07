# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avila-ca <avila-ca@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/14 17:02:02 by avila-ca          #+#    #+#              #
#    Updated: 2022/08/23 10:57:04 by avila-ca         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



SRC = server.c  

SRC2 = client.c

SRC_BONUS = server_bonus.c

SRC2_BONUS = client_bonus.c

OBJ = $(SRC:server.c=server.o)

OBJ2 = $(SRC2:client.c=client.o)

OBJ_BONUS = $(SRC_BONUS:server_bonus.c=server_bonus.o)

OBJ2_BONUS = $(SRC2_BONUS:client_bonus.c=client_bonus.o)

CFLAGS = -Wall -Werror -Wextra

NAME = server

NAME2 = client

NAME_BONUS = server_bonus

NAME2_BONUS = client_bonus

%.o : %.c
	$(CC)  -c $< -o $@


all: $(NAME)
	
$(NAME): $(OBJ) $(OBJ2)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	cc $(CFLAGS)  $(OBJ2) -o $(NAME2)

bonus:	$(OBJ_BONUS) $(OBJ2_BONUS)
	cc $(CFLAGS) $(OBJ_BONUS) -o $(NAME_BONUS) 
	cc $(CFLAGS) $(OBJ2_BONUS) -o $(NAME2_BONUS)
	touch $@

test_server: $(OBJ)
	cc $(CFLAGS) $(OBJ) -o $(NAME)
	./$(NAME)

test_client: $(OBJ2)
	cc $(CFLAGS) $(OBJ2) -o $(NAME2)

test_client_b: $(OBJ2_BONUS)
	cc $(CFLAGS) $(OBJ2_BONUS) -o $(NAME2_BONUS)

clean:	
	$(RM) $(OBJ2_BONUS)  $(OBJ_BONUS) $(OBJ2) $(OBJ) bonus 
 


fclean: clean
	$(RM) $(NAME) $(NAME2)
	$(RM) $(NAME_BONUS) $(NAME2_BONUS)

re: fclean
	$(MAKE)

.PHONY: all clean fclean re
