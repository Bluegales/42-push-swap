/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 20:45:26 by pfuchs            #+#    #+#             */
/*   Updated: 2022/04/19 19:25:33 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef B7BCDA9F_92EC_4016_B140_A1FFE35692BA
#define B7BCDA9F_92EC_4016_B140_A1FFE35692BA

typedef struct s_group_data	t_group_data;
typedef struct s_stack		t_stack;

void	sort(t_group_data *groups, t_stack *s1, t_stack *s2);
void	sort_small(t_stack *s1, t_stack *s2);

#endif /* B7BCDA9F_92EC_4016_B140_A1FFE35692BA */
