# Color def
DEL_LINE =		\033[2K
ITALIC =		\033[3m
BOLD =			\033[1m
DEF_COLOR =		\033[0;39m
GRAY =			\033[0;90m
RED =			\033[0;91m
GREEN =			\033[0;92m
YELLOW =		\033[0;93m
BLUE =			\033[0;94m
MAGENTA =		\033[0;95m
CYAN =			\033[0;96m
WHITE =			\033[0;97m
BLACK =			\033[0;99m
ORANGE =		\033[38;5;209m
BROWN =			\033[38;2;184;143;29m
DARK_GRAY =		\033[38;5;234m
MID_GRAY =		\033[38;5;245m
DARK_GREEN =	\033[38;2;75;179;82m
DARK_YELLOW =	\033[38;5;143m

# Compiler information
CC = cc

CFLAGS = -Wall -Werror -Wextra

# Directories for other dependencies
LIBFTDIR = ./libft

# Target names
NAME = push_swap
LIBFT = $(LIBFTDIR)/libft.a

# Files
SRC = ./push_swap.c\
	  ./split_argv.c\
	  ./atoln.c\
	  ./push_swap_utils.c\
	  ./free_list.c\
	  ./handle_stack.c\
	  ./rotate_commands.c\
	  ./swap_commands.c\
	  ./push_commands.c\
	  ./b_stack.c\
	  ./ident_a.c

OBJ = $(SRC:.c=.o)

# Create the push_swap library
$(LIBPUSH): $(OBJ)
	@ar rcs $(LIBPUSH) $(OBJ)

# Create executable, linking both libraries
$(NAME): $(OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L$(LIBFTDIR) -lft
	@echo "\n${GREEN} Created ${NAME} ${DEF_COLOR}\n"

# Compile .c files into .o files
%.o: %.c
	@echo "${MAGENTA} ~ ${BROWN} Compiling... ${MAGENTA}-> ${CYAN}$< ${DEF_COLOR}"
	@$(CC) $(CFLAGS) -I$(LIBFTDIR) -c $< -o $@ -g3

# Build libft and push_swap libraries
all: $(NAME)

# Build libft inside its directory
$(LIBFT):
	@make -C $(LIBFTDIR)

# Remove .o files for push_swap and libft directory
clean:
	@rm -f $(OBJ)
	@make -C $(LIBFTDIR) clean

# Remove everything including the program and libraries
fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFTDIR) fclean

# Rebuild everything
re: fclean all

.PHONY: all clean fclean re
