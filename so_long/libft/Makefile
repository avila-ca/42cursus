# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avila-ca <avila-ca@student.42barcelona.co  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/20 17:15:47 by avila-ca          #+#    #+#              #
#    Updated: 2022/09/12 08:41:54 by avila-ca         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = 	ft_bzero.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memset.c \
		ft_strchr.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strlen.c \
		ft_strncmp.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_atoi.c \
		ft_calloc.c \
		ft_strdup.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_strmapi.c \
		ft_striteri.c \
		ft_putchar_fd.c\
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_itoa.c \
		ft_putnbr_fd.c \
		ft_split.c

OBJ = $(SRC:.c=.o)

NAME = libft.a

BONUS = ft_lstnew.c \
		ft_lstadd_front.c \
		ft_lstsize.c \
		ft_lstlast.c \
		ft_lstadd_back.c \
		ft_lstdelone.c \
		ft_lstclear.c \
		ft_lstiter.c \
		ft_lstmap.c

BONUS_OBJ = $(BONUS:.c=.o)	

NAME = libft.a

CFLAGS = -Wall -Werror -Wextra

CC = gcc

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) -c  $(CFLAGS) $(SRC) -I libft.h 
	ar -src $(NAME) $(OBJ)
	ranlib $(NAME)

bonus : $(OBJ) $(BONUS_OBJ)
	$(CC) -c $(CFLAGS) $(SRC) $(BONUS) -I libft.h
	ar -src $(NAME) $(OBJ) $(BONUS_OBJ) 
	ranlib $(NAME)

clean: 
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all bonus
