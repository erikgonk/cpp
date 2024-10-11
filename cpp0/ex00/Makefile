# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erigonza <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/11 13:20:09 by erigonza          #+#    #+#              #
#    Updated: 2024/10/11 13:20:10 by erigonza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone

SRC = main.cpp

OBJ_DIR = obj/

OBJ = $(addprefix $(OBJ_DIR), $(SRC:.cpp=.o))

CC = c++ 

FLAGS = -Wall -Wextra -Werror -std=c++98 -g -c 

all: Makefile $(NAME)

$(OBJ_DIR)%.o: %.cpp Makefile
	@mkdir -p $(OBJ_DIR)
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

c clean:
	rm -f $(OBJ)

f fclean: clean
	rm -rf $(OBJ_DIR)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
