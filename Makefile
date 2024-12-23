NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = /libft
LIBFR = $(LIBFT_DIR)/
LIBFT_INC = $(LIBFT_DIR)

SRCS = src/pa.c src/pb.c src/ra.c src/rb.c src/rr.c src/rra.c src/rrb.c src/rrr.c src/sa.c src/sb.c src/ss.c src/push_swap.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT)

$(LIBFT):
	make -c $(LIBFT_DIR)

$(OBJS): %.o: %.c
	$(CC) $(CFLAGS) -$(LIBFT_INC) -v $< -o $@

clean:
	rm -f $(OBJS)
	make clean -c $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -c $(LIBFT_DIR)

re: fclean all

.PHONY:
