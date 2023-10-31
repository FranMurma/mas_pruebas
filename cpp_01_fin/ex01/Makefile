# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/09 16:35:55 by frmurcia          #+#    #+#              #
#    Updated: 2023/10/23 16:47:25 by frmurcia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN	= \033[32m
NC		= \033[m

NAME 	= braiiiiiiinnnzzzz

SRC 	= main.cpp Zombie.cpp zombieHorde.cpp

OBJ 	= $(SRC:.cpp=.o)

DEPS	= $(SRC:.cpp=.d)

HEADER = Zombie.hpp

CC 		= c++

RM = rm -f

FLAGS = -Wextra -Wall -Werror -std=c++98 -MMD -pedantic

%.o : %.cpp
	@$(CC) $(FLAGS) -c $< -o $@
	@echo "Compiling..."

all : $(NAME)

-include $(DEPS)

$(NAME) : $(OBJ)
	@$(CC) $(FLAGS) $(OBJ) -o $(NAME)
	@echo "$(GREEN)$(NAME) compiled!$(NC)"

clean :
	@$(RM) $(OBJ) $(DEPS)
	@echo "$(GREEN)$(NAME) cleaned!$(NC)"

fclean : clean
	@$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re
