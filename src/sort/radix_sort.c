/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itan <itan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 20:24:52 by itan              #+#    #+#             */
/*   Updated: 2022/11/16 21:09:38 by itan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	power(int num, int power)
{
	int	dst;

	if (!num)
		return (0);
	if (!power)
		return (1);
	dst = num;
	while (--power > 0)
		dst *= num;
	return (dst);
}

void	sort_tob(t_list **a, t_list **b, int *count, int isobit)
{
	if (isobit)
		pa(a, b, count);
	else
	{
		pa(a, b, count);
		rb(b, count);
	}
}

void	sort_toa(t_list **a, t_list **b, int *count, int isobit)
{
	if (isobit)
		pb(a, b, count);
	else
	{
		pb(a, b, count);
		ra(a, count);
	}
}

void	radix_sort_ps(t_list **a, t_list **b, int *count, int size)
{
	int	isobit;
	int	i;
	int	j;

	j = -1;
	while (++j < size)
		sort_tob(a, b, count, *((int *)(*a)->content) >= 0);
	i = 7;
	while (i >= 0)
	{
		j = 0;
		while (j < size)
		{
			isobit = *((int *)(*a)->content) & power(2, i);
			isobit = isobit > i - 1;
			if (i % 2 == 0)
				sort_tob(a, b, count, isobit);
			else
				sort_toa(a, b, count, isobit);
			j++;
		}
		i--;
	}
}
