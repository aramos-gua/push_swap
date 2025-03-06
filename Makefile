# Compiler information
CC = cc

CFLAGS = -Wall -Werror -Wextra

# Directories for other dependencies
LIBFTDIR = ./libft

# Target names
NAME = push_swap

LIBFT = $(LIBFTDIR)/libft.a

# Files
SRC = ./push_swap.c

OBJ = $(SRC:.c=.o)

# Create library for push_swap
$(NAME): $(OBJ) $(LIBFT)
	@cp $(LIBFT) libft.a
	@ar rcs libft.a $(OBJ)
	@mv libft.a $(NAME)
	@rm *.o

# Compile .c files into .o files
%.o: %.c
	$(CC) $(CFLAGS) -I$(LIBFTDIR) -c $< -o $@

# Build libft and push_swap libraries
all: $(LIBFT) $(NAME)

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
