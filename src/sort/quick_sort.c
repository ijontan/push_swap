/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itan <itan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 21:30:16 by itan              #+#    #+#             */
/*   Updated: 2022/11/10 21:54:31 by itan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static size_t	partition(int *lst, size_t lo, size_t hi)
{
	size_t	i;
	size_t	j;
	int		pivot;

	pivot = lst[(lo + hi) / 2];
	i = lo;
	j = hi;
	while (1)
	{
		while (lst[i] < pivot)
			i++;
		while (lst[j] > pivot)
			j--;
		if (i >= j)
			return (j);
		swap(&lst[i], &lst[j]);
	}
}

void	quick_sort(int *lst, size_t lo, size_t hi)
{
	size_t	p;

	if (lo >= 0 && hi >= 0 && hi > lo)
	{
		p = partition(lst, lo, hi);
		quick_sort(lst, lo, p);
		quick_sort(lst, p, hi);
	}
}
