NAME_SERVER = server
NAME_CLIENT = client

SRC_SERVER = src/server.c

SRC_CLIENT = src/client.c

CC = cc
FLAGS = -Wall -Wextra -Werror
DFLAGS = -Wall -Wextra -Werror -g -fsanitize=address -static-libsan

OBJ_SERVER = $(SRC_SERVER:.c=.o)
OBJ_CLIENT = $(SRC_CLIENT:.c=.o)

all: $(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER): $(OBJ_SERVER)
	@echo "Linking $@"
	@$(CC) $(OBJ_SERVER) $(FLAGS) -o $(NAME_SERVER)
	@echo "Done!"

$(NAME_CLIENT): $(OBJ_CLIENT)
	@echo "Linking $@"
	@$(CC) $(OBJ_CLIENT) $(FLAGS) -o $(NAME_CLIENT)
	@echo "Done!"

%.o: %.c
	@echo "Compiling $<"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ_SERVER) $(OBJ_CLIENT)
	@make clean -C ./ft_printf


fclean: clean
	@rm -f $(NAME_SERVER) $(NAME_CLIENT)

re: fclean all

alltest: all
	@./$(NAME)

test:
	@./$(NAME)

.PHONY: all clean fclean re test