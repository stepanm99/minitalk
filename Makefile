NAME_SERVER = server
NAME_CLIENT = client

SRC_SERVER = src/server.c

SRC_CLIENT = src/client.c

CC = cc
FLAGS = -Wall -Wextra -Werror
DFLAGS = -Wall -Wextra -Werror -g -fsanitize=address -static-libsan

OBJ_SERVER = $(SRC_SERVER:.c=.o)
OBJ_CLIENT = $(SRC_CLIENT:.c=.o)

LIBFT = incl/libft/libft.a

all: libft $(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER): $(OBJ_SERVER)
	@echo "Linking $@"
	@$(CC) $(OBJ_SERVER) $(FLAGS) $(LIBFT) -o $(NAME_SERVER)
	@echo "Done!"

$(NAME_CLIENT): $(OBJ_CLIENT)
	@echo "Linking $@"
	@$(CC) $(OBJ_CLIENT) $(FLAGS) $(LIBFT) -o $(NAME_CLIENT)
	@echo "Done!"

%.o: %.c
	@echo "Compiling $<"
	@$(CC) $(CFLAGS) -c $< -o $@

libft:
	make all -C ./incl/libft

clean:
	@rm -f $(OBJ_SERVER) $(OBJ_CLIENT)
	@make clean -C ./incl/libft

fclean: clean
	@rm -f $(NAME_SERVER) $(NAME_CLIENT)
	@make fclean -C ./incl/libft

re: fclean all

.PHONY: all clean fclean re test