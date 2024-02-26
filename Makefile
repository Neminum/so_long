# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tobias <tobias@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/27 15:40:37 by tsurma            #+#    #+#              #
#    Updated: 2024/02/21 13:51:52 by tsurma           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra -g3
NAME = so_long
MLXFLAGS = -Iinclude -ldl -lglfw -pthread -lm
MAKEFLAGS = --no-print-directory

SRC = so_long.c\
     so_long_map.c\
     so_long_mlx.c\
    so_long_path.c 

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME) : $(OBJ)
	@ make -C libft
	$(CC) $(CFLAGS) $(MLXFLAGS) -o $(NAME) $(OBJ) libft/libft.a ../MLX42/build/libmlx42.a

clean :
	make fclean -C libft
	@-rm -f $(OBJ)

fclean : clean
	@-rm -f $(NAME)

re : fclean all


.PHONY : clean fclean re all
