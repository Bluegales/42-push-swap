/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_groups.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 18:13:42 by pfuchs            #+#    #+#             */
/*   Updated: 2022/04/19 18:17:28 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_groups.h"
#include "sort_groups_helper.h"

#include <stdlib.h>
#include <stdio.h>

#include "stack.h"
#include "libft.h"

static void	reset_stacks(t_stack *s1, t_stack *s2, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		s1->array[i] = (unsigned int)i;
		i++;
	}
	s1->data = s1->array;
	s1->data_size = n;
	s2->data_size = 0;
}

static int	init(t_stack *s1, t_stack *s2, int size)
{
	int	error;

	error = 0;
	error += stack_init(s1, size * 2, NULL);
	error += stack_init(s2, size * 2, NULL);
	if (error)
	{
		stack_free(s1);
		stack_free(s2);
		return (1);
	}
	return (0);
}

static void	count_splits(int n, int *split2, int *split4)
{
	*split2 = 0;
	*split4 = 0;
	if (n <= 16)
		*split2 = 1;
	else if (n <= 32)
		*split4 = 1;
	else if (n <= 64)
		*split2 = 3;
	else if (n <= 128)
	{
		*split4 = 1;
		*split2 = 2;
	}
	else if (n <= 256)
	{
		*split4 = 2;
		*split2 = 1;
	}
	else if (n <= 256)
	{
		*split4 = 2;
		*split2 = 1;
	}
	else if (n <= 512)
		*split4 = 3;
}

static void	create_first_group(t_group_data *groups, t_stack *s1, t_stack *s2)
{
	reset_stacks(s1, s2, groups->number_count);
	split_end_4(s2, s1);
	set_group(groups, (t_group_set_data){0, 0, 4}, s2);
	if (groups->number_count > 8)
	{
		reset_stacks(s1, s2, groups->number_count);
		split_end_8(s2, s1);
		set_group(groups, (t_group_set_data){0, 1, 8}, s2);
	}
	else
	{
		set_group(groups, (t_group_set_data){0, 1, 4}, s2);
	}
}

static void create_groups(t_group_data *groups, t_stack *s1, t_stack *s2)
{
	int	last_group;
	int	split2;
	int	split4;

	create_first_group(groups, s1, s2);
	last_group = 0;
	count_splits(groups->number_count, &split2, &split4);
	//printf("split4: %d, split2: %d\n",split4, split2);
	while (split4--)
	{
		reset_stacks(s1, s2, groups->real_groups[last_group].group_count);
		split_2(s2, s1);
		set_group(groups, (t_group_set_data){last_group + 1, 0, 2}, s2);
		reset_stacks(s1, s2, groups->real_groups[last_group].group_count);
		split_4(s2, s1);
		set_group(groups, (t_group_set_data){last_group + 1, 1, 4}, s2);
		last_group++;
	}
	while (split2--)
	{
		reset_stacks(s1, s2, groups->real_groups[last_group].group_count);
		split_2(s2, s1);
		set_group(groups, (t_group_set_data){last_group + 1, 0, 2}, s2);
		set_group(groups, (t_group_set_data){last_group + 1, 1, 2}, s2);
		last_group++;
	}
	groups->last_group = last_group;
}

int	get_sort_groups(t_group_data *groups)
{
	t_stack	s1;
	t_stack	s2;

	if (init(&s1, &s2, groups->number_count))
		return (1);
	//printf("number is %d\n", groups->number_count);
	create_groups(groups, &s1, &s2);
	stack_free(&s1);
	stack_free(&s2);
	return (0);
}
