/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itan <itan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 21:30:16 by itan              #+#    #+#             */
/*   Updated: 2023/02/08 16:57:41 by itan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quick_sort(t_list *a, t_list *b, int top_len, int bot_len)
{
	long	val;

	val = (long)(a->content);
	a = a->next;
	while (a)
	{
		if ((long)(a->content) < val)
			pa(&a, &b);
		a = a->next;
	}
}
