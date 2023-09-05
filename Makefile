NAME		= get_next_line
BONUS_NAME	= bonus
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
LIBRARY		= -L$(LIBFT_DIR) -lft
INCLUDES	= -I$(HDR_DIR) -I$(LIBFT_DIR)

LIBFT		= $(LIBFT_DIR)libft.a
LIBFT_DIR	= ./libft/
LIBFT_HDR	= $(LIBFT_DIR)libft.h

HDR_LIST	= get_next_line.h get_next_line_bonus.h
HDR_DIR		= ./
HDR			= $(addprefix $(HDR_DIR), $(HDR_LIST))

SRCS		= get_next_line.c main.c
BONUS_SRCS	= get_next_line_bonus.c main_bonus.c

OBJS 		= $(SRCS:.c=.o)
BONUS_OBJS	= $(BONUS_SRCS:.c=.o)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBRARY)

all: $(NAME)

bonus: $(BONUS_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBRARY)


$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all clean fclean re bonus
