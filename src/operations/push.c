/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itan <itan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 00:55:52 by itan              #+#    #+#             */
/*   Updated: 2022/11/13 00:59:57 by itan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_list **from, t_list **to, unsigned char tob)
{
	t_list	*tmp;

	ft_lstadd_front(to, ft_lstnew((*from)->content));
	tmp = *from;
	*from = (*from)->next;
	(void)tob;
}
