/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 18:16:07 by pfuchs            #+#    #+#             */
/*   Updated: 2022/04/17 13:16:57 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

#include <stdlib.h> // malloc free

#include "commands.h"
#include "libft.h" // ft_memmove

int	stack_init(t_stack *stack, int allocated_size, int *command_index)
{
	int	error;

	error = 0;
	stack->array_size = allocated_size;
	stack->command_index = command_index;
	stack->data_size = 0;
	stack->array = malloc(sizeof(int) * allocated_size);
	stack->data = stack->array + allocated_size / 2;
	if (!stack->array)
		error++;
	if (command_index)
		error += commands_init(&stack->commands, 100);
	if (error)
	{
		stack_free(stack);
		return (1);
	}
	return (0);
}

void	stack_free(t_stack *stack)
{
	free(stack->array);
	stack->array = NULL;
	if (stack->command_index)
		commands_free(&stack->commands);
}
