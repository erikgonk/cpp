# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erigonza <erigonza@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/26 17:28:37 by erigonza          #+#    #+#              #
#    Updated: 2025/02/19 15:30:54 by erigonza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= identifyRealType

SRC			:= main.cpp

OBJ_DIR		:= obj/

HEADERS		:= A.hpp B.hpp Base.hpp C.hpp

OBJ			:= $(addprefix $(OBJ_DIR), $(SRC:.cpp=.o))

CC			:= c++

FLAGS		:= -Wall -Wextra -Werror -std=c++98 -g

RM			:= @/bin/rm -rf

all: Makefile $(NAME)

$(OBJ_DIR)%.o: %.cpp $(HEADERS) Makefile
	@printf "\033[0;33m\r🔨 $< ✅ \033[0m"
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ)
	@$(CC) $(FLAGS) $(OBJ) -o $(NAME)

v valgrind: $(NAME)
	@valgrind --leak-check=full --track-origins=yes ./$(NAME)

c clean:
	$(RM) $(OBJ)

f fclean: clean
	$(RM) $(OBJ_DIR)
	$(RM) $(NAME)
	
r re: fclean all

e execute:
	@make
	clear
	@./$(NAME)

.PHONY: all clean fclean re v c f r e execute
