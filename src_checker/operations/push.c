/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itan <itan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 00:55:52 by itan              #+#    #+#             */
/*   Updated: 2023/03/06 03:31:50 by itan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_list **from, t_list **to)
{
	t_list	*tmp;

	if (!*from)
		return ;
	tmp = *from;
	*from = (*from)->next;
	tmp->next = NULL;
	ft_lstadd_front(to, tmp);
}

void	pb(t_list **a, t_list **b)
{
	if (!*a)
		return ;
	push(a, b);
}

void	pa(t_list **a, t_list **b)
{
	if (!*b)
		return ;
	push(b, a);
}
