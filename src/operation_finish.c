/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_finish.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 22:33:22 by pfuchs            #+#    #+#             */
/*   Updated: 2022/04/27 02:34:20 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operation.h"

#include "stack.h"
#include "sort_groups.h"

#include <stdio.h>

typedef struct s_step_data
{
	t_group	*d;
	t_stack	*dst;
	t_stack	*src;
	int		group_id;
	int		stack_size;
}	t_step_data;

static void	step_value_sw(t_step_data *d, int *rotation_count, int *push_count)
{
	if (*push_count - *rotation_count >= 2)
	{
		if (d->dst->data[0] - d->dst->data[1] == 1)
			stack_swap(d->dst);
		if ((int)d->dst->data[0] - (int)d->dst->data[1] < -1)
			stack_swap(d->dst);
	}
}

static void	step_value(t_step_data *d, int *rotation_count, int *push_count)
{
	int	value;

	value = d->src->data[0];
	if (d->d->number_group[value] != d->group_id)
	{
		stack_rotate(d->src);
		return ;
	}
	stack_push(d->dst, d->src);
	(*push_count)++;
	if ((int)value >= d->stack_size / 2 - 1)
	{
		if (value - d->dst->data[d->dst->data_size - 1] == 1)
		{
			if (d->dst->data[1] - value == 1)
			{
				stack_rotate(d->dst);
				(*rotation_count)++;
			}
			stack_rotate(d->dst);
			(*rotation_count)++;
		}
	}
	step_value_sw(d, rotation_count, push_count);
}

static void	finish_group(t_group *d, t_stack *dst, t_stack *src, int group_id)
{
	t_step_data	data;
	int			rotation_counter;
	int			push_counter;

	push_counter = 0;
	rotation_counter = 0;
	data.src = src;
	data.dst = dst;
	data.stack_size = src->data_size;
	data.d = d;
	data.group_id = group_id;
	while (push_counter < d->group_sizes[group_id])
	{
		step_value(&data, &rotation_counter, &push_counter);
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
