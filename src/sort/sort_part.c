/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_part.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itan <itan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 06:00:13 by itan              #+#    #+#             */
/*   Updated: 2023/03/06 07:27:55 by itan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	select_push(t_list **a, t_list **b, int size, int part_size)
{
	int	i;
	int	push_count;
	int	current_size;

	current_size = ft_lstsize(*a);
	push_count = 0;
	i = 0;
	while (i++ < current_size)
	{
		if (!*a)
			return ;
		if (push_count > part_size)
			break ;
		if (*((int *)(*a)->content) < size && *((int *)(*a)->content) > (size
				- part_size))
		{
			pb(a, b);
			push_count++;
			if (i % 2 && *((int *)(*a)->content) > size)
			{
				rr(a, b);
			}
			else if (i % 2)
				rb(b);
		}
		else
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
	int	i;

	size = ft_lstsize(*a);
	i = 0;
	while (i++ < 5)
		select_push(a, b, size / 5 * i, size / 5);
	push_rest(a, b);
	insertion_sort(a, b, ft_lstsize(*b), 0);
}
