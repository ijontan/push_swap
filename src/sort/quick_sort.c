/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itan <itan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 21:30:16 by itan              #+#    #+#             */
/*   Updated: 2022/11/12 22:59:15 by itan             ###   ########.fr       */
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

static ssize_t	partition(int *lst, ssize_t lo, ssize_t hi)
{
	ssize_t	i;
	ssize_t	j;
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

void	quick_sort(int *lst, ssize_t lo, ssize_t hi)
{
	ssize_t	p;

	if (hi > lo)
	{
		p = partition(lst, lo, hi);
		quick_sort(lst, lo, p);
		quick_sort(lst, p + 1, hi);
	}
}
