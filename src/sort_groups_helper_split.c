/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_groups_helper_split.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 18:13:42 by pfuchs            #+#    #+#             */
/*   Updated: 2022/04/26 22:47:40 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_groups_helper.h"

#include <stdlib.h>
#include <stdio.h>

#include "stack.h"

void	split_end_8(t_stack *dst, t_stack *src)
{
	int	original_size;

	original_size = src->data_size;
	while (src->data_size > 0)
	{
		if (src->data_size <= original_size / 2)
		{
			stack_reverse_rotate(dst);
			stack_reverse_rotate(dst);
			stack_reverse_rotate(dst);
			stack_reverse_rotate(dst);
		}
		stack_push(dst, src);
		stack_push(dst, src);
		stack_reverse_rotate(src);
		stack_push(dst, src);
		stack_reverse_rotate(src);
		stack_push(dst, src);
	}
}

void	split_end_4(t_stack *dst, t_stack *src)
{
	while (src->data_size > 0)
	{
		stack_push(dst, src);
		stack_push(dst, src);
		stack_reverse_rotate(src);
		stack_push(dst, src);
		stack_reverse_rotate(src);
		stack_push(dst, src);
	}
}

void	split_4(t_stack *dst, t_stack *src)
{
	int	original_size;

	original_size = src->data_size;
	while (src->data_size > 0)
	{
		if (src->data_size < original_size / 2)
		{
			stack_reverse_rotate(dst);
			stack_reverse_rotate(dst);
		}
		stack_push(dst, src);
		stack_reverse_rotate(src);
		stack_push(dst, src);
	}
}

void	split_2(t_stack *dst, t_stack *src)
{
	while (src->data_size > 0)
	{
		stack_push(dst, src);
		stack_reverse_rotate(src);
		stack_push(dst, src);
	}
}
