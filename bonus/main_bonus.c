/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 06:44:39 by pfuchs            #+#    #+#             */
/*   Updated: 2022/04/27 07:56:15 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#include "parse_arguments.h"
#include "stack.h"
#include "libft.h"
#include "bonus.h"

static void	cleanup(t_stack *s1, t_stack *s2)
{
	stack_free(s1);
	stack_free(s2);
}

static int	init(t_stack *s1, t_stack *s2, int *command_index, int argc)
{
	int	error;

	error = 0;
	error += stack_init(s1, argc * 2, command_index);
	error += stack_init(s2, argc * 2, command_index);
	return (error);
}

int	main(int argc, char **argv)
{
	t_stack		s1;
	t_stack		s2;

	if (argc == 1)
		return (0);
	if (init(&s1, &s2, NULL, argc))
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
	get_commands(&s1, &s2);
	cleanup(&s1, &s2);
	return (0);
}
