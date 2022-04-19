/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_finish.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 22:33:22 by pfuchs            #+#    #+#             */
/*   Updated: 2022/04/19 03:36:48 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operation.h"

#include "stack.h"
#include "sort_groups.h"

#include <stdio.h>

static void step_value(t_group *d, t_stack *dst, t_stack *src, int group_id, int *rotation_count, int *push_count, int stack_size)
{
	int	value;

	value = src->data[0];
	if (d->number_group[value] != group_id)
	{
		stack_rotate(src);
		return ;
	}
	stack_push(dst, src);
	(*push_count)++;
	if ((int)value >= stack_size / 2)
	{
		if (value - dst->data[dst->data_size - 1] == 1)
		{
			if (dst->data[1] - value == 1)
			{
				stack_rotate(dst);
				(*rotation_count)++;
			}
			stack_rotate(dst);
			(*rotation_count)++;
		}
	}
	if (*push_count - *rotation_count >= 2)
	{
		if (dst->data[0] - dst->data[1] == 1)
			stack_swap(dst);
		if ((int)dst->data[0] - (int)dst->data[1] < -1)
			stack_swap(dst);
	}
}

static void finish_group(t_group *d, t_stack *dst, t_stack *src, int group_id)
{
	int	stack_size;
	int	rotation_counter;
	int	push_counter;

	stack_size = src->data_size;
	push_counter = 0;
	rotation_counter = 0;
	while (push_counter < d->group_sizes[group_id])
	{
		step_value(d, dst, src, group_id, &rotation_counter, &push_counter, stack_size);
	}
}

void	operation_finish(t_group *d, t_stack *dst, t_stack *src)
{
	int	i;
	i = 0;
	while (src->data_size)
	{
		finish_group(d, dst, src, i);
		i++;
	}
}
