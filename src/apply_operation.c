/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_operation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 17:20:36 by pfuchs            #+#    #+#             */
/*   Updated: 2022/04/10 17:41:12 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "apply_operation.h"

#include "stack.h"

int	apply_rotation(enum e_operation operation, t_stack s1, t_stack s2)
{
	if (operation == rb || operation == rr)
	{
		s1.top++;
		if (s1.top > s1.size)
			s1.top = 0;
	}
	if (operation == rb || operation == rr)
	{
		s2.top++;
		if (s2.top > s2.size)
			s2.top = 0;
	}
	if (operation == rb || operation == rr)
	{
		s1.top++;
		if (s1.top > s1.size)
			s1.top = 0;
	}
	if (operation == rb || operation == rr)
	{
		s2.top++;
		if (s2.top > s2.size)
			s2.top = 0;
	}
}



int	apply_operation(enum e_operation operation, t_stack s1, t_stack s2)
{

}
