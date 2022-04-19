/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 13:27:01 by pfuchs            #+#    #+#             */
/*   Updated: 2022/04/17 13:09:06 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

#include <stdlib.h>

#include "libft.h"

int	commands_init(t_commands *commands, int allocation_size)
{
	commands->array = malloc(sizeof(t_command_data) * allocation_size);
	if (!commands->array)
		return (1);
	commands->array_size = allocation_size;
	commands->size = 0;
	return (0);
}

void	commands_free(t_commands *commands)
{
	free(commands->array);
	commands->array = NULL;
	commands->array_size = 0;
	commands->size = 0;
}

int	commands_set_array_size(t_commands *commands, int allocation_size)
{
	void	*new_array;

	if (allocation_size < commands->size)
		return (1);
	new_array = malloc(sizeof(t_command_data) * allocation_size);
	if (!new_array)
		return (2);
	ft_memcpy(new_array, commands->array, commands->size * sizeof(t_command_data));
	free(commands->array);
	commands->array = new_array;
	commands->array_size = allocation_size;
	return (0);
}

#include <stdio.h>

int	commands_push(t_commands *commands, enum e_command command, int *index)
{
	if (!index)
		return (0);
	if (commands->array_size - commands->size - 1 < 0)
	{
		if (commands_set_array_size(commands, 100 + commands->size))
			return (1);
	}
	commands->array[commands->size] = (t_command_data) {command, *index};
	commands->size++;
	if (command != pull)
		(*index)++;
	return (0);
}
