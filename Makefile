CC			= cc
CFLAGS		= -Wall -Wextra -Werror -I.
DEBUG		= -fsanitize=address -g
NAME		= get_next_line
SRCS		= get_next_line.c \
			  get_next_line_utils.c \
			  main.c
OBJS 		= $(SRCS:.c=.o)
INCS		= get_next_line.h
BONUS_SRCS	= get_next_line_bonus.c \
			  get_next_line_utils_bonus.c \
			  main.c
BONUS_OBJS	= $(BONUS_SRCS:.c=.o)
BONUS_INCS	= get_next_line_bonus.h

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus: $(BONUS_OBJS)
	$(CC) $(CFLAGS) $^ -o $@

test: $(OBJS)
	$(CC) $(CFLAGS) $(DEBUG) $^ -o test

test_bonus: $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(DEBUG) $^ -o test

.PHONY: all clean fclean re bonus test
