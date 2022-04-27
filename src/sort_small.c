/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 16:44:54 by pfuchs            #+#    #+#             */
/*   Updated: 2022/04/27 02:58:12 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

#include <stdio.h>

// sorts stack of 2 in 1, stack of 3 in 2 operations
static void	sort_3(t_stack *s1)
{
	if (s1->data_size == 3)
	{
		if (s1->data[0] > s1->data[1] && s1->data[0] > s1->data[2])
			stack_rotate(s1);
		if (s1->data[1] > s1->data[0] && s1->data[1] > s1->data[2])
			stack_reverse_rotate(s1);
	}
	if (s1->data_size >= 2)
	{
		if (s1->data[0] > s1->data[1])
			stack_swap(s1);
	}
}

static void	sort_5_2(t_stack *s1, t_stack *s2,
	unsigned int *min, unsigned int *max)
{
	int	i;

	i = 0;
	while (i < s1->data_size)
	{
		if (s1->data[i] < *min)
			*min = s1->data[i];
		if (s1->data[i] > *max)
			*max = s1->data[i];
		i++;
	}
	while (s1->data_size > 3)
	{
		if (s1->data[0] == *min || s1->data[0] == *max)
			stack_push(s2, s1);
		else
			stack_rotate(s1);
	}
}

static void	sort_5(t_stack *s1, t_stack *s2)
{
	unsigned int	min;
	unsigned int	max;

	min = s1->data[0];
	max = s1->data[0];
	sort_5_2(s1, s2, &min, &max);
	sort_3(s1);
	while (s2->data_size != 0)
	{
		stack_push(s1, s2);
		if (s1->data[0] == max)
			stack_rotate(s1);
	}
}

void	sort_small(t_stack *s1, t_stack *s2)
{
	int	size;

	size = s1->data_size;
	if (size <= 5)
		sort_5(s1, s2);
}
