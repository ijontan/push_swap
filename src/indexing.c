/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itan <itan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 21:34:10 by itan              #+#    #+#             */
/*   Updated: 2023/03/05 23:52:57 by itan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*insertion_sort_index(int *a, int len)
{
	int	i;
	int	j;
	int	temp;
	int	*dst;

	dst = ft_calloc(len, sizeof(int));
	i = -1;
	while (++i < len)
		dst[i] = a[i];
	i = 1;
	while (i < len)
	{
		j = i;
		while (j > 0 && dst[j - 1] > dst[j])
		{
			temp = dst[j];
			dst[j] = dst[j - 1];
			dst[j - 1] = temp;
			j--;
		}
		i++;
	}
	return (dst);
}

int	get_index(int *a, int len, int n)
{
	int	i;

	i = -1;
	while (++i < len)
		if (a[i] == n)
			return (i);
	return (-1);
}

int	*indexing(int *a, int len)
{
	int	i;
	int	*dst;
	int	*sorted;

	dst = ft_calloc(len, sizeof(int));
	sorted = insertion_sort_index(a, len);
	i = 0;
	while (i < len)
	{
		dst[get_index(a, len, sorted[i])] = i + 1;
		i++;
	}
	free(a);
	free(sorted);
	return (dst);
}
