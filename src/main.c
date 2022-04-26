/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 12:14:22 by pfuchs            #+#    #+#             */
/*   Updated: 2022/04/26 23:42:50 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

#include "parse_arguments.h"
#include "stack.h"
#include "push_swap.h"

static void	cleanup(t_stack *s1, t_stack *s2)
{
	stack_free(s1);
	stack_free(s2);
}

static int	init(t_stack *s1, t_stack *s2, int *command_index, int argc)
{
	int	error;

	error = 0;
	*command_index = 0;
	error += stack_init(s1, argc * 2, command_index);
	error += stack_init(s2, argc * 2, command_index);
	return (error);
}

#include "stdio.h"

int	main(int argc, char **argv)
{
	t_stack		s1;
	t_stack		s2;
	int			command_index;
	int			space[200];

	(void)space;
	if (argc == 1)
		return (0);
	if (init(&s1, &s2, &command_index, argc))
	{
		cleanup(&s1, &s2);
		return (1);
	}
	if (parse_arguments(&argc, argv, s1.array))
	{
		cleanup(&s1, &s2);
		return (2);
	}
	s1.data = s1.array;
	s1.data_size = argc - 1;
	push_swap(&s1, &s2);
	cleanup(&s1, &s2);
	scanf("asd");
	return (0);
}
