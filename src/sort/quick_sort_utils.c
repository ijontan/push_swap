/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itan <itan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:55:46 by itan              #+#    #+#             */
/*   Updated: 2023/02/13 19:45:24 by itan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_median(t_list *a)
{
	int	*lst;
	int	i;
	int	j;
	int	tmp;

	lst = (int *)malloc(sizeof(int) * 4);
	lst[0] = *(int *)(a->content);
	lst[1] = *(int *)(a->next->content);
	lst[2] = *(int *)(a->next->next->content);
	lst[3] = *(int *)(a->next->next->next->content);
	i = -1;
	while (++i < 4)
	{
		j = i;
		while (++j < 4)
		{
			if (lst[i] < lst[j])
			{
				tmp = lst[j];
				lst[j] = lst[i];
				lst[i] = tmp;
			}
		}
	}
	return ((lst[1] + lst[2]) / 2);
}

void	q_sort_4_a(t_list **a, t_list **b)
{
	int	val;
	int	len;
	int	len_rotated;

	len = 4;
	val = find_median(*a);
	len_rotated = 0;
	while (len--)
	{
		if (*(int *)((*a)->content) <= val)
			pb(a, b);
		else
		{
			ra(a);
			len_rotated++;
		}
	}
	while (len_rotated--)
		rra(a);
}

void	q_sort_4_b(t_list **a, t_list **b)
{
	int	val;
	int	len;
	int	len_rotated;

	len = 4;
	val = find_median(*b);
	len_rotated = 0;
	while (len--)
	{
		if (*(int *)((*b)->content) > val)
			pa(a, b);
		else
		{
			rb(b);
			len_rotated++;
		}
	}
	while (len_rotated--)
		rrb(b);
}

void	q_sort_4(t_list **a, t_list **b, int at_a)
{
	int	a_s;
	int	b_s;

	if (at_a)
		q_sort_4_a(a, b);
	else
		q_sort_4_b(a, b);
	a_s = *(int *)((*a)->content) > *(int *)((*a)->next->content);
	b_s = *(int *)((*b)->content) < *(int *)((*b)->next->content);
	if (a_s && b_s)
		ss(a, b);
	else if (a_s)
		sa(a);
	else if (b_s)
		sb(b);
	pa(a, b);
	pa(a, b);
}
