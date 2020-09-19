NAME = philo_three
FLAGS = -Wall -Wextra -Werror -lpthread
HDRS = ./three.h
SRC = ./three.c ./get_param.c ./threads.c ./clear_leaks.c
UTILS = ./utils/ft_atoi.c ./utils/ft_itoa.c ./utils/ft_strdup.c ./utils/ft_strlen.c ./utils/ft_done.c ./utils/ft_print_mess.c ./utils/ft_time_is.c ./utils/ft_strjoin.c
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
	@echo "[$(GREEN)Success$(RESET)]$(GREEN) Successfully compiled philo_three project.$(RESET)"
	@echo ""
	@echo "$(CYAN)      /|/|"
	@echo "     ( @ @)"
	@echo "      ) ^ $(RESET)   philosophers(project 2020) $(CYAN)"
	@echo "     / |||       $(RESET) by ckakuna$(CYAN)"
	@echo "    / )|||_"
	@echo "   (_______)$(RESET)"
	@echo ""
	@echo "$(YELLOW)Your assistant rushes to the rescue.$(RESET)"
	@echo "$(RED)[Important argument]:$(RESET)"
	@echo " 1. $(YELLOW)[number_of_philosophers]$(RESET) - Количество философов/вилок."
	@echo " 2. $(YELLOW)[time_to_die]$(RESET) - Время в ms до смерти."
	@echo " 3. $(YELLOW)[time_to_eat]$(RESET) - Время в ms на прием пищи."
	@echo " 4. $(YELLOW)[time_to_sleep]$(RESET) - Время в ms на сон."
	@echo ""
	@echo "$(RED)[Optional argument]:$(RESET)"
	@echo " 5. $(YELLOW)[number_of_times_each_philosopher_must_eat]$(RESET) - Время в ms на ограниченное количество приема пищи."
	@echo ""
	@echo "$(RED)[For example]:$(RESET)"
	@echo "    $(YELLOW)[./$(NAME) 5 800 200 200]$(RESET) or $(YELLOW)[./$(NAME) 5 800 200 200 7]$(RESET)"
	@echo ""
	@echo "$(YELLOW)NOTE:$(RESET) По чек-листу есть ограничения на количество философов: 2-200 и время не меньше 60ms."
	@echo ""

all: $(NAME)

clean:
	@rm $(OBJ)
	@echo "[$(RED)Deleting$(RESET)]$(RED) Object files deleted.$(RESET)"

fclean: clean
	@rm $(NAME)
	@echo "[$(RED)Deleting$(RESET)]$(RED) philo_three deleted.$(RESET)"

re: fclean all

help:
	@echo ""
	@echo "$(CYAN)      /|/|"
	@echo "     ( @ @)"
	@echo "      ) ^ $(RESET)   philosophers(project 2020) $(CYAN)"
	@echo "     / |||       $(RESET) by ckakuna$(CYAN)"
	@echo "    / )|||_"
	@echo "   (_______)$(RESET)"
	@echo ""
	@echo "$(YELLOW)Your assistant rushes to the rescue.$(RESET)"
	@echo "$(RED)[Important argument]:$(RESET)"
	@echo " 1. $(YELLOW)[number_of_philosophers]$(RESET) - Количество философов/вилок."
	@echo " 2. $(YELLOW)[time_to_die]$(RESET) - Время в ms до смерти."
	@echo " 3. $(YELLOW)[time_to_eat]$(RESET) - Время в ms на прием пищи."
	@echo " 4. $(YELLOW)[time_to_sleep]$(RESET) - Время в ms на сон."
	@echo ""
	@echo "$(RED)[Optional argument]:$(RESET)"
	@echo " 5. $(YELLOW)[number_of_times_each_philosopher_must_eat]$(RESET) - Время в ms на ограниченное количество приема пищи."
	@echo ""
	@echo "$(RED)[For example]:$(RESET)"
	@echo "    $(YELLOW)[./$(NAME) 5 800 200 200]$(RESET) or $(YELLOW)[./$(NAME) 5 800 200 200 7]$(RESET)"
	@echo ""
	@echo "$(YELLOW)NOTE:$(RESET) По чек-листу есть ограничения на количество философов: 2-200 и время не меньше 60ms."
	@echo ""

.PHONY: all clean fclean re
