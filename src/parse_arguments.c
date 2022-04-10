/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 12:15:06 by pfuchs            #+#    #+#             */
/*   Updated: 2022/04/10 14:44:49 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_arguments.h"

#include <limits.h>

#include "libft.h"



#include <stdio.h>

static int	get_int(char *str, int *ret_number)
{
	int		i;
	int		sign;

	sign = -1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = 1;
		str++;
	}
	if (!*str)
		return (1);
	*ret_number = 0;
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (1);
		i = *ret_number;
		*ret_number = *ret_number * 10 - (*str - '0');
		if (*ret_number > 0)
			return (2);
		str++;
	}
	*ret_number *= sign;
	return (0);
}

static void	reduce(unsigned int *stack, int size)
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
			if (lowest > stack[j] && stack[j] > (unsigned int)i)
				lowest = stack[j];
			j++;
		}
		j = 0;
		if ((lowest != UINT_MAX && lowest != (unsigned int)i) || i == 0)
		{
			while (j < size)
			{
				if (stack[j] > (unsigned int)i)
				{
					stack[j] -= lowest - 1;
					stack[j] += i;
				}
				j++;
			}
		}
		i++;
		// int k = 0;
		// while (k < size)
		// {
		// 	printf("%u\n", stack[k]);
		// 	k++;
		// }
		// printf("\n");
	}
}

static int	check_for_dupes(unsigned int *stack, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		if (stack[i] == (unsigned int)size)
			return (0);
		i++;
	}
	return (1);
}

int	parse_arguments(int argc, char **argv, unsigned int *stack)
{
	int		i;
	int		n;

	i = 0;
	while (i < argc - 1)
	{
		if (get_int(argv[i + 1], &n))
			return (2);
		stack[i] = n - INT_MIN;
		i++;
	}
	reduce(stack, argc - 1);
	if (check_for_dupes(stack, argc - 1))
		return (1);
	return (0);
}
