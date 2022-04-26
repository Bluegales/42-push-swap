/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 21:17:04 by pfuchs            #+#    #+#             */
/*   Updated: 2022/04/26 22:55:48 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

#include <stdlib.h> // malloc free
#include <unistd.h> // write

#include <stdio.h>

enum e_merge_command {
	swap_1 = 0,
	rotate_1 = 1,
	reverse_rotate_1 = 2,
	swap_2 = 3,
	rotate_2 = 4,
	reverse_rotate_2 = 5,
	swap_both = 6,
	rotate_both = 7,
	reverse_rotate_both = 8,
	push_1 = 9,
	push_2 = 10,
	error = 11
};

static const char	*g_command_strings[] = {
	"sa",
	"ra",
	"rra",
	"sb",
	"rb",
	"rrb",
	"ss",
	"rr",
	"rrr",
	"pa",
	"pb",
	"ERR"
};

static enum e_merge_command	get_next_command_same(t_commands *cmd1,
	t_commands *cmd2)
{
	enum e_merge_command	command;

	command = error;
	if (cmd1->array->command == push && cmd2->array->command == pull)
		command = push_1;
	else if (cmd1->array->command == pull && cmd2->array->command == push)
		command = push_2;
	else if (cmd1->array->command == swap && cmd2->array->command == swap)
		command = swap_both;
	else if (cmd1->array->command == rotate && cmd2->array->command == rotate)
		command = rotate_both;
	else if (cmd1->array->command == reverse_rotate
		&& cmd2->array->command == reverse_rotate)
		command = reverse_rotate_both;
	cmd1->array++;
	cmd1->size--;
	cmd2->array++;
	cmd2->size--;
	return (command);
}

static enum e_merge_command	get_next_command(t_commands *cmd1, t_commands *cmd2)
{
	enum e_merge_command	command;
	t_commands				*next;

	command = error;
	next = cmd1;
	if (cmd1->size != 0 && cmd2->size != 0)
	{
		if (cmd1->array->index == cmd2->array->index
			|| cmd1->array->command == cmd2->array->command)
			return (get_next_command_same(cmd1, cmd2));
		if (cmd1->array->index > cmd2->array->index)
			next = cmd2;
	}
	if (cmd1->size == 0)
		next = cmd2;
	command = (enum e_merge_command)next->array->command;
	if (next == cmd2)
		command += 3;
	next->array++;
	next->size--;
	return (command);
}

static int	fill_print(enum e_merge_command *commands, char *print, int size)
{
	int			i;
	const char	*command_it;
	char		*print_it;

	i = 0;
	print_it = print;
	while (i < size)
	{
		command_it = g_command_strings[commands[i]];
		while (*command_it)
		{
			*print_it = *command_it;
			print_it++;
			command_it++;
		}
		*print_it = '\n';
		print_it++;
		i++;
	}
	*print_it = '\n';
	return ((int)(print_it - print));
}

int	commands_print(t_commands cmd1, t_commands cmd2)
{
	enum e_merge_command	*commands;
	char					*print;
	int						i;
	int						size;

	commands = malloc(sizeof(enum e_merge_command) * (cmd1.size + cmd2.size));
	if (!commands)
		return (1);
	i = 0;
	while (cmd1.size != 0 || cmd2.size != 0)
	{
		commands[i] = get_next_command(&cmd1, &cmd2);
		i++;
	}
	print = malloc(i * 4 + 4);
	if (!print)
	{
		free(commands);
		return (1);
	}
	size = fill_print(commands, print, i);
	write(1, print, size);
	free(commands);
	free(print);
	return (0);
}
