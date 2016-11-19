# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jlasne <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/03 12:34:13 by jlasne            #+#    #+#              #
#    Updated: 2016/11/17 10:39:00 by jlasne           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = fillit

SRC = main.c\
	  arrange.c\
	  check.c\
	  read.c\
	  shape.c\
	  solve.c\
	  tetriminos.c\
	  usage.c

OBJ = $(SRC:.c=.o)

SRC_PATH = src/

SRC_POS = $(addprefix $(SRC_PATH),$(SRC))

INC = -I includes

LIBFT =	src/libft/libft.a

CC = gcc

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
		$(CC) $(FLAGS) $(OBJ) -o $(NAME) $(LIBFT)

$(OBJ): $(LIBFT)
		$(CC) $(FLAGS) -c $(SRC_POS)

$(LIBFT):
		make -C ./src/libft/

clean:
		rm -f $(OBJ)
			make clean -C ./src/libft/

fclean: clean
		rm -f $(NAME)
			make fclean -C ./src/libft/

re: fclean all

.PHONY : all, re, clean, flcean
