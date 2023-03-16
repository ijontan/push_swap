/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itan <itan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 16:43:27 by itan              #+#    #+#             */
/*   Updated: 2023/03/16 17:07:03 by itan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sorted(t_list **a, t_list **b)
{
	t_list	*tmp;

	if (*b)
		return (0);
	tmp = *a;
	while (tmp && tmp->next)
	{
		if (*(int *)(tmp->content) > *(int *)(tmp->next->content))
			return (0);
		if (*(int *)(tmp->content) == *(int *)(tmp->next->content))
			return (-1);
		tmp = tmp->next;
	}
	return (1);
}
