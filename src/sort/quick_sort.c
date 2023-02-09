/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itan <itan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 21:30:16 by itan              #+#    #+#             */
/*   Updated: 2023/02/09 16:23:24 by itan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	partition(t_list **a, t_list **b, int bot_len)
{
	long	val;
	int		nbot_len;

	nbot_len = 0;
	if (*a != NULL)
		val = *(int *)((*a)->content);
	else
		return (0);
	while (bot_len > 0)
	{
		if (*(int *)((*a)->content) <= val)
			pa(a, b);
		else
		{
			ra(a);
			nbot_len++;
		}
		bot_len--;
	}
	return (nbot_len);
}

void	quick_sort(t_list **a, t_list **b, int len_a, int len_b)
{
	int	nlen_a;
	int	nlen_b;

	if (len_a == 2)
		return (sa(a));
	if (len_a <= 1)
		return ;
	nlen_a = partition(a, b, len_a);
	nlen_b = len_a + len_b - nlen_a;
	quick_sort(a, b, nlen_a, 0);
	len_b++;
	while (len_b-- > 0)
	{
		pb(a, b);
		len_a++;
	}
	nlen_a++;
	while (nlen_a-- > 0)
		rra(a);
	quick_sort(a, b, 0, nlen_b);
}
