/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itan <itan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:55:46 by itan              #+#    #+#             */
/*   Updated: 2023/03/06 03:54:21 by itan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	find_median(t_list *a)
{
	int	*lst;
	int	i;
	int	j;
	int	tmp;

	lst = ft_calloc(4, sizeof(int));
	lst[0] = *(int *)(a->content);
	lst[1] = *(int *)(a->next->content);
	lst[2] = *(int *)(a->next->next->content);
	lst[3] = *(int *)(a->next->next->next->content);
	i = -1;
	while (++i < 4)
	{
		j = i - 1;
		while (++j < 4)
			if (lst[i] < lst[j])
				swap(&lst[i], &lst[j]);
	}
	tmp = (lst[0] + lst[1] + lst[2] + lst[3]) / 4;
	free(lst);
	return (tmp);
}

static void	q_sort_4_a(t_list **a, t_list **b, int len)
{
	int	val;
	int	len_rotated;
	int	len_pushed;

	len_pushed = 0;
	val = find_median(*a);
	len_rotated = 0;
	while (len--)
	{
		if (len_pushed == 2)
			break ;
		if (*(int *)((*a)->content) <= val)
		{
			pb(a, b);
			len_pushed++;
		}
		else
		{
			ra(a);
			len_rotated++;
		}
	}
	while (len_rotated--)
		rra(a);
}

void	q_sort_4_b(t_list **a, t_list **b, int len)
{
	int	val;
	int	len_rotated;
	int	len_pushed;

	len_pushed = 0;
	val = find_median(*b);
	len_rotated = 0;
	while (len--)
	{
		if (len_pushed == 2)
			break ;
		if (*(int *)((*b)->content) > val)
		{
			pa(a, b);
			len_pushed++;
		}
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
		q_sort_4_a(a, b, 4);
	else
		q_sort_4_b(a, b, 4);
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
