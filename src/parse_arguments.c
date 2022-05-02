/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 12:15:06 by pfuchs            #+#    #+#             */
/*   Updated: 2022/05/02 13:04:10 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_arguments.h"

#include <limits.h>
#include <stdlib.h>
#include <stdio.h>

#include "stack.h"
#include "libft.h"

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
	if (ft_strlen(str) == 10 && sign == 0
		&& ft_strncmp(str, "2147483647", 11) > 0)
		return (2);
	*ret_number = 0;
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (1);
		*ret_number = *ret_number * 10 + (*str - '0');
		str++;
	}
	*ret_number = *ret_number + (unsigned int)INT_MAX + 1;
	if (sign)
		*ret_number = UINT_MAX - *ret_number + 1;
	// if (!sign)
	// 	*ret_number -= INT_MIN;
	// printf("%u\n", *ret_number);
	return (0);
}

static int	check_for_dupes(unsigned int *stack, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		if (stack[i] == (unsigned int)size - 1)
			return (0);
		i++;
	}
	return (1);
}

static int	handle_stack(char **numbers, unsigned int *stack, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (get_uint(numbers[i], stack + i))
			return (2);
		i++;
	}
	reduce(stack, size);
	if (check_for_dupes(stack, size))
		return (3);
	return (0);
}

int	parse_arguments(int *argc, char **argv, unsigned int *stack)
{
	int			size;
	int			error;
	char		**numbers;

	if (ft_strchr(argv[1], ' ') != NULL)
	{
		numbers = ft_strsplit(argv[1], " ");
		size = 0;
		while (numbers[size])
		{
			size++;
		}
		error = handle_stack(numbers, stack, size);
		size = 0;
		while (numbers[size])
			free(numbers[size++]);
		free(numbers);
		*argc = size + 1;
		return (error);
	}
	return (handle_stack(argv + 1, stack, *argc - 1));
}
