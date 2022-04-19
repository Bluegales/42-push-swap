/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_group_solve.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 00:00:22 by pfuchs            #+#    #+#             */
/*   Updated: 2022/04/18 18:55:50 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operation.h"

#include <stdio.h>

#include "stack.h"

static int	value_step(t_group *d, t_stack *dst, t_stack *src, int group)
{
	int	value;

	value = src->data[0];
	if (d->group[value] != group)
	{
		stack_rotate(src);
		return (0);
	}
	//printf("value: %d old_group: %d\n", value, d[-1].group[value]);
	stack_push(dst, src);
	if (d[-1].group[value] > (d[-1].group_count) / 2)
		stack_rotate(dst);
	return (1);
}

static void	group_step(t_group *d, t_stack *dst, t_stack *src, int group)
{
	int	push_counter;

	push_counter = 0;
	while (push_counter < d->group_sizes[group])
	{
		push_counter += value_step(d, dst, src, group);
	}
}

void	operation_step(t_group *d, t_stack *dst, t_stack *src)
{
	int	i;

	i = 0;
	while (src->data_size > 0)
	{
		group_step(d, dst, src, i);
		i++;
	}
}
