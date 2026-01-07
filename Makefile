NAME = push_swap
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

BONUS_DIR = bonus
CHECKER = checker
MY_BONUS_SRC = $(BONUS_DIR)/checker.c \
			   $(BONUS_DIR)/main.c \
			   $(BONUS_DIR)/parser.c \
			   $(BONUS_DIR)/validator.c\
			   $(BONUS_DIR)/stack_utils.c\
			   $(BONUS_DIR)/stack_operations.c\
			   $(BONUS_DIR)/exec_instructions.c

MY_OBJ = $(MY_SRC:.c=.o)
MY_BONUS_OBJ = $(MY_BONUS_SRC:.c=.o)

LIBFT_DIR=libft
LIBFT= $(LIBFT_DIR)/libft.a
RM = rm -f

all: $(NAME)

$(NAME): $(LIBFT) $(MY_OBJ)
	$(CC) $(CFLAGS) $(MY_OBJ) -L$(LIBFT_DIR) -lft -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c -I. -I$(LIBFT_DIR) -I$(BONUS_DIR) $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)

bonus: $(LIBFT) $(MY_BONUS_OBJ)
	$(CC) $(CFLAGS) $(MY_BONUS_OBJ) -L$(LIBFT_DIR) -lft -o $(CHECKER)

clean:
	make -C $(LIBFT_DIR) clean
	$(RM) $(MY_OBJ)
	$(RM) $(MY_BONUS_OBJ)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)
	$(RM) $(CHECKER)

re: fclean all

.PHONY: all bonus clean fclean re