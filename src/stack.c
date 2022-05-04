/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 18:16:01 by pfuchs            #+#    #+#             */
/*   Updated: 2022/05/04 15:19:01 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

#include "commands.h"
#include "libft.h"

static void	stack_center(t_stack *stack)
{
	unsigned int	*new_data;

	new_data = (stack->array_size - stack->data_size) / 2 + stack->array;
	ft_memmove(new_data, stack->data, stack->data_size * sizeof(int));
	stack->data = new_data;
}

int	stack_push(t_stack *dest, t_stack *src)
{
	if (src->data_size < 1)
		return (0);
	if (dest->data == dest->array)
		stack_center(dest);
	dest->data--;
	dest->data_size++;
	*dest->data = *src->data;
	src->data++;
	src->data_size--;
	if (commands_push(&src->commands, pull, src->command_index))
		return (1);
	if (commands_push(&dest->commands, push, dest->command_index))
		return (1);
	return (0);
}

int	stack_rotate(t_stack *stack)
{
	if (stack->data_size < 2)
		return (0);
	if (stack->data + stack->data_size == stack->array + stack->array_size)
		stack_center(stack);
	*(stack->data + stack->data_size) = *stack->data;
	stack->data++;
	if (commands_push(&stack->commands, rotate, stack->command_index))
		return (1);
	return (0);
}

int	stack_reverse_rotate(t_stack *stack)
{
	if (stack->data_size < 2)
		return (0);
	if (stack->data == stack->array)
		stack_center(stack);
	stack->data--;
	*stack->data = *(stack->data + stack->data_size);
	if (commands_push(&stack->commands, reverse_rotate, stack->command_index))
		return (1);
	return (0);
}

int	stack_swap(t_stack *stack)
{
	int	temp;

	if (stack->data_size < 2)
		return (1);
	temp = *stack->data;
	*stack->data = *(stack->data + 1);
	*(stack->data + 1) = temp;
	if (commands_push(&stack->commands, swap, stack->command_index))
		return (1);
	return (0);
}

//Only needed for debugging purpose

/* #include "stdio.h"

void	stack_print(t_stack *stack, int new_line, int rest_top)
{
	int i = 0;
	int rest = stack->data_size % (new_line * 2);
	if (rest_top == 2)
	{
		while (i < (stack->data_size - rest) / 2)
		{
			if (i % new_line == 0 && i)
				printf("\n");
			printf("%3u ", stack->data[i]);
			i++;
		}
		if (rest)
			printf("\n");
		if (rest && rest < new_line)
			printf("\n");
		while (i < stack->data_size)
		{
			if ((stack->data_size - i) % new_line == 0)
					printf("\n");
			printf("%3u ", stack->data[i]);
			i++;
		}
	}
	while (i < stack->data_size)
	{
		if (rest_top)
		{
			if ((stack->data_size - i) % new_line == 0 && i)
				printf("\n");
		}
		else
		{
			if (i % new_line == 0 && i)
				printf("\n");
		}
		printf("%3u ", stack->data[i]);
			i++;
	}
	printf("\n");
} */
