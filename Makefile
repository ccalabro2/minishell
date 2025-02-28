NAME = minishell
CC = gcc
CFLAGS = -Wall -Werror -Wextra
LDFLAGS = -lreadline -lncurses -LIBFTDIR
LIBFTDIR = ./libft/Project1/libft.a

SRCS = $(wildcard *.c) \
		$(wildcard ./read/*.c) \
		$(wildcard ./libft/*.c) \
		$(wildcard ./parse/*.c) \
		$(wildcard ./signals/*.c) \
		$(wildcard ./tokenize/*.c) \
		$(wildcard ./builtIn/*.c) \
		$(wildcard ./env/*.c) \
		$(wildcard ./exv/*.c) \
		$(wildcard ./memory/*.c) \



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

