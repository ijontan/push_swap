/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itan <itan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 21:30:16 by itan              #+#    #+#             */
/*   Updated: 2023/03/06 14:37:38 by itan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	partition_from_a(t_list **a, t_list **b, int len)
{
	int	average;
	int	number_pushed;
	int	number_left;
	int	no_r;

	no_r = len == ft_lstsize(*a);
	number_pushed = 0;
	number_left = 0;
	average = find_average_of_part(*a, len);
	while (len--)
	{
		if (*(int *)((*a)->content) < average)
		{
			pb(a, b);
			number_pushed++;
		}
		else
		{
			ra(a);
			number_left++;
		}
	}
	while (!no_r && number_left--)
		rra(a);
	return (number_pushed);
}

static int	partition_from_b(t_list **a, t_list **b, int len)
{
	int	average;
	int	number_pushed;
	int	number_left;

	number_pushed = 0;
	number_left = 0;
	average = find_average_of_part(*b, len);
	while (len--)
	{
		if (*(int *)((*b)->content) > average)
		{
			pa(a, b);
			number_pushed++;
		}
		else
		{
			rb(b);
			number_left++;
		}
	}
	while (number_left--)
		rrb(b);
	return (number_pushed);
}

static int	partition(t_list **a, t_list **b, int len, int at_a)
{
	int	total_number_pushed;

	if (at_a)
		total_number_pushed = partition_from_a(a, b, len);
	else
		total_number_pushed = partition_from_b(a, b, len);
	return (total_number_pushed);
}

static void	recurse(t_list **a, t_list **b, int len, int at_a)
{
	int	len_pushed;

	len_pushed = partition(a, b, len, at_a);
	if (at_a)
	{
		quick_sort(a, b, len - len_pushed, at_a);
		quick_sort(a, b, len_pushed, !at_a);
	}
	else
	{
		quick_sort(a, b, len_pushed, !at_a);
		quick_sort(a, b, len - len_pushed, at_a);
	}
}

void	quick_sort(t_list **a, t_list **b, int len, int at_a)
{
	if (len <= 0)
		return ;
	if (len == 3 && ft_lstsize(*a) == 3)
		return (sort_3(a, b, 0));
	if (len == 3 && at_a)
		return (q_sort_3(a, b, 0));
	if (len == 4)
		return (q_sort_4(a, b, at_a));
	if (len == 5 && at_a)
		return (q_sort_5(a, b));
	if (len == 2)
		return (q_sort_2(a, b, at_a));
	else if (len == 1)
	{
		if (!at_a)
			pa(a, b);
		return ;
	}
	else if (len < 17 && !at_a)
		return (insertion_sort(a, b, len, at_a));
	recurse(a, b, len, at_a);
}
