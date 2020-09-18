NAME = philo_one
FLAGS = -Wall -Wextra -Werror -lpthread
HDRS = ./one.h
SRC = ./one.c ./get_param.c ./threads.c ./clear_leaks.c
UTILS = ./utils/ft_atoi.c ./utils/ft_itoa.c ./utils/ft_strdup.c ./utils/ft_strlen.c ./utils/ft_done.c ./utils/ft_print_mess.c ./utils/ft_time_is.c
OBJ=$(SRC:.c=.o) $(UTILS:.c=.o)

#colors
RED=\033[1;31m
GREEN=\033[1;32m
YELLOW=\033[1;33m
CYAN=\033[1;36m
RESET=\033[0m

%.o:%.c
	@gcc -o $@ -c $< $(FLAGS)
	@echo "[$(GREEN)OK$(RESET)]$(YELLOW) Compiling $<$(RESET)"

$(NAME): $(OBJ) $(HDRS)
	@gcc -o $(NAME) $(OBJ) $(FLAGS)
	@echo "[$(GREEN)Success$(RESET)]$(GREEN) Successfully compiled philo_one project.$(RESET)"
	@echo ""
	@echo "$(CYAN)      /|/|"
	@echo "     ( @ @)"
	@echo "      ) ^ $(RESET)   philosophers(project 2020) $(CYAN)"
	@echo "     / |||       $(RESET) by ckakuna$(CYAN)"
	@echo "    / )|||_"
	@echo "   (_______)$(RESET)"
	@echo ""

all: $(NAME)

clean:
	@rm $(OBJ)
	@echo "[$(RED)Deleting$(RESET)]$(RED) Object files deleted.$(RESET)"

fclean: clean
	@rm $(NAME)
	@echo "[$(RED)Deleting$(RESET)]$(RED) philo_one deleted.$(RESET)"

re: fclean all

.PHONY: all clean fclean re
