/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 12:15:06 by pfuchs            #+#    #+#             */
/*   Updated: 2022/04/17 20:26:51 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_arguments.h"

#include <limits.h>
#include <stack.h>
#include "libft.h"


#include <stdio.h>

static int	get_uint(char *str, unsigned int *ret_number)
{
	int		sign;

	sign = 0;
	if (*str == '-')
		sign = 1;
	if (*str == '-' || *str == '+')
		str++;
	if (ft_strlen(str) > 10 || ft_strlen(str) == 0)
		return (2);
	if (ft_strlen(str) == 10 && ft_strncmp(str, "2147483648", 11) > 0)
		return (2);
	if (ft_strlen(str) == 10 && sign == 1 && ft_strncmp(str, "2147483647", 11) > 0)
		return (2);
	*ret_number = 0;
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (1);
		*ret_number = *ret_number * 10 + (*str - '0');
		str++;
	}
	if (!sign)
		*ret_number -= INT_MIN;
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
	int				i;

	i = 0;
	while (i < argc - 1)
	{
		if (get_uint(argv[i + 1], stack + i))
			return (2);
		i++;
	}
	reduce(stack, argc - 1);
	if (check_for_dupes(stack, argc - 1))
		return (3);
	i = 0;
	while (i < argc - 1)
	{
		stack[i]--;
		i++;
	}
	return (0);
}
