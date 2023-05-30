CC		= cc
CFLAGS	= -Wall -Wextra -Werror -I.
DEBUG	= -fsanitize=address -g
NAME	= get_next_line
SRCS	= get_next_line.c \
		  get_next_line_utils.c
OBJS 	= $(SRCS:.c=.o)
INCS	= get_next_line.h

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

test: $(NAME)
	$(CC) $(CFLAGS) $(DEBUG) main.c $^ -o test

.PHONY: all clean fclean re test
