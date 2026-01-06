NAME = push_swap
HEADER = push_swap.h
CC = cc
CFLAGS= -Wall -Wextra -Werror
MY_SRC = main.c \
		 validator.c \
         parser.c    \
		 stack_utils.c \
		 swap_operations.c \
		 push_operations.c \
		 rotate_operations.c\
		 r_rotate_operations.c\
		 push_swap.c       \
		 algorithm.c \
		 algorithm_utils.c \
		 chunk.c

MY_OBJ = $(MY_SRC:.c=.o)
LIBFT_DIR=libft
LIBFT= $(LIBFT_DIR)/libft.a
RM = rm -f

all: $(NAME)

$(NAME): $(LIBFT) $(MY_OBJ)
	$(CC) $(CFLAGS) $(MY_OBJ) -L$(LIBFT_DIR) -lft -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c -I. -I$(LIBFT_DIR) $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	make -C $(LIBFT_DIR) clean
	$(RM) $(MY_OBJ)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re