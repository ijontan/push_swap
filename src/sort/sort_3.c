/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itan <itan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 16:35:07 by itan              #+#    #+#             */
/*   Updated: 2023/02/09 17:01:02 by itan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_list **a)
{
	int	a1;
	int	a2;
	int	a3;

	a1 = *(int *)((*a)->content);
	a2 = *(int *)((*a)->next->content);
	a3 = *(int *)((*a)->next->next->content);
	if (a1 > a2 && a1 < a3)
		return (sa(a));
	if (a1 < a2 && a1 > a3)
		return (rra(a));
	if (a1 > a2 && a1 > a3)
	{
		if (a2 > a3)
		{
			sa(a);
			return (rra(a));
		}
		else
			return (ra(a));
	}
	if (!(a1 < a2 && a1 < a3 && a2 > a3))
		return ;
	sa(a);
	ra(a);
}
