/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itan <itan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:38:05 by itan              #+#    #+#             */
/*   Updated: 2023/02/09 15:30:11 by itan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_list **list, unsigned char reversed)
{
	t_list	*tmp;
	t_list	*item;

	if (!*list)
		return ;
	if (reversed)
	{
		if ((*list)->next == NULL)
			return ;
		item = ft_lstlast(*list);
		tmp = *list;
		while (tmp->next != item)
			tmp = tmp->next;
		tmp->next = NULL;
		ft_lstadd_front(list, item);
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

void	ra(t_list **a)
{
	if (!*a)
		return ;
	rotate(a, 0);
	ft_printf("ra\n");
}

void	rb(t_list **b)
{
	if (!*b)
		return ;
	rotate(b, 0);
	ft_printf("rb\n");
}

void	rra(t_list **a)
{
	if (!*a)
		return ;
	rotate(a, 1);
	ft_printf("rra\n");
}

void	rrb(t_list **b)
{
	if (!*b)
		return ;
	rotate(b, 1);
	ft_printf("rra\n");
}
