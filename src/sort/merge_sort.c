/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itan <itan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 00:38:51 by itan              #+#    #+#             */
/*   Updated: 2023/02/07 17:52:45 by itan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	merge_sort_ps(t_list **a, t_list **b, int num)
{
	if (num == 2)
	{
		if ((*a)->content > (*a)->next->content)
			sa(a);
		return ;
	}
	if (num > 2)
	{
		merge_sort_ps(a, b, num / 2);
		merge_sort_ps(a, b, num / 2 + 1);
		if ((*a)->content > ft_lstlast(*a)->content)
			sa(a);
		else
		{
		}
	}
}
