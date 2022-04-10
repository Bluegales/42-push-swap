/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 12:14:22 by pfuchs            #+#    #+#             */
/*   Updated: 2022/04/10 17:35:49 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "parse_arguments.h"
#include "stack.h"

#include <stdio.h>

static void	cleanup(t_stack *s1, t_stack *s2)
{
	free(s1->s);
	free(s2->s);
}

static int	init(t_stack *s1, t_stack *s2, int argc)
{
	s1->s = malloc(sizeof(int) * argc);
	s2->s = malloc(sizeof(int) * argc);
	if (!s1->s || !s2->s)
	{
		cleanup(s1, s2);
		return (1);
	}
	s1->top = 0;
	s2->top = 0;
	s1->size = argc - 1;
	s2->size = 0;
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack		s1;
	t_stack		s2;

	if (argc == 1)
		return (0);
	if (init(&s1, &s2, argc))
		return (1);
	if (parse_arguments(argc, argv, s1.s))
	{
		cleanup(&s1, &s2);
		return (1);
	}
}
