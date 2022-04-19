/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 18:16:10 by pfuchs            #+#    #+#             */
/*   Updated: 2022/04/19 19:35:01 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdlib.h>

#include "stack.h"
#include "operation.h"
#include "commands.h"

#include "sort.h"
#include "sort_groups.h"
#include "libft.h"
#include <stdio.h>

static void	cleanup_groups(t_group_data *groups)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		free(groups->push_groups[i].number_group);
		free(groups->real_groups[i].number_group);
		free(groups->push_groups[i].group_sizes);
		free(groups->real_groups[i].group_sizes);
		i++;
	}
}

static int	init_groups(t_group_data *groups, int n)
{
	int	i;
	int	error;

	i = 0;
	error = 0;
	groups->number_count = n;
	while (i < 6)
	{
		groups->push_groups[i].number_group = ft_calloc(sizeof(short), n);
		groups->real_groups[i].number_group = ft_calloc(sizeof(short), n);
		groups->push_groups[i].group_sizes = ft_calloc(sizeof(short), 1 + n / 4);
		groups->real_groups[i].group_sizes = ft_calloc(sizeof(short), 1 + n / 4);
		if (!groups->push_groups[i].number_group
			|| !groups->real_groups[i].number_group
			|| !groups->push_groups[i].group_sizes
			|| !groups->real_groups[i].group_sizes)
		{
			error++;
		}
		i++;
	}
	if (error)
		cleanup_groups(groups);
	return (error);
}

int	push_swap(t_stack *s1, t_stack *s2)
{
	t_group_data	groups;
	int				steps;

	if (s1->data_size <= 5)
	{
		//printf("small %d\n", s1->data_size);
		sort_small(s1, s2);
	}
	else
	{
		if (init_groups(&groups, s1->data_size))
			return (1);
		steps = get_sort_groups(&groups);
		if (steps < 0)
			return (1);
		sort(&groups, s1, s2);
	}
	commands_print(s1->commands, s2->commands);
	return 0;

	//stack_print(s1, 20, 1);
	//printf("-- getting sort group\n");

	//printf("-- done getting groups\n");

	//operation_step(groups+2, s2, s1);
	//stack_print(s2, 8, 1);
	//operation_finish(groups, s1, s2);
	//stack_print(s1, 20, 1);
	//operation_finish(groups, s1, s2);
	//operation_finish(groups, s2, s1);
	//commands_print(s1->commands, s2->commands);
	//printf("final stack\n");
	//stack_print(s2, 16, 1);
	//printf("size: %d\n", *s1->command_index);

	//cleanup_groups(&groups);
	//printf("exit push_swap\n");

}
