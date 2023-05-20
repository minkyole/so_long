CC = cc
CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -Lmlx -lmlx -framework OpenGL -framework Appkit
NAME = a.out
LIBFT = ./libft/libft.a
LIBFT_DIR = libft
SRCS = so_long.c
OBJS = $(SRCS:.c=.o)

.PHONY : clean fclean re all bonus

all: $(NAME)

clean:
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) fclean

fclean:
	$(MAKE) clean
	rm -f $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(MLXFLAGS) $^ -o $@

$(OBJS): $(SRCS)
	$(CC) $(CFLAGS) -Imlx -I$(LIBFT_DIR) -c $^ -o $@

$(LIBFT):
	make -C $(LIBFT_DIR) all
