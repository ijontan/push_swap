/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itan <itan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 23:08:00 by itan              #+#    #+#             */
/*   Updated: 2023/03/06 14:30:58 by itan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_from_bot(t_list **a, t_list **b, t_insertion *data)
{
	data->biggest_num *= -1;
	rrb(b);
	data->len_top++;
	data->len_bot--;
	while (*((int *)((*b)->content)) != data->biggest_num)
	{
		rrb(b);
		data->len_top++;
		data->len_bot--;
	}
	if (*((int *)((*b)->content)) == data->biggest_num)
	{
		pa(a, b);
		data->len_top--;
	}
}

void	get_from_top(t_list **a, t_list **b, t_insertion *data)
{
	if ((*b)->next)
		if (*((int *)((*b)->next->content)) == data->biggest_num)
			sb(b);
	while (*((int *)((*b)->content)) != data->biggest_num)
	{
		rb(b);
		data->len_top--;
		data->len_bot++;
	}
	if (*((int *)((*b)->content)) == data->biggest_num)
	{
		pa(a, b);
		data->len_top--;
	}
}

static void	is_b(t_list **a, t_list **b, int len)
{
	int			i;
	t_insertion	data;

	i = 0;
	data.len_top = len;
	data.len_bot = 0;
	while (i++ < len)
	{
		data.biggest_num = get_biggest_val(*b, data.len_top, data.len_bot);
		if (data.biggest_num < 0)
			get_from_bot(a, b, &data);
		else
			get_from_top(a, b, &data);
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
