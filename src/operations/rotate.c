/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itan <itan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:38:05 by itan              #+#    #+#             */
/*   Updated: 2022/11/16 21:13:17 by itan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_list **list, unsigned char reversed)
{
	t_list	*tmp;
	t_list	*item;

	if (!*list)
		return ;
	if (reversed)
	{
		item = ft_lstlast(*list);
		*list = (*list)->next;
		tmp = *list;
		ft_lstadd_front(list, item);
		while (tmp->next != item)
			tmp = tmp->next;
		tmp->next = NULL;
	}
	else
	{
		(void)item;
		tmp = *list;
		*list = (*list)->next;
		tmp->next = NULL;
		ft_lstadd_back(list, tmp);
	}
}

void	ra(t_list **a, int *count)
{
	if (!*a)
		return ;
	rotate(a, 0);
	(*count)++;
}

void	rb(t_list **b, int *count)
{
	if (!*b)
		return ;
	rotate(b, 0);
	(*count)++;
}

void	rra(t_list **a, int *count)
{
	if (!*a)
		return ;
	rotate(a, 1);
	(*count)++;
}

void	rrb(t_list **b, int *count)
{
	if (!*b)
		return ;
	rotate(b, 1);
	(*count)++;
}
