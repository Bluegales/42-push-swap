/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_groups_helper.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 15:16:15 by pfuchs            #+#    #+#             */
/*   Updated: 2022/04/27 01:17:08 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_GROUPS_HELPER_H
# define SORT_GROUPS_HELPER_H

typedef struct s_stack		t_stack;
typedef struct s_group_data	t_group_data;

typedef struct s_group_set_data
{
	short	id;
	short	real : 2;
	short	max_size;
}	t_group_set_data;

void	split_end_4(t_stack *dst, t_stack *src);
void	split_end_8(t_stack *dst, t_stack *src);
void	split_4(t_stack *dst, t_stack *src);
void	split_2(t_stack *dst, t_stack *src);
void	set_group(t_group_data *groups, t_group_set_data d, t_stack *stack);
int		init(t_stack *s1, t_stack *s2, int size);

#endif // SORT_GROUPS_HELPER_H
