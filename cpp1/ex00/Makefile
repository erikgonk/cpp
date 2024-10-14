# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erigonza <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/11 13:19:02 by erigonza          #+#    #+#              #
#    Updated: 2024/10/14 12:13:02 by erigonza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = BraiiiiiiinnnzzzZ

SRC = main.cpp Zombie.cpp newZombie.cpp randomChump.cpp

OBJ_DIR = obj/

OBJ = $(addprefix $(OBJ_DIR), $(SRC:.cpp=.o))

CC = c++ 

FLAGS = -Wall -Wextra -Werror -std=c++98 -c -fsanitize=address

LDFLAGS = -fsanitize=address

all: Makefile $(NAME)

$(OBJ_DIR)%.o: %.cpp Makefile
	@mkdir -p $(OBJ_DIR)
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(LDFLAGS) -o $(NAME)

c clean:
	rm -rf $(OBJ_DIR)

f fclean: clean
	rm -rf $(OBJ_DIR)
	rm -f $(NAME)

r re: fclean all

.PHONY: all clean fclean re
