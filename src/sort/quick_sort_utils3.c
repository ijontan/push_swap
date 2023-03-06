/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_utils3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itan <itan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 04:21:58 by itan              #+#    #+#             */
/*   Updated: 2023/03/06 14:44:54 by itan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_smallest(t_list *a)
{
	int	smallest;
	int	i;

	smallest = *(int *)a->content;
	i = 0;
	while (i < 5)
	{
		if (*(int *)a->content < smallest)
			smallest = *(int *)a->content;
		a = a->next;
		i++;
	}
	return (smallest);
}

static void	sort_5_rot(t_list **a, t_list **b, int *number_pushed, int smallest)
{
	int	number_rotated;

	number_rotated = 0;
	while (*number_pushed <= 2)
	{
		if ((*(int *)(*a)->content == (smallest + 1))
			|| (*(int *)(*a)->content == smallest))
		{
			pb(a, b);
			(*number_pushed)++;
			continue ;
		}
		if (*number_pushed == 2)
			break ;
		ra(a);
		(number_rotated)++;
	}
	while ((number_rotated)--)
		rra(a);
}

void	q_sort_5(t_list **a, t_list **b)
{
	int	number_pushed;
	int	smallest;

	number_pushed = 0;
	smallest = get_smallest(*a);
	sort_5_rot(a, b, &number_pushed, smallest);
	q_sort_3(a, b, *(int *)(*b)->content < *(int *)(*b)->next->content);
	while (number_pushed--)
		pa(a, b);
}

int	find_average_of_part(t_list *lst, int len)
{
	int	val;
	int	total;

	total = len;
	val = 0;
	while (len--)
	{
		val += *(int *)(lst->content);
		lst = lst->next;
	}
	return (val / total);
}

void	q_sort_2(t_list **a, t_list **b, int at_a)
{
	if (at_a)
		if (*(int *)((*a)->content) > *(int *)((*a)->next->content))
			sa(a);
	if (!at_a)
	{
		pa(a, b);
		pa(a, b);
		if (*(int *)((*a)->content) > *(int *)((*a)->next->content))
			sa(a);
	}
}
