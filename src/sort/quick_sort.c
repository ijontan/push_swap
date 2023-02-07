/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itan <itan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 21:30:16 by itan              #+#    #+#             */
/*   Updated: 2023/02/07 16:17:15 by itan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quick_sort(t_list *a, t_list *b, int *count)
{
	long	val;

	val = (long)(a->content);
	a = a->next;
	while ((long)(a->content))
	{
		if ((long)(a->content) < val)
			pa(&a, &b, count);
		a = a->next;
	}
}
