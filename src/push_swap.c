/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 18:16:10 by pfuchs            #+#    #+#             */
/*   Updated: 2022/04/26 23:42:08 by pfuchs           ###   ########.fr       */
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
		groups->push_groups[i].number_group = ft_calloc(2UL, n);
		groups->real_groups[i].number_group = ft_calloc(2UL, n);
		groups->push_groups[i].group_sizes = ft_calloc(2UL, 1 + n / 4);
		groups->real_groups[i].group_sizes = ft_calloc(2UL, 1 + n / 4);
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

int	push_swap(t_stack *s1, t_stack *s2)
{
	t_group_data	groups;
	int				steps;

	if (s1->data_size <= 5)
	{
		sort_small(s1, s2);
		return (0);
	}
	while (!is_sorted(s1))
	{
		if (init_groups(&groups, s1->data_size))
			return (1);
		steps = get_sort_groups(&groups);
		if (steps < 0)
			return (1);
		sort(&groups, s1, s2);
	}
	cleanup_groups(&groups);
	commands_print(s1->commands, s2->commands);
	return (0);
}
