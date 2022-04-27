# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pfuchs <pfuchs@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/10 12:13:51 by pfuchs            #+#    #+#              #
#    Updated: 2022/04/27 07:55:54 by pfuchs           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

VPATH = src bonus

# Compiler Variables
CC		= cc
CFLAGSS	= -Wall -Wextra -Werror -g
INCFLAG	= -Imlx -I include -I libft
# File Variables
NAME	= push_swap
SRC		= main.c parse_arguments.c parse_arguments_reduce.c commands.c commands_print.c stack.c stack_2.c \
			push_swap.c sort.c operation_finish.c count_splits.c\
			sort_groups.c sort_groups_helper.c sort_groups_helper_split.c sort_small.c
BON		= parse_arguments.c parse_arguments_reduce.c stack.c stack_2.c \
			main_bonus.c commands.c bonus.c
OBJ		= $(addprefix _bin/,$(notdir $(SRC:.c=.o)))
BONOBJ	= $(addprefix _bin/,$(notdir $(BON:.c=.o)))

$(NAME): $(OBJ) | libft/libft.a
	$(CC) $(CFLAGS) -o $@ $^ -Llibft -lft

libft/libft.a :
	-(cd libft && make && make clean)

_bin :
	mkdir _bin

_bin/%.o : %.c libft/libft.a | _bin
	$(CC) -c $(CFLAGSS) -MMD -MP $(INCFLAG) $< -o $@

clean:
	@rm -rf _bin

fclean:	clean
	@rm -f $(NAME)

re:		fclean all

all:	$(NAME)

checker:	$(BONOBJ)
	$(CC) $(CFLAGS) -o $@ $^ -Llibft -lft

bonus:	checker

norm:
	norminette $(SRC)

.PHONY: clean fclean re all bonus

-include $(OBJ:.o=.d)
