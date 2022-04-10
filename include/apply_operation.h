/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_operation.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 14:47:14 by pfuchs            #+#    #+#             */
/*   Updated: 2022/04/10 17:43:21 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef APPLY_OPERATION_H
# define APPLY_OPERATION_H

typedef struct s_stack	t_stack;

typedef int (*f_operation)(t_stack);

const static f_operation	operations[] = {
	swap_a;
};

enum e_operation{ sa=0, sb=1, ss=2,	pa=3, pb=4, ra=5, rb=6, rr=7, rra=8, rb=9,
	rrr=10
};

#endif // APPLY_OPERATION_H
