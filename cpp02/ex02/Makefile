# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/30 18:12:04 by frmurcia          #+#    #+#              #
#    Updated: 2023/10/30 18:12:25 by frmurcia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN	= \033[32m
NC		= \033[m

NAME 	= canonics

SRC 	= main.cpp Fixed.cpp

OBJ 	= $(SRC:.cpp=.o)

DEPS	= $(SRC:.cpp=.d)

HEADER = Fixed.hpp

CC 		= c++

RM = rm -f

FLAGS = -Wextra -Wall -Werror -std=c++98 -MMD

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
