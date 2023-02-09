/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itan <itan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 16:57:56 by itan              #+#    #+#             */
/*   Updated: 2023/02/09 18:02:57 by itan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_5(t_list **a, t_list **b)
{
	int	i;

	pa(a, b);
	pa(a, b);
	sort_3(a);
	i = 0;
	if (*(int *)((*b)->content) > *(int *)((*b)->next->content))
		sb(b);
	while (*b)
	{
		if (*(int *)((*b)->content) < *(int *)((*a)->content))
			if (*(int *)((*b)->content) > *(int *)(ft_lstlast(*a)->content))
				pb(a, b);
		ra(a);
		i++;
	}
	while (*(int *)((*a)->content) > *(int *)(ft_lstlast(*a)->content))
		ra(a);
}
