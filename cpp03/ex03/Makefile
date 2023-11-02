# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/01 12:28:17 by frmurcia          #+#    #+#              #
#    Updated: 2023/11/02 19:11:12 by frmurcia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN	= \033[32m
NC		= \033[m

NAME 	= weird

SRC 	= main.cpp ScavTrap.cpp ClapTrap.cpp FragTrap.cpp DiamondTrap.cpp

OBJ 	= $(SRC:.cpp=.o)

DEPS	= $(SRC:.cpp=.d)

HEADER = ClapTrap.hpp FragTrap.hpp ScavTrap.hpp DiamondTrap.hpp

CC 		= c++

RM = rm -f

FLAGS = -Wextra -Wall -Werror -std=c++98 -MMD -Wshadow -Wno-shadow
# -Wshadow to use virtual heritance
# -Wno to specify a negative form to desactivate the warning

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

leaks: all
	@leaks -atExit -- ./$(NAME)

.PHONY : all clean fclean re leaks
