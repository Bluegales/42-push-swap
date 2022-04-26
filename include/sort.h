/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 20:45:26 by pfuchs            #+#    #+#             */
/*   Updated: 2022/04/26 22:38:44 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
# define SORT_H

typedef struct s_group_data	t_group_data;
typedef struct s_stack		t_stack;

void	sort(t_group_data *groups, t_stack *s1, t_stack *s2);
void	sort_small(t_stack *s1, t_stack *s2);

#endif // SORT_H
