# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erigonza <erigonza@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/26 17:28:37 by erigonza          #+#    #+#              #
#    Updated: 2025/02/26 13:22:21 by erigonza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= MutantStack

SRC			:= main.cpp

TMP_DIR		:= obj/

HEADERS		:= MutantStack.hpp

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

f fclean:
	$(RM) $(TMP_DIR)
	$(RM) $(NAME)
	
re: fclean all

r run: $(NAME)
	clear
	@./$(NAME)

.PHONY: all f fclean re v valgrind r run
