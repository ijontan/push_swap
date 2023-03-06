/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itan <itan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 20:24:52 by itan              #+#    #+#             */
/*   Updated: 2023/03/06 14:29:42 by itan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_biggest_num(t_list *list)
{
	int	num;

	num = *((int *)(list->content));
	while (list)
	{
		if (num < *((int *)(list->content)))
			num = *((int *)(list->content));
		list = list->next;
	}
	return (num);
}

void	sort_tob(t_list **a, t_list **b, int size, int power)
{
	int	isobit;
	int	j;

	j = 0;
	while (j < size)
	{
		isobit = (*((int *)(*a)->content)) & power;
		isobit = isobit == power;
		if (isobit)
			pb(a, b);
		else
			ra(a);
		j++;
	}
}

void	sort_merge(t_list **a, t_list **b)
{
	while (*b)
	{
		rrb(b);
		pa(a, b);
		ra(a);
	}
}

void	radix_sort_ps(t_list **a, t_list **b, int size)
{
	int	max_n_radix;
	int	i;

	i = 0;
	max_n_radix = ft_log2(get_biggest_num(*a));
	while (i <= max_n_radix)
	{
		sort_tob(a, b, size, power(2, i));
		sort_merge(a, b);
		i++;
	}
}
