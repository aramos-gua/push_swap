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
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L$(LIBFTDIR) -lft

# Compile .c files into .o files
%.o: %.c
	$(CC) $(CFLAGS) -I$(LIBFTDIR) -c $< -o $@ -g3

# Build libft and push_swap libraries
all: $(NAME)

# Build libft inside its directory
$(LIBFT):
	make -C $(LIBFTDIR)

# Remove .o files for push_swap and libft directory
clean:
	rm -f $(OBJ)
	make -C $(LIBFTDIR) clean

# Remove everything including the program and libraries
fclean: clean
	rm -f $(NAME)
	make -C $(LIBFTDIR) fclean

# Rebuild everything
re: fclean all

.PHONY: all clean fclean re
