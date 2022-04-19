/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_groups_helper.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 22:28:37 by pfuchs            #+#    #+#             */
/*   Updated: 2022/04/19 03:29:32 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_groups_helper.h"
#include "sort_groups.h"

#include <stdio.h>

#include "stack.h"

static void set_group_sizes(t_group_data *groups, t_group_set_data d)
{
	t_group	*group;
	int	i;
	int	max;

	group = &(groups->real_groups[d.id]);
	if (!d.real)
		group = &(groups->push_groups[d.id]);
	i = 0;
	max = 0;
	while (i < groups->number_count)
	{
		group->group_sizes[group->number_group[i]]++;
		if (group->number_group[i] > max)
			max = group->number_group[i];
		i++;
	}
	group->group_count = max + 1;
}

static void	convert_group(t_group_data *groups, t_group_set_data d, int old, int new)
{
	int	i;
	short	*old_number_group;
	short	*new_number_group;

	new_number_group = groups->real_groups[d.id].number_group;
	if (!d.real)
		new_number_group = groups->push_groups[d.id].number_group;
	if (d.id != 0)
		old_number_group = groups->real_groups[d.id - 1].number_group;
	i = 0;
	while (i < groups->number_count)
	{
		if (d.id == 0 && i == old)
			new_number_group[i] = new;
		if (d.id != 0 && old_number_group[i] == old)
			new_number_group[i] = new;
		i++;
	}
}

void	print_group(t_group_data *groups, t_group_set_data d)
{
	t_group	*group;
	int	i;

	printf("group %d: real %d\n", d.id, d.real);
	group = &(groups->real_groups[d.id]);
	if (!d.real)
		group = &(groups->push_groups[d.id]);
	printf("  groupcount %d\n", group->group_count);
	i = 0;
	while (i < group->group_count)
	{
		printf("    group %d size %d: ", i, group->group_sizes[i]);
		int j = 0;
		while (j < groups->number_count)
		{
			if (group->number_group[j] == i)
				printf("%4d", j);
			j++;
		}
		printf("\n");
		i++;
	}
}

void	set_group(t_group_data *groups, t_group_set_data d, t_stack *stack)
{
	int	i;
	int	missing;

	missing = d.max_size - stack->data_size % d.max_size;
	if (missing == d.max_size)
		missing = 0;
	i = 0;
	while (i < stack->data_size)
	{
		convert_group(groups, d, stack->data[i], (i + missing) / d.max_size);
		i++;
	}
	set_group_sizes(groups, d);
	//print_group(groups, d);
}
