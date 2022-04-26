/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 13:31:33 by pfuchs            #+#    #+#             */
/*   Updated: 2022/04/26 22:38:03 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMANDS_H
# define COMMANDS_H

enum e_command{
	swap=0,
	rotate=1,
	reverse_rotate=2,
	push=3,
	pull=4
};

typedef struct s_command_data {
	enum e_command	command;
	int				index;
}	t_command_data;

typedef struct s_commands {
	t_command_data	*array;
	int				array_size;
	int				size;
}	t_commands;

int		commands_init(t_commands *commands, int allocation_size);
void	commands_free(t_commands *commands);
int		commands_set_array_size(t_commands *commands, int allocation_size);
int		commands_push(t_commands *commands, enum e_command command, int *index);
int		commands_print(t_commands commands1, t_commands commands2);

#endif // COMMANDS_H
