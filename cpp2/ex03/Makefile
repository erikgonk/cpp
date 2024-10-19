# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erigonza <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/19 12:02:57 by erigonza          #+#    #+#              #
#    Updated: 2024/10/19 12:02:59 by erigonza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := bsp

SRC := main.cpp Fixed.cpp Point.cpp bsp.cpp

OBJ_DIR := obj/

OBJ := $(addprefix $(OBJ_DIR), $(SRC:.cpp=.o))

CC := c++ 

FLAGS := -Wall -Wextra -Werror -std=c++98 -g -c 

all: Makefile $(NAME)

$(OBJ_DIR)%.o: %.cpp Makefile
	@mkdir -p $(OBJ_DIR)
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

c clean:
	rm -rf $(OBJ_DIR)

f fclean: clean
	rm -rf $(OBJ_DIR)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
