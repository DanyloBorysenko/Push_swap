NAME = push_swap
HEADER = push_swap.h
CC = cc
CFLAGS= -Wall -Wextra -Werror
MY_SRC = push_swap.c \
         validator.c

$(NAME): $(MY_SRC) $(HEADER)
	$(CC) $(CFLAGS) $(MY_SRC) -I. -o $(NAME)