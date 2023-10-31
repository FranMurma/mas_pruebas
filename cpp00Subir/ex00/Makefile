# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/25 10:51:17 by frmurcia          #+#    #+#              #
#    Updated: 2023/09/25 10:52:35 by frmurcia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN	= \033[32m

NAME 	= megaphone

SRC 	= megaphone.cpp

OBJ 	= $(SRC:.cpp=.o)

CC 		= c++

RM = rm -f

FLAGS = -Wall -Werror -Wextra -std=c++98

%.o : %.cpp
	@$(CC) $(FLAGS) -c $< -o $(<:.cpp=.o)
	@echo "Compiling..."

all : $(NAME)

$(NAME) : $(OBJ)
	@$(CC) $(FLAGS) $(OBJ) -o $(NAME)
	@echo "$(GREEN)$(NAME) compiled!$(NC)"

clean :
	$(RM) $(OBJ)
	@echo "$(GREEN)$(NAME) cleaned!$(NC)"

fclean : clean
	@$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re
