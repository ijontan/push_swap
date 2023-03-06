/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itan <itan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 16:57:56 by itan              #+#    #+#             */
/*   Updated: 2023/03/06 14:25:49 by itan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_smallest(t_list *a, int num_pushed)
{
	int	i;
	int	val;
	int	sign;

	val = 6;
	sign = 1;
	i = 0;
	while (i++ < 3 - num_pushed)
	{
		if (*(int *)a->content < val)
			val = *(int *)a->content;
		a = a->next;
	}
	while (a)
	{
		if (*(int *)a->content < val)
		{
			val = *(int *)a->content;
			sign = -1;
		}
		a = a->next;
	}
	return (val * sign);
}

void	sort_5(t_list **a, t_list **b)
{
	int	val;
	int	num_pushed;

	num_pushed = 0;
	while (num_pushed < 2)
	{
		val = get_smallest(*a, num_pushed);
		if (val > 0 && *(int *)(*a)->content != val)
			ra(a);
		else if (val < 0 && *(int *)(*a)->content != val)
			rra(a);
		if (*(int *)(*a)->content == val)
		{
			pb(a, b);
			num_pushed++;
		}
	}
	sort_3(a, b, *(int *)((*b)->content) < *(int *)((*b)->next->content));
	pa(a, b);
	pa(a, b);
}
