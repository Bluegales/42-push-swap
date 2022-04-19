/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 17:23:08 by pfuchs            #+#    #+#             */
/*   Updated: 2022/04/16 19:56:11 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

#include "commands.h"

typedef struct s_stack
{
	unsigned int	*array;
	int				array_size;
	unsigned int	*data;
	int				data_size;
	t_commands		commands;
	int				*command_index;
}	t_stack;

int		stack_init(t_stack *stack, int allocated_size, int *command_index);
void	stack_free(t_stack *stack);
int		stack_push(t_stack *dest, t_stack *src);
int		stack_rotate(t_stack *stack);
int		stack_reverse_rotate(t_stack *stack);
int		stack_swap(t_stack *stack);

void	stack_print(t_stack *stack, int newline, int rest_top);

#endif // STACK_H
