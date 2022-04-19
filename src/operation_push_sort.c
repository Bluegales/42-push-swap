/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_push_sort.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 18:16:15 by pfuchs            #+#    #+#             */
/*   Updated: 2022/04/17 17:47:43 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operation.h"

#include "stack.h"

int	operation_push_sort(t_push_sort d)
{
	//stack_print(data.src);
	while (d.count--)
	{
		if ((d.push_offset > 0 && (int)*d.src->data > d.push_offset)
			|| (d.push_offset < 0 && (int)*d.src->data < -d.push_offset))
		{
			if (stack_push(d.dest, d.src))
				return (1);
			if ((d.sort_offset > 0 && (int)*d.dest->data > d.sort_offset)
				|| (d.sort_offset < 0 && (int)*d.dest->data < -d.sort_offset))
			{
				stack_rotate(d.dest);
			}
		}
		else
		{
			stack_rotate(d.src);
		}
		//stack_print(data.src);
	}
	return (0);
}
