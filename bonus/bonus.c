/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 07:29:32 by pfuchs            #+#    #+#             */
/*   Updated: 2022/05/04 15:15:51 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#include "parse_arguments.h"
#include "stack.h"
#include "libft.h"

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
	end = 11,
	error = 12
};

static const char	*g_command_strings[] = {
	"sa\n",
	"ra\n",
	"rra\n",
	"sb\n",
	"rb\n",
	"rrb\n",
	"ss\n",
	"rr\n",
	"rrr\n",
	"pa\n",
	"pb\n",
	"\n"
};

static int	is_sorted(t_stack *s1)
{
	int	i;

	i = 0;
	while (i < s1->data_size)
	{
		if (i != (int)(s1->data[i]))
		{
			return (0);
		}
		i++;
	}
	return (1);
}

static void	apply_commands_2(t_stack *s1, t_stack *s2, int cmd)
{
	if (cmd == rotate_1)
		stack_rotate(s1);
	if (cmd == reverse_rotate_1)
		stack_reverse_rotate(s1);
	if (cmd == swap_2)
		stack_swap(s2);
	if (cmd == rotate_2)
		stack_rotate(s2);
	if (cmd == reverse_rotate_2)
		stack_reverse_rotate(s2);
	if (cmd == swap_both)
	{
		stack_swap(s1);
		stack_swap(s2);
	}
	if (cmd == rotate_both)
	{
		stack_rotate(s1);
		stack_rotate(s2);
	}
	if (cmd == reverse_rotate_both)
	{
		stack_reverse_rotate(s1);
		stack_reverse_rotate(s2);
	}
}

static int	apply_command(t_stack *s1, t_stack *s2, int cmd)
{
	if (cmd == swap_1)
		stack_swap(s1);
	apply_commands_2(s1, s2, cmd);
	if (cmd == push_1)
		stack_push(s1, s2);
	if (cmd == push_2)
		stack_push(s2, s1);
	if (cmd == end)
	{
		if (is_sorted(s1))
		{
			write(1, "OK\n", 3);
			return (1);
		}
		write(1, "KO\n", 3);
		return (1);
	}
	return (0);
}

static void	find_eol(int *size_read, char *buffer)
{
	if (*size_read == 0)
	{
		ft_memcpy(buffer, "\n", 1);
		*size_read = 1;
	}
}

int	get_commands(t_stack *s1, t_stack *s2)
{
	int		i;
	int		size_read;
	char	buffer[4];

	while (1)
	{
		size_read = read(0, buffer, 4);
		if (size_read == -1)
		{
			write(2, "ERROR\n", 6);
			return (1);
		}
		find_eol(&size_read, buffer);
		i = 0;
		while (i < 12 && ft_strncmp(g_command_strings[i], buffer, size_read))
			i++;
		if (i == error)
		{
			write(2, "ERROR\n", 6);
			return (1);
		}
		if (apply_command(s1, s2, i))
			return (0);
	}
}
