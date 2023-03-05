/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itan <itan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 23:08:00 by itan              #+#    #+#             */
/*   Updated: 2023/03/06 03:15:49 by itan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_biggest_num(t_list *list, int len_top, int len_bot)
{
	int	num;
	int	i;
	int	mid_len;
	int	sign;

	sign = 1;
	mid_len = ft_lstsize(list) - len_top - len_bot;
	num = *((int *)(list->content));
	i = 0;
	if (mid_len == 0)
	{
		len_top = ft_lstsize(list) / 2 + ft_lstsize(list) % 2;
		len_bot = ft_lstsize(list) / 2;
	}
	while (i++ < len_top)
	{
		if (num < *((int *)(list->content)))
			num = *((int *)(list->content));
		list = list->next;
	}
	i = 0;
	while (i++ < mid_len)
		list = list->next;
	i = 0;
	while (i++ < len_bot)
	{
		if (num < *((int *)(list->content)))
		{
			num = *((int *)(list->content));
			sign = -1;
		}
		list = list->next;
	}
	return (num * sign);
}

static void	is_b(t_list **a, t_list **b, int len)
{
	int	len_btop;
	int	len_bbot;
	int	i;
	int	biggest_num;

	i = 0;
	len_btop = len;
	len_bbot = 0;
	while (i++ < len)
	{
		biggest_num = get_biggest_num(*b, len_btop, len_bbot);
		if (biggest_num < 0)
		{
			biggest_num *= -1;
			rrb(b);
			len_btop++;
			len_bbot--;
			while (*((int *)((*b)->content)) != biggest_num)
			{
				rrb(b);
				len_btop++;
				len_bbot--;
			}
			if (*((int *)((*b)->content)) == biggest_num)
			{
				pa(a, b);
				len_btop--;
			}
		}
		else
		{
			if ((*b)->next)
				if (*((int *)((*b)->next->content)) == biggest_num)
					sb(b);
			while (*((int *)((*b)->content)) != biggest_num)
			{
				rb(b);
				len_btop--;
				len_bbot++;
			}
			if (*((int *)((*b)->content)) == biggest_num)
			{
				pa(a, b);
				len_btop--;
			}
		}
	}
}

void	insertion_sort(t_list **a, t_list **b, int len, int at_a)
{
	int	i;

	if (at_a)
	{
		i = 0;
		while (i++ < len)
			pb(a, b);
		is_b(a, b, len);
	}
	else
		is_b(a, b, len);
}
