NAME = so_long

SRCS = map_validation1.c free.c \
	eventlistener.c maps.c \
	so_long.c floodfill.c \
	game.c mouv_p.c env_check.c \
	map_validation2.c mouve_p2.c \
	get_next_line/get_next_line.c \
	get_next_line/get_next_line_utils.c

OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

MLXPATH = minilibx-linux
MLXFLAGS = -L$(MLXPATH) -lmlx -lXext -lX11
MLXINC = -I$(MLXPATH)

LIBFTPATH = libft
LIBFT = $(LIBFTPATH)/libft.a

all: $(NAME)

$(NAME): $(OBJS)
	@echo "=============================="
	@echo "🔧 Building libft... 🔧"
	@echo "=============================="
	@make -C $(LIBFTPATH)
	@echo "=============================="
	@echo "⚙️ Compiling the program... ⚙️"
	@echo "=============================="
	@$(CC) $(OBJS) $(LIBFT) $(MLXFLAGS) $(CFLAGS) -o $(NAME)
	@echo "=================================="
	@echo "✅ Build complete! ✅"
	@echo "=================================="
	@echo "\033[31m ███▄ ▄███▓    ▄▄▄██▀▀▀    ▄▄▄          ███▄ ▄███▓    ██▓    ██▓    "
	@echo "▓██▒▀█▀ ██▒      ▒██      ▒████▄       ▓██▒▀█▀ ██▒   ▓██▒   ▓██▒    "
	@echo "▓██    ▓██░      ░██      ▒██  ▀█▄     ▓██    ▓██░   ▒██▒   ▒██░    "
	@echo "▒██    ▒██    ▓██▄██▓     ░██▄▄▄▄██    ▒██    ▒██    ░██░   ▒██░    "
	@echo "▒██▒   ░██▒    ▓███▒       ▓█   ▓██▒   ▒██▒   ░██▒   ░██░   ░██████▒"
	@echo "░ ▒░   ░  ░    ▒▓▒▒░       ▒▒   ▓▒█░   ░ ▒░   ░  ░   ░▓     ░ ▒░▓  ░"
	@echo "░  ░      ░    ▒ ░▒░        ▒   ▒▒ ░   ░  ░      ░    ▒ ░   ░ ░ ▒  ░"
	@echo "░      ░       ░ ░ ░        ░   ▒      ░      ░       ▒ ░     ░ ░   "
	@echo "       ░       ░   ░            ░  ░          ░       ░         ░  ░"
	@echo "\033[0m"  # Reset color
	@echo "\033[0m"  # Reset color
	@echo "Well done! 🎯"

%.o: %.c
	@echo "=============================="
	@echo "🛠️ Compiling $< ... 🛠️"
	@echo "=============================="
	@$(CC) $(CFLAGS) $(MLXINC) -c $< -o $@

clean:
	@echo "=============================="
	@echo "🧹 Cleaning up object files... 🧹"
	@echo "=============================="
	@make -C $(LIBFTPATH) clean
	@rm -f $(OBJS)
	@echo "=============================="
	@echo "🧹 Cleanup complete! 🧹"
	@echo "=============================="

fclean: clean
	@echo "=============================="
	@echo "🪣 Performing full cleanup... 🪣"
	@echo "=============================="
	@make -C $(LIBFTPATH) fclean
	@rm -f $(NAME)
	@echo "=============================="
	@echo "🪣 Full cleanup complete! 🪣"
	@echo "=============================="

re: fclean all

.PHONY: all clean fclean re