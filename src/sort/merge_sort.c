/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itan <itan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 00:38:51 by itan              #+#    #+#             */
/*   Updated: 2022/11/13 00:53:17 by itan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	merge_sort_push_swap(t_list **a, t_list **b, int size)
{
	t_list	*tmp;

	if (size / 2 != 1)
		merge_sort_push_swap(a, b, size / 2);
	while (*a)
	{
		ft_lstadd_front(b, ft_lstnew((*a)->content));
		tmp = *a;
		*a = (*a)->next;
		free(tmp);
		if (*(int *)((*a)->content) > *(int *)((*b)->content))
		{
			ft_lstadd_front(b, ft_lstnew((*a)->content));
			tmp = *a;
			*a = (*a)->next;
			free(tmp);
		}
		else
		{
		}
	}
}
