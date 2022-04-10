# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pfuchs <pfuchs@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/10 12:13:51 by pfuchs            #+#    #+#              #
#    Updated: 2022/04/10 17:22:12 by pfuchs           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

VPATH = src

# Compiler Variables
CC		= cc
CFLAGSS	= -Wall -Wextra -Werror -g
INCFLAG	= -Imlx -I include -I libft
# File Variables
NAME	= push_swap
SRC		= main.c parse_arguments.c apply_operation.c
OBJ		= $(addprefix _bin/,$(notdir $(SRC:.c=.o)))

$(NAME): $(OBJ) | libft/libft.a
	$(CC) $(CFLAGS) -o $@ $^ -Llibft -lft

libft/libft.a :
	-(cd libft && make && make clean)

_bin :
	mkdir _bin

_bin/%.o : %.c libft/libft.a | _bin
	$(CC) -c $(CFLAGSS) -MMD -MP $(INCFLAG) $< -o $@

clean:
	@rm -f $(OBJ)

fclean:	clean
	@rm -f $(NAME)

re:		fclean all

all:	$(NAME)

norm:
	norminette $(SRC)

.PHONY: clean fclean re all

-include $(OBJ:.o=.d)
