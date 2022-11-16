/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itan <itan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:22:09 by itan              #+#    #+#             */
/*   Updated: 2022/11/16 21:12:41 by itan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_list **lst)
{
	t_list	*tmp;

	if (!*lst && !(*lst)->next)
		return ;
	tmp = (*lst)->next;
	(*lst)->next = tmp->next;
	tmp->next = *lst;
	*lst = tmp;
}

void	sa(t_list **a, int *count)
{
	if (!*a && !(*a)->next)
		return ;
	swap(a);
	(*count)++;
}

void	sb(t_list **b, int *count)
{
	if (!*b && !(*b)->next)
		return ;
	swap(b);
	(*count)++;
}
