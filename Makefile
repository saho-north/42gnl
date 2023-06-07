CC			= cc
CFLAGS		= -Wall -Wextra -Werror -I.
DEBUG		= -fsanitize=address -g
NAME		= get_next_line
SRCS		= get_next_line.c \
			  get_next_line_utils.c
OBJS 		= $(SRCS:.c=.o)
INCS		= get_next_line.h
BONUS_SRCS	= get_next_line_bonus.c \
			  get_next_line_utils_bonus.c
BONUS_OBJS	= $(BONUS_SRCS:.c=.o)

ifdef ADD_BONUS
OBJS	+= $(BONUS_OBJS)
INCS	+= get_next_line_bonus.h
endif

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
	make ADD_BONUS=1

test:
	$(CC) $(CFLAGS) $(DEBUG) *.c -o test

check:
	$(CC) $(CFLAGS) $(DEBUG) *.c -o a.out
	lldb ./a.out


.PHONY: all clean fclean re bonus test
