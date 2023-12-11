NAME_SERVER = server
NAME_CLIENT = client

SRC_SERVER = src/server.c

SRC_SERVER_BONUS = src/server_bonus.c src/bonus_utils.c

SRC_CLIENT = src/client.c

SRC_CLIENT_BONUS = src/client_bonus.c src/bonus_utils.c

CC = cc
FLAGS = -Wall -Wextra -Werror -O3
DFLAGS = -Wall -Wextra -Werror -g -fsanitize=address -static-libsan

OBJ_SERVER = $(SRC_SERVER:.c=.o)
OBJ_CLIENT = $(SRC_CLIENT:.c=.o)

BOBJ_SERVER = $(SRC_SERVER_BONUS:.c=.o)
BOBJ_CLIENT = $(SRC_CLIENT_BONUS:.c=.o)

all: $(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER): $(OBJ_SERVER)
	@echo "Linking $@"
	@$(CC) $(OBJ_SERVER) $(FLAGS) -o $(NAME_SERVER)
	@echo "Done!"

$(NAME_CLIENT): $(OBJ_CLIENT)
	@echo "Linking $@"
	@$(CC) $(OBJ_CLIENT) $(FLAGS) -o $(NAME_CLIENT)
	@echo "Done!"

bonus: bonus_client bonus_server

bonus_client: $(BOBJ_CLIENT)
	@echo "Linking $@"
	@$(CC) $(BOBJ_CLIENT) $(FLAGS) -o $(NAME_CLIENT)
	@echo "Done!"

bonus_server: $(BOBJ_SERVER)
	@echo "Linking $@"
	@$(CC) $(BOBJ_SERVER) $(FLAGS) -o $(NAME_SERVER)
	@echo "Done!"

%.o: %.c
	@echo "Compiling $<"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ_SERVER) $(OBJ_CLIENT) $(BOBJ_SERVER) $(BOBJ_CLIENT)

fclean: clean
	@rm -f $(NAME_SERVER) $(NAME_CLIENT)

re: fclean all

.PHONY: all clean fclean re test