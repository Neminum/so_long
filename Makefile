# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsurma <tsurma@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/27 15:40:37 by tsurma            #+#    #+#              #
#    Updated: 2024/02/14 12:13:29 by tsurma           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra -g3
NAME = 
MAKEFLAGS = --no-print-directory

SRC = 

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME) : $(OBJ)
	@ make -C libft
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) libft/*.o

clean :
	make fclean -C libft
	@-rm -f $(OBJ)

fclean : clean
	@-rm -f $(NAME)

re : fclean all


.PHONY : clean fclean re all
