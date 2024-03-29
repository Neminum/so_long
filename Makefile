# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsurma <tsurma@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/27 15:40:37 by tsurma            #+#    #+#              #
#    Updated: 2024/03/12 15:12:24 by tsurma           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra -g3 -fsanitize=address
NAME = so_long
MLXFLAGS = -Iinclude -ldl -lglfw -pthread -lm
MAKEFLAGS = --no-print-directory

SRC = so_long.c\
	so_long_map.c\
	so_long_mlx.c\
	so_long_path.c\
	so_long_move.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME) : $(OBJ)
	@ make -C libft
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) libft/libft.a ../MLX42/build/libmlx42.a $(MLXFLAGS)

clean :
	make fclean -C libft
	@-rm -f $(OBJ)

fclean : clean
	@-rm -f $(NAME)

re : fclean all


.PHONY : clean fclean re all
