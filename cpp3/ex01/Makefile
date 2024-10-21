# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erigonza <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/11 13:19:02 by erigonza          #+#    #+#              #
#    Updated: 2024/10/21 11:23:56 by erigonza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    	:= serena_myLove

SRC			:= main.cpp ClapTrap.cpp

OBJ_DIR		:= obj/

OBJ			:= $(addprefix $(OBJ_DIR), $(SRC:.cpp=.o))

CC			:= c++ 

FLAGS		:= -Wall -Wextra -Werror -std=c++98 -g -c 

all: Makefile $(NAME)

$(OBJ_DIR)%.o: %.cpp Makefile ClapTrap.hpp
	@mkdir -p $(OBJ_DIR)
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

v valgrind: $(NAME)
	@valgrind --leak-check=full --track-origins=yes ./$(NAME)  10 Boo

c clean:
	rm -rf $(OBJ_DIR)

f fclean: clean
	rm -rf $(OBJ_DIR)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
