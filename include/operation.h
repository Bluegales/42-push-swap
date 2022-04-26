/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 18:16:31 by pfuchs            #+#    #+#             */
/*   Updated: 2022/04/26 22:38:13 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATION_H
# define OPERATION_H

typedef struct s_stack	t_stack;
typedef struct s_group	t_group;

typedef struct s_push_sort {
	t_stack		*src;
	t_stack		*dest;
	int			count;
	int			push_offset;
	int			sort_offset;
}	t_push_sort;

int		operation_push_sort(t_push_sort data);
void	operation_finish(t_group *d, t_stack *s1, t_stack *s2);
void	operation_step(t_group *d, t_stack *dst, t_stack *src);

#endif // OPERATION_H
