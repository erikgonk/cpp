# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erigonza <erigonza@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/26 17:28:37 by erigonza          #+#    #+#              #
#    Updated: 2025/03/06 17:58:03 by erigonza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= PmergeMe

SRC			:= main.cpp PmergeMe.cpp

TMP_DIR		:= obj/

HEADERS		:= PmergeMe.hpp

OBJ			:= $(addprefix $(TMP_DIR), $(SRC:.cpp=.o))
DEPS		:= $(addprefix $(TMP_DIR)/, $(SRC:.cpp=.d))

CC			:= c++

FLAGS		:= -Wall -Wextra -Werror -std=c++98 -g -MMD

RM			:= @/bin/rm -rf

all: $(NAME)

$(TMP_DIR)%.o: %.cpp $(HEADERS) Makefile
	clear
	@printf "\033[0;33m\r🔨 $< ✅ \033[0m \n"
	@mkdir -p $(TMP_DIR)
	@$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ)
	@$(CC) $(FLAGS) $(OBJ) -o $(NAME)

v valgrind: $(NAME)
	clear
	@valgrind --leak-check=full --track-origins=yes ./$(NAME)

c clean:
	$(RM) $(OBJ)

f fclean: clean
	$(RM) $(TMP_DIR)
	$(RM) $(NAME)
	
r re: fclean all

ARGS		:= 0 1 42 41 40 10 20
e execute: $(NAME)
	clear
	@./$(NAME) $(ARGS)

.PHONY: all clean fclean re v valgrind c f r e execute

