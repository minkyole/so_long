# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minkyole <minkyole@student.42seoul.>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/20 21:57:01 by minkyole          #+#    #+#              #
#    Updated: 2023/05/20 21:57:02 by minkyole         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -Lmlx -lmlx -framework OpenGL -framework Appkit
NAME = a.out
LIBFT = ./libft/libft.a
LIBFT_DIR = libft
SRCS = so_long.c so_long_util1.c so_long_util2.c so_long_util3.c so_long_util4.c
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

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -I$(LIBFT_DIR) -c $^ -o $@

$(LIBFT):
	make -C $(LIBFT_DIR) all
