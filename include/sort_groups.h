/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_groups.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 18:26:26 by pfuchs            #+#    #+#             */
/*   Updated: 2022/04/26 23:31:49 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_GROUPS_H
# define SORT_GROUPS_H

typedef struct s_stack	t_stack;

typedef struct s_group {
	short		*number_group;
	short		*group_sizes;
	short		group_count;
}	t_group;

typedef struct s_group_data {
	short	number_count;
	short	last_group;
	t_group	real_groups[6];
	t_group	push_groups[6];
}	t_group_data;

int		get_sort_groups(t_group_data *groups);

#endif // SORT_GROUPS_H
