GREEN	= \033[32m
NC		= \033[m

NAME 	= RPN

SRC 	= main.cpp RPN.cpp 

OBJ 	= $(SRC:.cpp=.o)

DEPS	= $(SRC:.cpp=.d)

CC 		= c++

RM = rm -f

FLAGS = -Wextra -Wall -Werror -std=c++98 -pedantic -MMD

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
	@leaks -atExit -- ./$(NAME) "'9'"

run:
	./$(NAME) "'9'"

.PHONY : all clean fclean re leaks run
