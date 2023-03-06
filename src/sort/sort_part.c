/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_part.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itan <itan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 06:00:13 by itan              #+#    #+#             */
/*   Updated: 2023/03/06 13:18:37 by itan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	select_push(t_list **a, t_list **b, int part_size)
{
	int	i;

	i = 0;
	while (*a)
	{
		while (*a && *(int *)(*a)->content < part_size + i)
		{
			pb(a, b);
			i++;
			if (*b && *(int *)(*b)->content < i + part_size / 2)
			{
				if (*a && *(int *)(*a)->content > part_size + i)
					rr(a, b);
				else
					rb(b);
			}
		}
		ra(a);
	}
}

static void	push_rest(t_list **a, t_list **b)
{
	int	i;

	i = 0;
	while (*a)
	{
		pb(a, b);
		if (i % 2)
			rb(b);
		i++;
	}
}

void	sort_part(t_list **a, t_list **b)
{
	int	size;

	size = ft_lstsize(*a);
	select_push(a, b, 15);
	push_rest(a, b);
	insertion_sort(a, b, ft_lstsize(*b), 0);
}
