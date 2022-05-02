/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arguments_reduce.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 22:44:01 by pfuchs            #+#    #+#             */
/*   Updated: 2022/05/02 14:31:21 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_arguments.h"

#include <limits.h>

static void	reduce_2(unsigned int *stack, unsigned int lowest, int i, int size)
{
	int	j;

	j = 0;
	if ((lowest != (unsigned int)i) || i == 0)
	{
		while (j < size)
		{
			if (stack[j] > (unsigned int)i)
			{
				stack[j] -= lowest;
				stack[j] += i;
			}
			j++;
		}
	}
}

void	reduce(unsigned int *stack, int size)
{
	int				i;
	int				j;
	unsigned int	lowest;

	i = 0;
	while (i < size)
	{
		j = 0;
		lowest = UINT_MAX;
		while (j < size)
		{
			if (lowest > stack[j] && stack[j] >= (unsigned int)i)
				lowest = stack[j];
			j++;
		}
		reduce_2(stack, lowest, i, size);
		i++;
	}
}
