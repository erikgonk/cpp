# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erigonza <erigonza@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/26 17:28:37 by erigonza          #+#    #+#              #
#    Updated: 2025/02/22 10:50:21 by erigonza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= ScalarConverter

SRC			:= main.cpp ScalarConverter.cpp

TMP_DIR		:= obj/

HEADERS		:= ScalarConverter.hpp

OBJ			:= $(addprefix $(TMP_DIR), $(SRC:.cpp=.o))
DEPS		:= $(addprefix $(TMP_DIR)/, $(SRC:.cpp=.d))

CC			:= c++

FLAGS		:= -Wall -Wextra -Werror -std=c++98 -g -MMD

RM			:= @/bin/rm -rf

all: $(NAME)

$(TMP_DIR)%.o: %.cpp $(HEADERS) Makefile
	@printf "\033[0;33m\r🔨 $< ✅ \033[0m"
	@mkdir -p $(TMP_DIR)
	@$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ)
	@$(CC) $(FLAGS) $(OBJ) -o $(NAME)

v valgrind: $(NAME)
	@valgrind --leak-check=full --track-origins=yes ./$(NAME)

c clean:
	$(RM) $(OBJ)

f fclean: clean
	$(RM) $(TMP_DIR)
	$(RM) $(NAME)
	
r re: fclean all

e execute:
	@make
	clear
	@./$(NAME)

.PHONY: all clean fclean re v c f r e execute

