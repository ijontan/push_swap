/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itan <itan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 20:24:52 by itan              #+#    #+#             */
/*   Updated: 2022/11/23 21:04:26 by itan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_biggest_num(t_list *list)
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

int	sort_tob(t_list **a, t_list **b, int size, int power)
{
	int	count;
	int	isobit;
	int	j;

	j = 0;
	while (j < size)
	{
		isobit = (*((int *)(*a)->content)) & power;
		isobit = isobit == power;
		if (isobit)
			pa(a, b, &count);
		else
			ra(a, &count);
		j++;
	}
	return (count);
}

int	sort_merge(t_list **a, t_list **b)
{
	int	count;

	int len = lst
		while (*b)
	{
		rrb(b, &count);
		pb(a, b, &count);
		ra(a, &count);
	}
	return (count);
}

void	radix_sort_ps(t_list **a, t_list **b, int *count, int size)
{
	int	max_n_radix;
	int	i;

	i = 0;
	max_n_radix = ft_log2(get_biggest_num(*a));
	(void)max_n_radix;
	while (i <= 32)
	{
		*count += sort_tob(a, b, size, power(2, i));
		*count += sort_merge(a, b);
		i++;
	}
}
