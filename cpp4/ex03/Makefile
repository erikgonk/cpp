# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erigonza <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/26 17:31:53 by erigonza          #+#    #+#              #
#    Updated: 2024/10/26 18:10:46 by erigonza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= AMateria 

SRC			:= main.cpp AMateria.cpp Character.cpp MateriaSource.cpp Ice.cpp Cure.cpp

OBJ_DIR		:= obj/

HEADERS		:= AMateria.hpp ICharacter.hpp Character.hpp IMateriaSource.hpp MateriaSource.hpp Ice.hpp Cure.hpp

OBJ			:= $(addprefix $(OBJ_DIR), $(SRC:.cpp=.o))

CC			:= c++

FLAGS		:= -Wall -Wextra -Werror -std=c++98 -pedantic -MMD -g

a all: Makefile $(NAME)

$(OBJ_DIR)%.o: %.cpp $(HEADERS) Makefile
	mkdir -p $(OBJ_DIR)
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

v valgrind: $(NAME)
	@valgrind --leak-check=full --track-origins=yes ./$(NAME)

tv totvalgrind: $(NAME)
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME)

c clean:
	/bin/rm -f $(OBJ)

f fclean: clean
	/bin/rm -rf $(OBJ_DIR)
	/bin/rm -f $(NAME)
	
r re: fclean all

.PHONY: all clean fclean re a v tv c f r
