NAME = push_swap
HEADER = push_swap.h
CC = cc
CFLAGS= -Wall -Wextra -Werror
MY_SRC = push_swap.c \
		 validator.c \
         parser.c    \
		 basic_operations.c \
		 stack_utils.c \
		 swap_operations.c \
		 push_operations.c \

LIBFT_DIR=libft
LIBFT= libft.a

$(NAME): $(LIBFT) $(MY_SRC) $(HEADER)
	$(CC) $(CFLAGS) $(MY_SRC) -g -I. -I$(LIBFT_DIR) -L$(LIBFT_DIR) -lft -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

all: $(NAME)

clean:
	make -C $(LIBFT_DIR) clean

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -f $(NAME)