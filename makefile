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
NAME = so_long
BNAME = so_long_bonus
LIBFT = ./libft/libft.a
LIBFT_DIR = libft
MLX = ./mlx/libmlx.a
MLX_DIR = mlx/mlx_custom
SRCS = so_long.c so_long_util1.c so_long_util2.c so_long_util3.c so_long_util4.c so_long_util5.c so_long_util6.c so_long_util7.c so_long_util8.c so_long_util9.c
BSRCS = so_long_bonus.c so_long_util1_bonus.c so_long_util2_bonus.c so_long_util3_bonus.c so_long_util4_bonus.c so_long_util5_bonus.c so_long_util6_bonus.c so_long_util7_bonus.c so_long_util8_bonus.c so_long_util9_bonus.c so_long_util10_bonus.c
OBJS = $(SRCS:.c=.o)
BOBJS = $(BSRCS:.c=.o)

.PHONY : clean fclean re all bonus

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(MLXFLAGS) $^ -o $@

clean:
	rm -f $(OBJS) $(BOBJS)
	make -C $(LIBFT_DIR) fclean
	make -C $(MLX_DIR) clean

fclean:
	$(MAKE) clean
	rm -f $(BNAME) rm -f $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

bonus: $(BNAME)

$(BNAME): $(BOBJS) $(LIBFT) $(MLX)
	$(CC) $(CFALGS) $(MLXFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -I$(LIBFT_DIR) -c $^ -o $@

$(LIBFT):
	make -C $(LIBFT_DIR) all

$(MLX):
	make -C $(MLX_DIR)

all: $(BNAME) $(NAME)