/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_utils2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itan <itan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 03:45:33 by itan              #+#    #+#             */
/*   Updated: 2023/03/06 05:53:33 by itan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	f231(t_list **a, t_list **b, int s_sb)
{
	pb(a, b);
	sa(a);
	pa(a, b);
	if (s_sb)
		ss(a, b);
	else
		sa(a);
}

static void	f321(t_list **a, t_list **b, int s_sb)
{
	if (s_sb)
		ss(a, b);
	else
		sa(a);
	pb(a, b);
	sa(a);
	pa(a, b);
	sa(a);
}

static void	f312(t_list **a, t_list **b, int s_sb)
{
	if (s_sb)
		ss(a, b);
	else
		sa(a);
	pb(a, b);
	sa(a);
	pa(a, b);
}

static void	f132(t_list **a, t_list **b, int s_sb)
{
	if (s_sb)
		sb(b);
	pb(a, b);
	sa(a);
	pa(a, b);
}

void	q_sort_3(t_list **a, t_list **b, int s_sb)
{
	int	a1;
	int	a2;
	int	a3;

	a1 = *(int *)((*a)->content);
	a2 = *(int *)((*a)->next->content);
	a3 = *(int *)((*a)->next->next->content);
	if (a1 > a2 && a1 < a3)
	{
		if (s_sb)
			return (ss(a, b));
		else
			return (sa(a));
	}
	if (a1 < a2 && a1 > a3)
		return (f231(a, b, s_sb));
	if (a1 > a2 && a1 > a3 && a2 > a3)
		return (f321(a, b, s_sb));
	if (a1 > a2 && a1 > a3 && a2 < a3)
		return (f312(a, b, s_sb));
	if (a1 < a2 && a1 < a3 && a2 > a3)
		return (f132(a, b, s_sb));
	if (s_sb)
		sb(b);
}
