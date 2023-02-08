/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itan <itan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 21:30:16 by itan              #+#    #+#             */
/*   Updated: 2023/02/08 17:32:08 by itan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	partition(t_list *a, t_list *b, int bot_len)
{
	long	val;
	int		nbot_len;

	nbot_len = 0;
	val = (long)(a->content);
	while (bot_len > 0)
	{
		if ((long)(a->content) < val)
			pa(&a, &b);
		else
		{
			ra(&a);
			nbot_len++;
		}
		a = a->next;
		bot_len--;
	}
	return (nbot_len);
}

void	quick_sort(t_list *a, t_list *b, int top_len, int bot_len)
{
	int	nbot_len;

	if (bot_len == 2)
		return (sa(&a));
	nbot_len = partition(a, b, bot_len);
	quick_sort(a, b, bot_len - nbot_len, nbot_len);
	quick_sort(a, b, 0, top_len);
}
