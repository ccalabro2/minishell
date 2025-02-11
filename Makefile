NAME = minishell
CC = gcc
CFLAGS = -Wall -Werror -Wextra -g -gdwarf-4
LDFLAGS = -lreadline -lncurses -LIBFTDIR
LIBFTDIR = ./libft/Project1/libft.a

SRCS = $(wildcard *.c) \
		$(wildcard ./read/*.c) \
		$(wildcard ./libft/*.c) \
		$(wildcard ./parse/*.c) \
		$(wildcard ./tokenize/*.c)


OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
