NAME = a.out

CC = clang++

CFLAGS = -Wall -Werror -Wextra

SRC_NAME = main.cpp

OBJ_NAME = $(SRC_NAME:.cpp=.o)

all: $(NAME)

%.o : %.cpp
	@$(CC) $(CFLAGS) -c -o $@ $^

$(NAME): $(OBJ_NAME)
	@$(CC) $(CFLAGS) $^ -o $@

clean:
	@-/bin/rm -f $(OBJ_NAME)
	@echo "\033[0;32mFiles deleted\033[0m"

fclean: clean
	@-/bin/rm -f $(NAME)
	@echo "\033[0;32mCleaned\033[0m"

re: fclean all

.PHONY: all clean fclean re