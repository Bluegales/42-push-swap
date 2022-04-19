/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 20:45:09 by pfuchs            #+#    #+#             */
/*   Updated: 2022/04/19 01:54:51 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

#include <stdio.h>

#include "sort_groups.h"
#include "operation.h"
#include "stack.h"

typedef struct s_sort_data
{
	t_group		*current;
	t_group		*next;
	t_stack		*dst;
	t_stack		*src;
}	t_sort_data;

static int	value_step(t_sort_data d, int group)
{
	int	value;

	value = d.src->data[0];
	if (d.current->number_group[value] != group)
	{
		stack_rotate(d.src);
		return (0);
	}
	//printf("value: %d old_group: %d\n", value, d[-1].group[value]);
	stack_push(d.dst, d.src);
	if (d.next->number_group[value] >= (d.next->group_count) / 2)
		stack_rotate(d.dst);
	return (1);
}

static void	group_step(t_sort_data d, int group)
{
	int	push_counter;

	push_counter = 0;
	while (push_counter < d.current->group_sizes[group])
	{
		push_counter += value_step(d, group);
	}
}

void	sort_step(t_group_data *groups, int id, t_stack *dst, t_stack *src)
{
	t_sort_data	d;
	int	i;

	d.current = &groups->push_groups[id];
	d.next = &groups->real_groups[id-1];
	d.dst = dst;
	d.src = src;
	i = 0;
	while (src->data_size > 0)
	{
		group_step(d, i);
		i++;
	}
}

void sort(t_group_data *groups, t_stack *s1, t_stack *s2)
{
	int	i;

	i = 0;
	//printf("enter sort\n");
	//printf("  needs %d steps\n", groups->last_group + 1);
	while (groups->last_group > 0)
	{
		if (groups->last_group % 2 == 0)
		{
			sort_step(groups, groups->last_group, s1, s2);
			//printf("stack now:\n");
			//stack_print(s1, 8, 1);
		}
		else
		{
			sort_step(groups, groups->last_group, s2, s1);
			//printf("stack now:\n");
			//stack_print(s2, 8, 1);
		}
		i++;
		groups->last_group--;
	}
	operation_finish(&groups->push_groups[0], s1, s2);
}
