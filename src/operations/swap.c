/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itan <itan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:22:09 by itan              #+#    #+#             */
/*   Updated: 2023/03/06 03:32:39 by itan             ###   ########.fr       */
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

void	sa(t_list **a)
{
	if (!*a && !(*a)->next)
		return ;
	swap(a);
	ft_printf("sa\n");
}

void	sb(t_list **b)
{
	if (!*b && !(*b)->next)
		return ;
	swap(b);
	ft_printf("sb\n");
}

void	ss(t_list **a, t_list **b)
{
	if (!*a && !(*a)->next)
		return ;
	if (!*b && !(*b)->next)
		return ;
	swap(a);
	swap(b);
	ft_printf("ss\n");
}
