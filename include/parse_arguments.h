/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arguments.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 12:17:12 by pfuchs            #+#    #+#             */
/*   Updated: 2022/04/26 22:45:01 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_ARGUMENTS_H
# define PARSE_ARGUMENTS_H

int		parse_arguments(int *argc, char **argv, unsigned int *stack);

// only used by parse_arguments has the be here because of norm...
void	reduce(unsigned int *stack, int size);

#endif // PARSE_ARGUMENTS_H
