# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jlasne <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/03 12:34:13 by jlasne            #+#    #+#              #
#    Updated: 2016/11/07 15:43:23 by jlasne           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = fillit

SRC = main.c\
	  ft_usage.c\
	  ft_checkbuf.c\
	  ft_checktetri.c\
	  ft_get_sizes.c\
	  ft_tetri.c\
	  ft_inittab.c

OBJ = $(SRC:.c=.o)

SRC_PATH = srcs/

SRC_POS = $(addprefix $(SRC_PATH),$(SRC))

INC = -I includes

LIBFT =	srcs/libft/libft.a

CC = gcc

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
		$(CC) $(FLAGS) $(OBJ) -o $(NAME) $(LIBFT)

$(OBJ): $(LIBFT)
		$(CC) $(FLAGS) -c $(SRC_POS)

$(LIBFT):
		make -C ./srcs/libft/

clean:
		rm -f $(OBJ)
			make clean -C ./srcs/libft/

fclean: clean
		rm -f $(NAME)
			make fclean -C ./srcs/libft/

re: fclean all
