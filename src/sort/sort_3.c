/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itan <itan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 16:35:07 by itan              #+#    #+#             */
/*   Updated: 2023/03/06 13:35:19 by itan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	f321(t_list **a, t_list **b, int s_sb)
{
	if (s_sb)
		ss(a, b);
	else
		sa(a);
	rra(a);
}

static void	f132(t_list **a, t_list **b, int s_sb)
{
	if (s_sb)
		ss(a, b);
	else
		sa(a);
	ra(a);
}

void	sort_3(t_list **a, t_list **b, int s_sb)
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
		rra(a);
	if (a1 > a2 && a1 > a3 && a2 > a3)
		return (f321(a, b, s_sb));
	if (a1 > a2 && a1 > a3 && a2 < a3)
		ra(a);
	if (a1 < a2 && a1 < a3 && a2 > a3)
		return (f132(a, b, s_sb));
	if (s_sb)
		sb(b);
}
