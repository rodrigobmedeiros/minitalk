NAME = minitalk
SERVER = server
CLIENT = client

SRCS_SERVER = \
	server.c

SRCS_CLIENT = \
	client.c

FLAGS = -Wall -Wextra -Werror

OBJS_SERVER = ${SRCS_SERVER:.c=.o}
OBJS_CLIENT = ${SRCS_CLIENT:.c=.o}

LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

# Define color codes
COLOR_RESET = \033[0m
COLOR_RED = \033[0;31m
COLOR_GREEN = \033[0;32m
COLOR_YELLOW = \033[0;33m
COLOR_BLUE = \033[0;34m
COLOR_MAGENTA = \033[0;35m
COLOR_CYAN = \033[0;36m
COLOR_WHITE = \033[0;37m

# Define format functions
PRINT_INFO = printf "$(COLOR_CYAN)%s$(COLOR_RESET)\n" "$1"
PRINT_SUCCESS = printf "$(COLOR_GREEN)%s$(COLOR_RESET)\n" "$1"
PRINT_WARNING = printf "$(COLOR_YELLOW)%s$(COLOR_RESET)\n" "$1"
PRINT_ERROR = printf "$(COLOR_RED)%s$(COLOR_RESET)\n" "$1"

all: $(NAME)

$(NAME): $(LIBFT)
	@$(call PRINT_INFO,"Building server...")
	cc $(FLAGS) $(SRCS_SERVER) $(LIBFT) -o $(SERVER)
	@$(call PRINT_SUCCESS,"Server built successfully")
	@$(call PRINT_INFO,"Building client...")
	cc $(FLAGS) $(SRCS_CLIENT) $(LIBFT) -o $(CLIENT)
	@$(call PRINT_SUCCESS,"Client built successfully")

$(LIBFT):
	@$(call PRINT_INFO,"Building libraries...")
	make -C $(LIBFT_PATH) all
	@$(call PRINT_SUCCESS,"Libraries built successfully")

clean:
	@$(call PRINT_INFO,"Cleaning...")
	make -C $(LIBFT_PATH) clean
	@$(call PRINT_SUCCESS,"Cleaned successfully")

fclean: clean
	@$(call PRINT_INFO,"Cleaning...")
	rm -f $(SERVER) $(CLIENT)
	make -C $(LIBFT_PATH) fclean
	@$(call PRINT_SUCCESS,"Cleaned successfully")

re: clean fclean all

.PHONY: all clean fclean re