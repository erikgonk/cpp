# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erigonza <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/26 17:28:37 by erigonza          #+#    #+#              #
#    Updated: 2024/10/26 17:28:47 by erigonza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= I_don’t_want_to_set_the_world_on_fire 

SRC			:= main.cpp AAnimal.cpp Cat.cpp Dog.cpp WrongAnimal.cpp WrongCat.cpp Brain.cpp

OBJ_DIR		:= obj/

HEADERS		:= AAnimal.hpp Cat.hpp Dog.hpp WrongAnimal.hpp WrongCat.hpp Brain.hpp

OBJ			:= $(addprefix $(OBJ_DIR), $(SRC:.cpp=.o))

CC			:= c++

FLAGS		:= -Wall -Wextra -Werror -std=c++98 -pedantic -g

all: Makefile $(NAME)

$(OBJ_DIR)%.o: %.cpp $(HEADERS) Makefile
	mkdir -p $(OBJ_DIR)
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

v valgrind: $(NAME)
	@valgrind --leak-check=full --track-origins=yes ./$(NAME)

c clean:
	/bin/rm -f $(OBJ)

f fclean: clean
	/bin/rm -rf $(OBJ_DIR)
	/bin/rm -f $(NAME)
	
r re: fclean all

.PHONY: all clean fclean re v c f r

