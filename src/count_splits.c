/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_splits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 01:14:31 by pfuchs            #+#    #+#             */
/*   Updated: 2022/04/27 01:16:32 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void	count_splits_2(int n, int *split2, int *split4)
{
	*split2 = 0;
	if (n <= 512)
		*split4 = 3;
	else
		*split4 = 5;
}

void	count_splits(int n, int *split2, int *split4)
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
	else
		count_splits_2(n, split2, split4);
}
