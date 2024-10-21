# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erigonza <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/11 13:19:02 by erigonza          #+#    #+#              #
#    Updated: 2024/10/21 10:49:20 by erigonza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := NowWeAreTalking

SRC := main.cpp Fixed.cpp 

OBJ_DIR := obj/

OBJ := $(addprefix $(OBJ_DIR), $(SRC:.cpp=.o))

CC := c++ 

FLAGS := -Wall -Wextra -Werror -std=c++98 -g -c 

all: Makefile $(NAME)

$(OBJ_DIR)%.o: %.cpp Makefile Fixed.hpp
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
