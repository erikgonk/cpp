# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erigonza <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/25 18:09:47 by erigonza          #+#    #+#              #
#    Updated: 2024/10/25 18:58:22 by erigonza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= Polymorphism 

SRC			:= main.cpp Animal.cpp Cat.cpp Dog.cpp WrongAnimal.cpp WrongCat.cpp Olifant.cpp

OBJ_DIR		:= obj/

HEADERS		:= Animal.hpp Cat.hpp Dog.hpp WrongAnimal.hpp WrongCat.hpp Olifant.hpp

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
